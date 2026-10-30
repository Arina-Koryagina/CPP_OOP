#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

//#include"Time.h"
#include"WarOfWorld.h"
#include"MyException.h"

using namespace std;

float division(int a, int b)
{
	if (b == 0)
		throw new invalid_argument("b = 0");
	return a / b;
}

int main()
{
	//WarOfWorld war(3, 5);
	//war.game();

	/*throw 1;
	throw "Error";
	throw Time();*/

	try
	{
		//cout << division(10, 0) << endl;
		int a, b;
		cin >> a >> b;
		if (b == 0)
			throw "Div by zero"; //exception; //new invalid_argument("b = 0");

		////if (b == 1)
		////	throw MyException(__DATE__, __TIME__, __FILE__, __LINE__, "Div by one");
		//
		cout << a / b << endl;
	}
	catch (exception* ex)
	{
		cout << ex->what() << endl;
	}
	catch (MyException& ex)
	{
		ex.getConsoleError();
		ex.saveToFile();
	}
	catch (const char* err)
	{
		cout << err << endl;
	}
	catch (int a)
	{
		cout << "Int " << a << endl;
	}
	catch (...)
	{
		cout << "Fatal error" << endl;
	}

	//PriorityQueue<int, int> p;
	//p.enqueue(10, 10);
	//p.enqueue(20, 20);
	//p.enqueue(50, 50);
	//p.dequeue();
	//p.print();

	//Animal* cat = new Kitten("Gerard", 8);

	//Kitten* c = dynamic_cast<Kitten*>(cat);
	//if(c)
	//{
	//	c->catchMouse();
	//	c->catchMouse();
	//	c->catchMouse();
	//	cout << c->getMouse() << endl;
	//}
	//else
	//{
	//	cout << "Not Cat\n";
	//}

	return 0;
}