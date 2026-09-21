#pragma once
#include<iostream>

#include"Array.h"
#include"String.h"

using namespace std;

class Student
{
	String name;
	int age = 0;
	Array marks;

	const int id;

	static int count;

public:
	// constructors
	Student(int id) : id{ id }
	{
		setName("Unknown");
		//cout << "Default constructor called" << endl;
	}

	Student(int id, const char* n, int a) : id{ id }
	{
		//cout << "Parameterized constructor called" << endl;
		setName(n);
		setAge(a);
	}

	// copy constructor
	Student(const Student& obj) : id(obj.id)
	{
		name = obj.name;
		/*int len = strlen(obj.name);
		name = new char[len + 1];
		strcpy(name, obj.name);*/

		age = obj.age;

		marks.create(obj.marks.getSize());
		marks = obj.marks;
				
		count++;

		//cout << "Copy constructor called\n";
	}

	// destructor

	~Student()
	{
		//cout << "Destructor called" << endl;
		//delete[] name;
	}

	// setters
	void setName(String n)
	{
		name = n;
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
		if (isdigit(m) || m < 0 || m > 12)
		{
			return;
		}
		else
		{
			marks.add(m);
		}
	}

	// getters

	int getAge()
	{
		return age;
	}

	String getName()
	{
		return name;
	}

	static int getCount()
	{
		return count;
	}

	void displayInfo()
	{
		cout << "ID: " << id << "\nName: ";
		name.print();
		cout << "Age: " << age << "\nMarks: ";
		marks.show();
	}
};

int Student::count = 0;