#pragma once
#include<iostream>
#include<stdlib.h>

#include"String.h"

using namespace std;

enum class TYPE
{
	INT, DOUBLE, STR
};

class var
{
	TYPE t;
	void* value;

public:
	var();
	var(int v);
	var(double v);
	var(const char* v);
	var(String v);
	var(const var& obj);
	~var();

	operator int() const;
	operator double() const;
	operator String() const; //char*

	var& operator=(const var& obj);

	var operator+(const var& obj) const;
	var operator-(const var& obj) const;
	var operator*(const var& obj) const;
	var operator/(const var& obj) const;

	var& operator+=(const var& obj);
	var& operator-=(const var& obj);
	var& operator*=(const var& obj);
	var& operator/=(const var& obj);

	bool operator<(const var& obj) const;
	bool operator>(const var& obj) const;

	bool operator==(const var& obj) const;
	bool operator!=(const var& obj) const;

	bool operator<=(const var& obj) const;
	bool operator>=(const var& obj) const;

	friend ostream& operator<<(ostream& out, const var& obj);
	void Show() const;
};

var::var() : var(0) {}
var::var(int v)
{
	t = TYPE::INT;
	value = new int(v);
}
var::var(double v)
{
	t = TYPE::DOUBLE;
	value = new double(v);
}
var::var(const char* v) : var(String(v)) {}
var::var(String v)
{
	t = TYPE::STR;
	value = new String(v);
}

var::var(const var& obj) : t(obj.t), value(nullptr)
{
	switch (t)
	{
	case TYPE::INT:    value = new int(*(const int*)obj.value); break;
	case TYPE::DOUBLE: value = new double(*(const double*)obj.value); break;
	case TYPE::STR:    value = new String(*(const String*)obj.value);
	}
}

var::~var()
{
	switch (t)
	{
	case TYPE::INT:    delete ((int*)value); break;
	case TYPE::DOUBLE: delete ((double*)value); break;
	case TYPE::STR:    delete ((String*)value);
	}
}

var::operator int() const // https://stackoverflow.com/questions/3814865/what-is-an-operator-int-function
{
	switch (t)
	{
	case TYPE::INT:    return *(int*)(value);
	case TYPE::DOUBLE: return int(*(double*)value);
	case TYPE::STR:    return atoi((*((String*)value)).getStr());
	}
}
var::operator double() const
{
	switch (t)
	{
	case TYPE::INT:    return double(*(int*)(value));
	case TYPE::DOUBLE: return *(double*)value;
	case TYPE::STR:    return atof((*((String*)value)).getStr());
	}
}
var::operator String() const
{
	char buffer[64];
	switch (t)
	{
	case TYPE::INT:
		_itoa(*(int*)value, buffer, 10);
		return String(buffer);
	case TYPE::DOUBLE: // https://stackoverflow.com/questions/7228438/convert-double-float-to-string
		snprintf(buffer, sizeof(buffer), "%g", *(double*)value); // https://en.cppreference.com/cpp/io/c/fprintf
		return String(buffer);
	case TYPE::STR: return *(String*)value;
	}
}

var& var::operator=(const var& obj)
{
	if (this == &obj)
	{
		return *this;
	}

	switch (t)
	{
	case TYPE::INT:    delete ((int*)value); break;
	case TYPE::DOUBLE: delete ((double*)value); break;
	case TYPE::STR:    delete ((String*)value);
	}

	t = obj.t;
	switch (t)
	{
	case TYPE::INT:    value = new int(*( const int*)obj.value); break;
	case TYPE::DOUBLE: value = new double(*(const double*)obj.value); break;
	case TYPE::STR:    value = new String(*(const String*)obj.value);
	}

	return *this;
}

var var::operator+(const var& obj) const
{
	switch (t)
	{
	case TYPE::INT:    return var(int(*this) + int(obj));
	case TYPE::DOUBLE: return var(double(*this) + double(obj));
	case TYPE::STR:    return var(String(*this) + String(obj));
	}
}
var var::operator-(const var& obj) const
{
	switch (t)
	{
	case TYPE::INT:    return var(int(*this) - int(obj));
	case TYPE::DOUBLE: return var(double(*this) - double(obj));
	case TYPE::STR:    return var(String(*this) - String(obj));
	}
}
var var::operator*(const var& obj) const
{
	switch (t)
	{
	case TYPE::INT: return var(int(*this) * int(obj));
	case TYPE::DOUBLE: return var(double(*this) * double(obj));
	case TYPE::STR:
	{
		String a = String(*this), b = String(obj);
		int lenA = a.getLen(), lenB = b.getLen(), size = 0;
		char* c = new char[lenA + 1];
		for (int i = 0; i < lenA; i++)
		{
			for (int j = 0; j < lenB; j++)
			{
				if (a[i] == b[j])
				{
					c[size++] = a[i];
					break;
				}
			}
		}
		c[size] = '\0';
		String result(c);
		delete[] c;
		return result;
	}
	}
}
var var::operator/(const var& obj) const
{
	switch (t)
	{
	case TYPE::INT:
	{
		int a = int(*this), b = int(obj);
		return (b != 0) ? var(a / b) : var(a);
	}
	case TYPE::DOUBLE:
	{
		double a = double(*this), b = double(obj);
		return (b != 0) ? var(a / b) : var(a);
	}
	case TYPE::STR:
	{
		String a = String(*this), b = String(obj);
		String temp = *(String*)((var)a * (var)b).value;
		int lenA = a.getLen(), lenT = temp.getLen(), size = 0;
		char* c = new char[lenA - lenT + 2];
		for (int i = 0; i < lenA; i++)
		{
			bool incl = true;
			for (int j = 0; j < lenT; j++)
			{
				if (a[i] == temp[j])
				{
					incl = false;
					break;
				}
			}
			if (incl)
			{
				c[size++] = a[i];
			}
		}
		c[size] = '\0';
		String result(c);
		delete[] c;
		return result;
	}
	}
}

var& var::operator+=(const var& obj)
{
	*this = *this + obj;
	return *this;
}
var& var::operator-=(const var& obj)
{
	*this = *this - obj;
	return *this;
}
var& var::operator*= (const var & obj)
{
	*this = *this * obj;
	return *this;
}
var& var::operator/=(const var& obj)
{
	*this = *this / obj;
	return *this;
}

bool var::operator==(const var& obj) const
{
	switch (t)
	{
	case TYPE::INT:    return int(*this) == int(obj);
	case TYPE::DOUBLE: return double(*this) == double(obj);
	case TYPE::STR:    return String(*this) == String(obj);
	}
}
bool var::operator!=(const var& obj) const
{
	return !(*this == obj);
}

bool var::operator<(const var& obj) const
{
	switch (t)
	{
	case TYPE::INT:    return int(*this) < int(obj);
	case TYPE::DOUBLE: return double(*this) < double(obj);
	case TYPE::STR:    return String(*this) < String(obj);
	}
}
bool var::operator>(const var& obj) const
{
	return !(*this < obj || *this == obj);
}

bool var::operator<=(const var& obj) const
{
	return (*this < obj || *this == obj);
}
bool var::operator>=(const var& obj) const
{
	return (*this > obj || *this == obj);
}

ostream& operator<<(ostream& out, const var& obj)
{
	switch (obj.t)
	{
	case TYPE::INT: out << *((int*)obj.value); break;
	case TYPE::DOUBLE: out << *((double*)obj.value); break;
	case TYPE::STR: out << ((String*)obj.value)->getStr();
	}
	return out;
}

void var::Show() const
{
	if (t == TYPE::STR)
	{
		(*((String*)value)).print();
	}
	else
	{
		cout << ((t == TYPE::INT) ? *((int*)value) : *((double*)value)) << endl;
	}
}
