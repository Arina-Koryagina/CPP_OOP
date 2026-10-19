#pragma once
#include<iostream>

#include"String.h"

using namespace std;

class Pet
{
	String name;
	size_t age;
	String breed;
	String colour;
	String food;

public:
	Pet(String n, size_t a, String c) : name(n), age(a), colour(c) {}

	void feed()
	{
		cout << "You fed your pet\n";
	}
	void play()
	{
		cout << "You played with your pet\n";
	}
	void wash()
	{
		cout << "You washed your pet\n";
	}
	void teach()
	{
		cout << "You get your pet a lesson\n";
	}
	void info()
	{
		cout << name << " is " << age << "y.o.\n";
	}
};

class Dog : public Pet
{
public:
	Dog(String n, size_t a, String c) : Pet(n, a, c) {}

	void info();
};

class Cat : public Pet
{
public:
	Cat(String n, size_t a, String c) : Pet(n, a, c) {}

	void info();

};

class Parrot : public Pet
{
public:
	Parrot(String n, size_t a, String c) : Pet(n, a, c) {}

	void info();

};