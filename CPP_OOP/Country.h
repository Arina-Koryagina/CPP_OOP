#pragma once
#include<iostream>

using namespace std;

#include"String.h"

enum class stateStructure
{
	UnitarySystem, FederalSystem, Confederation
};

class Country
{
	String name;
	double area;
};