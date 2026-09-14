#pragma once
#include<iostream>

#include"Func.h"

using namespace std;

class Student
{
	char* name;
	int age;
	int mCount = 0;
	int* marks;

	//int id;

public:
	// constructors
	Student()
	{
		setName("Unknown");
		setAge(0);
		cout << "Default constructor called" << endl;
	}

	Student(const char* n, int a)
	{
		cout << "Parameterized constructor called" << endl;
		setName(n);
		setAge(a);
	}

	// setters
	void setName(const char* n)
	{
		if (n != nullptr)
		{
			name = new char[strlen(n) + 1];
			strcpy(name, n);
		}
		else
		{
			name = nullptr;
		}
	}

	void setAge(int a)
	{
		if (a < 0 || a > 100)
		{
			age = 0;
		}
		else
		{
			age = a;
		}
	}

	void setMark()
	{
		int m;
		cin >> m;
		setMark(m);
	}

	void setMark(int m)
	{
		if (m < 0 || m > 12)
		{
			addValueArray(marks, mCount, 0);
		}
		else
		{
			addValueArray(marks, mCount, m);
		}
	}

	// getters

	int getAge()
	{
		return age;
	}

	char* getName()
	{
		return name;
	}

	void displayInfo()
	{
		cout << "Name: " << name << "\nAge: " << age << "\nMarks: ";
		printArray(marks, mCount);
	}
};