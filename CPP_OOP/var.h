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

	var& operator=(const var& obj);
	var operator+(const var& obj) const;

	bool operator==(const var& v) const;

	var operator*(const var& obj) const;
	var operator/(const var& obj) const;

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
	case TYPE::INT:
		value = new int(*(const int*)obj.value);
		break;

	case TYPE::DOUBLE:
		value = new double(*(const double*)obj.value);
		break;

	case TYPE::STR:
		value = new String(*(const String*)obj.value);
		break;
	}
}

var::~var()
{
	switch (t)
	{
	case TYPE::INT:    delete ((int*)value); break;
	case TYPE::DOUBLE: delete ((double*)value); break;
	case TYPE::STR:    delete ((String*)value); break;
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
	case TYPE::STR:    delete ((String*)value); break;
	}

	t = obj.t;

	switch (t)
	{
	case TYPE::INT:    value = new int(*( const int*)obj.value); break;
	case TYPE::DOUBLE: value = new double(*(const double*)obj.value); break;
	case TYPE::STR:    value = new String(*(const String*)obj.value); break;
	}

	return *this;
}

var var::operator+(const var& obj) const
{
	switch (t)
	{
	case TYPE::INT:
	{
		int a = *(int*)(value), b = 0;
		switch (obj.t)
		{
		case TYPE::INT:    b = *(int*)(obj.value); break;
		case TYPE::DOUBLE: b = int(*(double*)obj.value); break;
		case TYPE::STR:    b = atoi((*((String*)obj.value)).getStr()); break;
		}

		return var(a + b);
	}
	case TYPE::DOUBLE:
	{
		double a = *(double*)(value), b = 0.;
		switch (obj.t)
		{
		case TYPE::INT:    b = double(*(int*)(obj.value)); break;
		case TYPE::DOUBLE: b = *(double*)obj.value; break;
		case TYPE::STR:    b = atof((*((String*)obj.value)).getStr()); break;
		}

		return var(a + b);
	}
	case TYPE::STR:
	{
		String a = *(String*)value;
		String b;

		switch (obj.t)
		{
		case TYPE::INT:
		{
			char buffer[20];
			_itoa(*(int*)obj.value, buffer, 10);
			b = String(buffer);
			break;
		}
		case TYPE::DOUBLE: // https://stackoverflow.com/questions/7228438/convert-double-float-to-string
		{
			char buffer[64];
			snprintf(buffer, sizeof(buffer), "%g", *(double*)obj.value); // https://en.cppreference.com/cpp/io/c/fprintf
			b = String(buffer);
			break;
		}
		case TYPE::STR:
			b = *(String*)obj.value;
			break;
		}

		return var(a + b);
	}
	}

	return 0; //error
}

bool var::operator==(const var& v) const
{
	switch (t)
	{
	case TYPE::INT:
	{
		int a = *(int*)(value), b = 0;
		switch (v.t)
		{
		case TYPE::INT:    b = *(int*)(v.value); break;
		case TYPE::DOUBLE: b = int(*(double*)v.value); break;
		case TYPE::STR:    b = atoi((*((String*)v.value)).getStr()); break;
		}

		return a == b;
	}
	case TYPE::DOUBLE:
	{
		double a = *(double*)(value), b = 0.;
		switch (v.t)
		{
		case TYPE::INT:    b = double(*(int*)(v.value)); break;
		case TYPE::DOUBLE: b = *(double*)v.value; break;
		case TYPE::STR:    b = atof((*((String*)v.value)).getStr()); break;
		}

		return a == b;
	}
	case TYPE::STR:
	{
		String a = *(String*)value;
		String b;

		switch (v.t)
		{
		case TYPE::INT:
		{
			char buffer[20];
			_itoa(*(int*)v.value, buffer, 10);
			b = String(buffer);
			break;
		}
		case TYPE::DOUBLE: // https://stackoverflow.com/questions/7228438/convert-double-float-to-string
		{
			char buffer[64];
			snprintf(buffer, sizeof(buffer), "%g", *(double*)v.value); // https://en.cppreference.com/cpp/io/c/fprintf
			b = String(buffer);
			break;
		}
		case TYPE::STR:
			b = *(String*)v.value;
			break;
		}

		return a == b;
	}
	}
	
	return false; //error
}

var var::operator*(const var& obj) const
{
	switch (t)
	{
	case TYPE::INT:
	{
		int a = *(int*)(value), b = 0;
		switch (obj.t)
		{
		case TYPE::INT:    b = *(int*)(obj.value); break;
		case TYPE::DOUBLE: b = int(*(double*)obj.value); break;
		case TYPE::STR:    b = atoi((*((String*)obj.value)).getStr()); break;
		}

		return var(a * b);
	}
	case TYPE::DOUBLE:
	{
		double a = *(double*)(value), b = 0.;
		switch (obj.t)
		{
		case TYPE::INT:    b = double(*(int*)(obj.value)); break;
		case TYPE::DOUBLE: b = *(double*)obj.value; break;
		case TYPE::STR:    b = atof((*((String*)obj.value)).getStr()); break;
		}

		return var(a * b);
	}
	case TYPE::STR:
	{
		String a = *(String*)value, b;
		char number[64];

		switch (obj.t)
		{
		case TYPE::INT:
			_itoa(*(int*)obj.value, number, 10);
			b = String(number);
			break;
		case TYPE::DOUBLE:
			snprintf(number, sizeof(number), "%g", *(double*)obj.value);
			b = String(number);
			break;
		case TYPE::STR:
			b = *(String*)obj.value;
			break;
		}

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

	return 0; //error
}

var var::operator/(const var& obj) const
{
	switch (t)
	{
	case TYPE::INT:
	{
		int a = *(int*)(value), b = 0;
		switch (obj.t)
		{
		case TYPE::INT:    b = *(int*)(obj.value); break;
		case TYPE::DOUBLE: b = int(*(double*)obj.value); break;
		case TYPE::STR:    b = atoi((*((String*)obj.value)).getStr()); break;
		}

		return (b != 0) ? var(a / b) : a;
	}
	case TYPE::DOUBLE:
	{
		double a = *(double*)(value), b = 0.;
		switch (obj.t)
		{
		case TYPE::INT:    b = double(*(int*)(obj.value)); break;
		case TYPE::DOUBLE: b = *(double*)obj.value; break;
		case TYPE::STR:    b = atof((*((String*)obj.value)).getStr()); break;
		}

		return (b != 0) ? var(a / b) : a;
	}
	case TYPE::STR:
	{
		String a = *(String*)value, b;
		char number[64];

		switch (obj.t)
		{
		case TYPE::INT:
			_itoa(*(int*)obj.value, number, 10);
			b = String(number);
			break;
		case TYPE::DOUBLE:
			snprintf(number, sizeof(number), "%g", *(double*)obj.value);
			b = String(number);
			break;
		case TYPE::STR:
			b = *(String*)obj.value;
			break;
		}
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

	return 0; // error
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
