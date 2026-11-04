#pragma once
#include<iostream>

using namespace std;


class IPrintable
{
public:
	virtual void print() = 0;
};


class Animal
{
	string name;
	int age;

public:
	Animal(string n, int a) : name(n), age(a) {}

	virtual ~Animal() {} // { cout << "Destr Animal\n"; }

	string getName() { return name; }

	virtual string getType() { return "Animal"; }

	virtual string getVoice() = 0;
};

string Animal::getVoice()
{
	return "no sound";
}

class Cat /*final*/ : public Animal, public IPrintable
{
	int mouse = 0;

public:
	Cat(string n, int a) : Animal(n, a) {}

	~Cat() {} // { cout << "Destr Cat\n"; }

	virtual string getType() override { return "Cat"; }

	virtual string getVoice() /*final*/ override { return "Me-ow~"; }

	virtual void print() { cout << "Cat " << getName() << endl; }

	void catchMouse() { mouse++; }

	int getMouse() { return mouse; }
};

class BritishKitten : public Cat
{
public:
	BritishKitten(string n, int a) : Cat(n, a) {}

	virtual string getType() override { return "BritishKitten"; }

	virtual string getVoice() override { return "Mmmrrrr meow~"; }
};

class Dog : public Animal, public IPrintable
{
public:
	Dog(string n, int a) : Animal(n, a) {}

	virtual string getType() override { return "Dog"; }

	virtual string getVoice() override { return "Bark!"; }

	virtual void print() { cout << "Dog\n"; }
};

class Snail : public Animal
{
public:
	Snail(string n, int a) : Animal(n, a) {}

	virtual string getType() override { return "Snail"; }

	virtual string getVoice() override { return Animal::getVoice(); }
};
