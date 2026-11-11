#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <stack>
#include <list>
#include <set>

//#include"WarOfWorld.h"
#include"Animal.h"
#include"SmartPointer.h"
//#include"md5.h"

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

class MyStack : public stack<int>
{
public:
	void show()
	{
		//auto it = this->c.begin();
		//while (it != )
		//{

		//}
	}
};

int main()
{
	set<int> s = { 1, 2, 3, 4, 3, 6, 5, 6, 7 };
	auto p = s.insert(16);
	cout << *p.first << " " << p.second << endl;
	print(s);


	//list<Cat> cats = { Cat("Tom", 3), Cat("Gerard", 8), Cat("William", 5) };
	//print(cats);
	////cats.sort([](Cat& c1, Cat& c2) {return c1.getAge() < c2.getAge();});
	//cats.sort([](Cat& c1, Cat& c2) {return c1.getName() < c2.getName();});
	//print(cats);

	//string password = "123456";
	//string phash = md5(password);
	//cout << "Password: " << password << endl;
	//cout << "Hash: " << phash << endl;

	//hash<string> h;
	//auto hash2 = h(password);
	//cout << "Hash2: " << hash2 << endl;

	


	//WarOfWorld war(3, 5);
	//war.game();

	return 0;
}