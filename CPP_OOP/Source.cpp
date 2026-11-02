#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

//#include"WarOfWorld.h"
#include"Animal.h"
#include"SmartPointer.h"
#include"List.h"

using namespace std;

//void PrintAnimal(IPrintable* a)
//{
//	a->print();
//}

//void superFunc()
//{
//	//Cat* c = new Cat("Gerard", 8);
//	SmartPointer<Cat> c(new Cat("Gerard", 8));
//	SmartPointer<Cat> c1 = move(c);
//
//	int a;
//	cin >> a;
//	if (a == 0)
//		throw new invalid_argument("a = 0");
//
//	//delete c;
//}

int main()
{
	SharedPointer<Cat> c(new Cat("William", 4));
	//cout << c << endl;
	SharedPointer<Cat> c1(c);


	//SmartPointer<Cat> c(new Cat("William", 4));
	//c->print();

	//SmartPointer<Cat>c1 = move(c);
	//c1->print();

	//unique_ptr<Cat> c = make_unique<Cat>("William", 4);
	//unique_ptr<Cat> c1;
	//cout << c << endl;
	//cout << c1 << endl;

	//c1 = move(c);
	//cout << c << endl;
	//cout << c1 << endl;


	//shared_ptr<Cat> k1 = make_shared<Cat>("William", 4);

	//int a = 10;
	//int&& b = 10;

	//List<Cat> l;// = { Cat("Tom", 3), Cat("William", 5), Cat("Gerard", 8) };
	//l.push_back(Cat("Tom", 3));
	//l.push_back(Cat("William", 5));

	//IPrintable* a = new BritishKitten("William", 3);
	//PrintAnimal(a);


	//WarOfWorld war(3, 5);
	//war.game();

	return 0;
}