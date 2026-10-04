#pragma once
#include<iostream>

using namespace std;

class String
{
	char* str = nullptr;
	int size = 0;

	int lenStr(const char* str)
	{
		int i = 0;
		while (str[i] != '\0')
		{
			i++;
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
	String operator+(const String& obj);
	String operator-(const String& obj);
	char operator[](int index);
	bool operator==(const String& other) const;
	bool operator<(const String& other) const;
	operator char* () const;

	~String();

	void clear();
	void clear(int l);

	void input();
	void input(const char* line);

	String reSize();

	const char* getStr() const;
	int getLen() const;

	void print() const;

	int countWords() const;
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

String String::operator+(const String& obj)
{
	char* temp = new char[size + obj.size + 1];
	strcpy(temp, str);
	strcpy(temp + size, obj.str);

	String st(temp);
	delete[] temp;
	return st;
}

String String::operator-(const String& obj) //
{
	char* temp = new char[size + obj.size + 1];
	strcpy(temp, str);
	strcpy(temp + size, obj.str);

	String st(temp);
	delete[] temp;
	return st;
}

char String::operator[](int index)
{
	//assert(index >= 0 && index < size);
	return str[index];
}
bool String::operator==(const String& other) const
{
	if (strcmp(str, other.str))
	{
		return true;
	}
	return false;
}
bool String::operator<(const String& other) const
{
	if (strcmp(str, other.str) < 0)
	{
		return true;
	}
	return false;
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

String String::reSize()
{
	size = 50;
	str = new char[size];
	return *this;
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

int String::countWords() const
{
	int count = 0;
	for (int i = 0; i < size; i++)
	{
		if (isalnum(str[i]) && (str[i + 1] == ' ' || str[i + 1] == '\0' || ispunct(str[i + 1])))
		{
			count += 1;
		}
	}

	return count;
}
