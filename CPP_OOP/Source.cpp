#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

//#include"WarOfWorld.h"
#include"Animal.h"
#include"Dictionary.h"

using namespace std;

template<class Cont>
void print(Cont& cont)
{
	for (auto elem : cont)
	{
		cout << elem << endl;
	}
	cout << endl;
}

int main()
{
	Dictionary d;
	try
	{
		d.readFile("GoodOmens.txt");
	}
	catch (const exception& ex)
	{
		cout << ex.what() << endl;
	}
	d.showStats();
	cout << endl;
	d.showStats(5);
	d.saveStats();


	
	//WarOfWorld war(3, 5);
	//war.game();

	return 0;
}