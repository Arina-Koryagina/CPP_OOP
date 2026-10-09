#pragma once
#include<iostream>
#include<cassert>

using namespace std;

class String
{
	char* str = nullptr;
	int size = 0;

	int lenStr(const char* str) const
	{
		int i = 0;
		if (str != nullptr)
		{
			while (str[i] != '\0')
			{
				i++;
			}
		}

		return i;
	}

	void myStrcpy(char* str, const String& obj) const
	{
		for (int i = 0; i <= size; i++)
		{
			str[i] = obj.str[i];
		}
	}

public:
	String();
	String(int l);
	String(const char* line);
	String(const String& obj);

	String& operator=(const String& obj);

	String operator+(const String& obj) const;
	String operator*(int times) const;
	String& operator+=(const String& obj);
	String& operator*=(int times);

	char operator[](int index) const;
	void operator()(const char* line);
	void operator()(const String& obj);

	bool operator==(const String& obj) const;
	bool operator!=(const String& obj) const;
	bool operator<(const String& obj) const;
	bool operator>(const String& obj) const;
	bool operator<=(const String& obj) const;
	bool operator>=(const String& obj) const;

	friend ostream& operator<<(ostream& out, const String& s);
	friend istream& operator>>(istream& in, String& s);

	operator char* () const;

	~String();

	void clear();
	void clear(int l);

	void input();
	void input(const char* line);

	const char* getStr() const;
	int getLen() const;

	void print() const;

	//String reSize();
	//int countWords() const;
};

String::String() : String(80) { }
String::String(int l)
{
	clear(l);
}
String::String(const char* line)
{
	input(line);
	//cout << "Constr\n";
}
String::String(const String& obj)
{
	size = obj.size;
	str = new char[size + 1];
	strcpy(str, obj.str);
	//cout << "Copy\n";
}

String& String::operator=(const String& obj)
{
	if (this == &obj)
	{
		return *this;
	}

	delete[] str;

	size = obj.size;
	str = new char[size + 1];
	strcpy(str, obj.str);
	/*for (int i = 0; i <= size; i++)
	{
		str[i] = obj.str[i];
	}*/
	//str[size] = '\0';

	return *this;
}

String String::operator+(const String& obj) const
{
	char* temp = new char[size + obj.size + 1];
	strcpy(temp, str);
	strcpy(temp + size, obj.str);

	String st(temp);
	delete[] temp;
	return st;
}
String String::operator*(int times) const
{
	if (times > 0)
	{
		char* temp = new char[size * times + 1];

		for (int i = 0; i < times; i++)
		{
			strcpy(temp + size * i, str);
		}

		String st(temp);
		delete[] temp;
		return st;
	}
	return "";
}
String& String::operator+=(const String& obj)
{
	*this = *this + obj;
	return *this;
}
String& String::operator*=(int times)
{
	*this = *this * times;
	return *this;
}

char String::operator[](int index) const
{
	assert(index >= 0 && index < size);
	return str[index];
}
//char& String::operator[](int index)
//{
//	assert(index >= 0 && index < size);
//	return str[index];
//}
void String::operator()(const char* line)
{
	input(line);
}
void String::operator()(const String& obj)
{
	size = obj.size;
	delete[] str;
	str = new char[size + 1];
	strcpy(str, obj.str);
}

bool String::operator==(const String& obj) const
{
	return strcmp(str, obj.str) == 0;
}
bool String::operator!=(const String& obj) const
{
	return !(*this == obj);
}
bool String::operator<(const String& obj) const
{
	if (strcmp(str, obj.str) < 0)
	{
		return true;
	}
	return false;
}
bool String::operator>(const String& obj) const
{
	return !(*this < obj || *this == obj);
}
bool String::operator<=(const String& obj) const
{
	return (*this < obj || *this == obj);
}
bool String::operator>=(const String& obj) const
{
	return (*this > obj || *this == obj);
}

ostream& operator<<(ostream& out, const String& s)
{
	out << s.str;
	return out;
}
istream& operator>>(istream& in, String& s)
{
	char word[80];
	in >> word;
	if (in)
	{
		s.input(word);
	}
	return in;
}

String::operator char* () const
{
	return str;
}

String::~String()
{
	//cout << " Destr\n";
	delete[] str;
}

void String::clear(int l)
{
	size = l;
	delete[] str;
	str = new char[size + 1];
	str[0] = '\0';
}
void String::clear()
{
	clear(80);
}

void String::input()
{
	//cout << "Input line: ";
	char buffer[256];

	cin.getline(buffer, 256);
	if (lenStr(buffer) > size)
	{
		input(buffer);
	}
	else
	{
		strcpy(str, buffer);
	}
}
void String::input(const char* line)
{
	size = lenStr(line);
	delete[] str;
	str = new char[size + 1];
	strcpy(str, line);
}

int String::getLen() const
{
	return size;
}

const char* String::getStr() const
{
	return str;
}

void String::print() const
{
	cout << str << endl;
}

//String String::reSize()
//{
//	size = 50;
//	str = new char[size];
//	return *this;
//}
//int String::countWords() const
//{
//	int count = 0;
//	for (int i = 0; i < size; i++)
//	{
//		if (isalnum(str[i]) && (str[i + 1] == ' ' || str[i + 1] == '\0' || ispunct(str[i + 1])))
//		{
//			count += 1;
//		}
//	}
//
//	return count;
//}
