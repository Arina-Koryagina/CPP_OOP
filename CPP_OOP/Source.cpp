#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <stack>
#include <list>
#include <set>
#include <map>
#include <algorithm>

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

//class FromCatName
//{
//public:
//	bool operator()(const Cat& c1, const Cat& c2) const
//	{
//		return c1.getName() < c2.getName();
//	}
//};

class CalcOddEven
{
	int even;
	int odd;

public:
	bool operator()(int a)
	{
		
	}
	int getEven() { return even; }
	int getOdd() { return odd; }
};

int main()
{
	cout.setf(ios::boolalpha);

	list<Cat> cats = { Cat("Tom", 3), Cat("William", 5), Cat("Gerard", 8) };
	//for_each(cats.begin(), cats.end(), [](Cat& c) {c.setAge(c.getAge()+1);});
	//print(cats);

	int arr[] = { 1,2,3,4,5 };

	//cout << all_of(cats.begin(), cats.end(), [](Cat& c) {return c.getAge() > 1;}) << endl;
	//cout << all_of(begin(arr), end(arr), [](int a) {return a > 0;}) << endl;
	//cout << any_of(begin(arr), end(arr), [](int a) {return a > 0;}) << endl;

	//auto it = find_if(cats.begin(), cats.end(), [](Cat& c) { return c.getName() == "William";});
	//if(it != cats.end())
	//	cout << (*it).getVoice() << endl;

	cout << count_if(begin(arr), end(arr), [](int a) {return a > 2;}) << endl;

	//CalcOddEven calc;
	//calc = for_each(begin(arr), end(arr), calc);
	//cout << "Even: " << calc.getEven() << ", Odd: " << calc.getOdd() << endl;

	//map<string, int> m;
	//m["one"] = 1;
	//cout << m["two"] << endl;

	//for (auto elem : m)
	//{
	//	cout << elem.first << " " << elem.second << endl;
	//}


	//map<string, Cat, FromCatName> cats;
	//cats.insert(make_pair("Tom", Cat("Tom", 3)));
	//cats.insert(make_pair("Gerard", Cat("Gerard", 8)));
	//cats.insert(make_pair("William", Cat("William", 5)));
	//for (auto elem : cats)
	//{
	//	cout << elem.first << endl;
	//}
	//set<Cat, FromCatName> cats;
	//cats.insert(Cat("Tom", 3));
	//cats.insert(Cat("Gerard", 8));
	//cats.insert(Cat("William", 5));
	//for (auto elem : cats)
	//{
	//	cout << elem.getName() << endl;
	//}

	

	


	//WarOfWorld war(3, 5);
	//war.game();

	return 0;
}