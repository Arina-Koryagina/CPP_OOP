#pragma once

#include"BTree.h"
#include"String.h"
#include"List.h"

class Protocol
{
	String number;
	String date;
	int charge;
	bool isPaid = false;

public:
	String getNumber();
	void input();
};

String Protocol::getNumber()
{
	return number;
}

void Protocol::input()
{
}

class PoliceBase
{
	BTree<String, List<Protocol*>> base;

public:
	void addProtocol();
	void print();
	void print(String number1, String number2);
	void save();
	void load();
	void pay();
};

void PoliceBase::addProtocol()
{
	Protocol* p = new Protocol;// (.input());

	List<Protocol*>* l = base.getValue(p->getNumber());
	if (l)
	{
		l->push_back(p);
	}
	else
	{
		List<Protocol*> newList;
		newList.push_back(p);
		base.push_r(p->getNumber(), newList);
	}
}

void PoliceBase::print()
{
}

void PoliceBase::print(String number1, String number2)
{
}

void PoliceBase::save()
{
}

void PoliceBase::load()
{
}

void PoliceBase::pay()
{
}
