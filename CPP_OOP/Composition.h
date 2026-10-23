#pragma once
#include<iostream>

#include"String.h"

using namespace std;

// Composition
//class Engine
//{
//	int cylinder = 4;
//
//public:
//
//	void start()
//	{
//		cout << "Engine started" << endl;
//	}
//
//	void stop()
//	{
//		cout << "Engine stopped" << endl;
//	}
//};
//
//class Car
//{
//	Engine en;
//
//public:
//
//	void move()
//	{
//		en.stop();
//		cout << "Moving" << endl;
//		en.stop();
//	}
//
//};

// Agregation
class Engine
{
	int cilindr = 4;
	int power   = 50;

public:

	void start()
	{
		cout << "Engine start" << endl;
	}

	void stop()
	{
		cout << "Engine stop" << endl;
	}

	void powerUpgrade()
	{
		power += 10;
	}
};

class Car
{
	Engine* en;

public:
	Car() { en = new Engine; }
	~Car() { delete en; }
	//Car(Engine* en) : en(en) {}

	void move()
	{
		en->start();
		cout << "Moving" << endl;
		en->stop();
	}

	//Engine* getEngine()
	//{
	//	return en;
	//}

};

class STO
{
	Engine* en;

public:
	void setEngine(Engine* en)
	{
		this->en = en;
	}

	void upgrade()
	{
		en->powerUpgrade();
	}
};


class Human
{
	String name;
	int age;

public:
	Human(String n, int a)
	{
		name = n;
		age = a;
	}

	void setAge(int a)
	{
		age = a;
	}

	int getAge()
	{
		return age;
	}

	void info()
	{
		cout << "Name : " << name << endl;
		cout << "Age  : " << age << endl;
	}

	void method()
	{
		// name;
		// age;
	}
};

class Player : public Human
{
	int goal;

public:
	Player(String name, int age, int goal) : Human(name, age), goal(goal) {}
	~Player() {}

	void info()
	{
		Human::info();
		cout << "Goal : " << goal << endl;
	}

	void method() = delete;
};

class Device
{
public:
	int id;

	Device(int id) : id(id)
	{

	}
};

class LANDevice : virtual public Device
{
	int id;

public:
	LANDevice(int id, int id_d) : id(id), Device(id_d)
	{

	}

	int getID() { return id; }
};

class WiFiDevice : virtual public Device
{
	int id;

public:
	WiFiDevice(int id, int id_d) : id(id), Device(id_d)
	{

	}

	int getID() { return id; }
};

class Router : public WiFiDevice, public LANDevice
{
	int id;

public:
	Router(int id, int id_w, int id_l, int id_d) : id(id), WiFiDevice(id_w, id_d), LANDevice(id_l, id_d), Device(id_d)
	{

	}
};