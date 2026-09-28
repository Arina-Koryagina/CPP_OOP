#pragma once
#include<iostream>

#include"String.h"

using namespace std;

enum class TYPE
{
	INT, DOUBLE, STR
};

class var
{
	TYPE t;
	void* value;

public:
	var(int v);
	var(double v);
	var(String v);

	void Show();
};

var::var(int v)
{
	t = TYPE::INT;
	value = new int(v);
}
var::var(double v)
{
	t = TYPE::DOUBLE;
	value = new double(v);
}
var::var(String v)
{
	t = TYPE::STR;
	value = new String(v);
}

void var::Show()
{
	if (t == TYPE::STR)
	{
		//*((String)value).print();
	}
	else
	{
		cout << ((t == TYPE::INT) ? *((int*)value) : *((double*)value)) << endl;
	}
}