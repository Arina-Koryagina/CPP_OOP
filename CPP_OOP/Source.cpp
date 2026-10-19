#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

#include"Composition.h"
//#include"Inherit.h"

using namespace std;

int main()
{
	Player p("Messi", 40, 980);
	p.info();
	//p.method();


	//A a;
	//a.aaa = 10;

	//B b;
	//b.aaa = 10;

	//Human h(20);


	//Engine* en = new Engine;
	//{
	//	Car c(en);

	//	STO sto;
	//	sto.setEngine(c.getEngine());
	//	sto.upgrade();
	//}
	//en->start();

	return 0;
}