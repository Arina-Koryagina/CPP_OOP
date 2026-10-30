#pragma once
#include<iostream>

using namespace std;

class Animal
{
	string name;
	int age;

public:
	Animal(string n, int a) : name(n), age(a) {}

	virtual ~Animal() { cout << "Destr Animal\n"; }

	string getName() { return name; }

	virtual string getType() { return "Animal"; }

	virtual string getVoice() = 0;
};

string Animal::getVoice()
{
	return "no sound";
}

class Kitten /*final*/ : public Animal
{
	int mouse = 0;

public:
	Kitten(string n, int a) : Animal(n, a) {}

	~Kitten() { cout << "Destr Kitten" << endl; }

	virtual string getType() override { return "Kitten"; }

	virtual string getVoice() /*final*/ override { return "Me-ow~"; }

	void catchMouse() { mouse++; }

	int getMouse() { return mouse; }
};

class BritishKitten : public Kitten
{
public:
	BritishKitten(string n, int a) : Kitten(n, a) {}

	virtual string getType() override { return "BritishKitten"; }

	virtual string getVoice() override { return "Mmmrrrr meow~"; }
};

class Puppy : public Animal
{
public:
	Puppy(string n, int a) : Animal(n, a) {}

	virtual string getType() override { return "Puppy"; }

	virtual string getVoice() override { return "Bark!"; }
};

class Snail : public Animal
{
public:
	Snail(string n, int a) : Animal(n, a) {}

	virtual string getType() override { return "Snail"; }

	virtual string getVoice() override { return Animal::getVoice(); }
};
