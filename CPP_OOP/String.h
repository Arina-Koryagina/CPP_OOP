#pragma once
#include<iostream>

using namespace std;

class String
{
	char* str = nullptr;
	int size = 0;

public:
	String();
	String(int l);
	String(const char* line);

	~String();

	void clear();
	void clear(int l);

	void input();
	void input(const char* line);

	String reSize();

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
}

String::~String()
{
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
	cout << "Input line: ";
	char buffer[256];

	cin.getline(buffer, 256);
	if (strlen(buffer) > size)
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
	size = strlen(line);
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
