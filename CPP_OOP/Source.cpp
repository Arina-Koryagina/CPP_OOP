#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

//#include"WarOfWorld.h"
#include"Animal.h"
#include"SmartPointer.h"

using namespace std;

template<class Cont>
void print(Cont& cont)
{
	for (auto elem : cont)
	{
		cout << elem << " ";
	}
	cout << endl;
}

//bool isEven(int a)
//{
//	return a % 2 == 0;
//}

int main()
{
	vector<int> v = { 1,2,3,4,5,6 };
	//vector<int> v1 = { 12, 23, 34, 45, 56, 67 };
	print(v);




	//v.insert(v.begin() + 3, 99);
	//v.insert(v.begin() + 3, v1.begin() + 2, v1.begin() + 5);
	//v.insert(v.begin() + 3, {6,7,8,9});
	//print(v);

	/*vector<Cat> vc = { Cat("William", 4), Cat("Gerard", 8) };
	vc.insert(vc.begin() + 1, Cat("Tom", 3));
	vc.emplace(vc.begin() + 1, "Barsik", 4);
	for (Cat cat : vc)
	{
		cat.print();
	}*/

	//erase_if(v, isEven);
	//erase_if(v, [](int a) { return a % 2 == 0; });
	//print(v);

	auto f = [](const char* msg) {cout << msg << endl; };
	f("mama");


	auto ff = [](int a)->int {
		if (a == 0)
			return 10;
		return 5.0; };
	cout << ff(0) << endl;

	int c = 10, m = 12;
	auto fff = [=, &c]() { cout << ++c << m << endl; }; // & - link, = - copy
	fff();

	//v.push_back(10);
	//cout << v.size() << endl;
	//cout << v.capacity() << endl;

	//auto it = v.begin() + 2; // auto = vector<int>::iterator
	//cout << *(++it) << endl;

	//v.shrink_to_fit();
	//cout << v.size() << endl;
	//cout << v.capacity() << endl;
	//cout << v.max_size() << endl; // 4 611 686 018 427 387 903

	//SharedPointer<Cat> c(new Cat("William", 4));
	//c->print();
	//SharedPointer<Cat> c1(c);
	//c1->print();
	//SharedPointer<Cat> c2 = c1;
	//c2->print();


	//WarOfWorld war(3, 5);
	//war.game();

	return 0;
}