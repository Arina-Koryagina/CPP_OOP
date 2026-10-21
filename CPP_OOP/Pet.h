#pragma once
#include<iostream>

#include"String.h"

using namespace std;

class Pet
{
	String name;
	size_t age;
	String colour;
	String character;
	String food = "";

public:
	Pet() : Pet("Unknown", 0, "Unknown", "Unknown") {}
	Pet(String name, size_t age, String colour, String character) : name(name), age(age), colour(colour), character(character) {}

	void feed() const
	{
		cout << "You fed " << name << ".\n";
	}
	void watch() const
	{
		cout << "You watched " << name << " (doing smth).\n";
	}
	void play() const
	{
		cout << "You played with " << name << ".\n";
	}

	void info() const
	{
		cout << name << " is a " << age << " y.o. " << character << " " << colour;
	}

	void rename(const String& new_name) { name = new_name; }
	void ageUp() { age++; }

	void setFavouriteFood(const String& fav_food) { food = fav_food; }
	String getFood() const { return food; }
	bool foodSet() const { return (food != "") ? true : false; }

	void  sleep() const { cout << "\"Hrrrr mimimi\"\n"; }
	void    eat() const { cout << "*crunch-crunch*\n"; }
	void wonder() const { cout << "*wondering around*\n"; }
};

class Dog : public Pet
{
	String favToy = "";
	int ballsCaught = 0;
	bool canFetch = false;

public:
	Dog(String name, size_t age, String colour, String character) : Pet(name, age, colour, character) {}

	void info() const
	{
		Pet::info();
		cout << " dog.\n";
		if (Pet::foodSet())
		{
			cout << "They like eating " << getFood() << ".\n";
		}
		if (favToy != "")
		{
			cout << "They like playing with " << favToy << ".\n";
		}
		if (canFetch)
		{
			cout << "Is trained to fetch a stick.\n";
		}
		cout << "Catched balls counter: " << ballsCaught << endl;
	}

	void train() { canFetch = true; }
	void ballCatch() { ballsCaught++; }
	void setFavouriteToy(const String& fav_toy) { favToy = fav_toy; }
	String getToy() const { return favToy; }

	void bark() const { cout << "Bark!\n"; }
	void chase() const { cout << "*chasing cats around*\n"; }
};

class Cat : public Pet
{
	String favSpot = "";
	int plantsEaten = 0;
	bool isLiquid = true;

public:
	Cat(String name, size_t age, String colour, String character) : Pet(name, age, colour, character) {}

	void info() const
	{
		Pet::info();
		cout << " cat.\n";
		if (Pet::foodSet())
		{
			cout << "They like eating " << getFood() << ".\n";
		}
		if (favSpot != "")
		{
			cout << "They like laying at the " << favSpot << ".\n";
		}
		if (isLiquid)
		{
			cout << "Is a confirmed liquid. (evidence present)\n";
		}
		cout << "Eaten plants counter: " << plantsEaten << endl;
	}

	void sprawl() { isLiquid = true; }
	void eatPlant() { plantsEaten++; }
	void setFavouriteSpot(const String& fav_spot) { favSpot = fav_spot; }
	String getSpot() const { return favSpot; }

	void meow() const { cout << "Meow~\n"; }
	void pets() const { cout << "*demanding pets*\n"; }
};

class Parrot : public Pet
{
	String favStick = "";
	int wordsSaid = 0;
	bool canTalk = true;

public:
	Parrot(String name, size_t age, String colour, String character) : Pet(name, age, colour, character) {}

	void info() const
	{
		Pet::info();
		cout << " parrot.\n";
		if (Pet::foodSet())
		{
			cout << "They like eating " << getFood() << ".\n";
		}
		if (favStick != "")
		{
			cout << "They like nibbling at the " << favStick << ".\n";
		}
		if (canTalk)
		{
			cout << "Has ability to talk.\n";
		}
		cout << "Said words counter: " << wordsSaid << endl;
	}

	void repeat() { canTalk = true; }
	void speak() { wordsSaid++; }
	void setFavouriteStick(const String& fav_stick) { favStick = fav_stick; }
	String getStick() const { return favStick; }

	void talk() const { cout << ((canTalk) ? "Placebo\n" : "Squawk"); }
	void fly() const { cout << "*flying around*\n"; }
};