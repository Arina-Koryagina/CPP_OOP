#pragma once
#include<iostream>

#include"Array.h"
#include"Func.h"

using namespace std;

class Student
{
	char* name = nullptr;
	int age = 0;
	int mCount = 0;
	int* marks = nullptr;

	const int id;

	static int count;

public:
	// constructors
	Student(int id) : id{ id }
	{
		setName("Unknown");
		cout << "Default constructor called" << endl;
	}

	Student(int id, const char* n, int a) : id{ id }
	{
		cout << "Parameterized constructor called" << endl;
		setName(n);
		setAge(a);
	}

	// destructor

	~Student()
	{
		cout << "Destructor called" << endl;
		delete[] name;
		delete[] marks;
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
			return;
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
		if (!isdigit(m) || m < 0 || m > 12)
		{
			return;
		}
		else
		{
			addValueArray(marks, mCount, m);
			//marks.add(m);
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

	static int getCount()
	{
		return count;
	}

	void displayInfo()
	{
		cout << "ID: " << id << "\nName: " << name << ", Age: " << age << "\nMarks: ";
		//marks.show();
		printArray(marks, mCount);
	}
};

int Student::count = 0;