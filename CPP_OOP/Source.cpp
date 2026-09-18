#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

#include"Student.h"
#include"Array.h"
#include"Time.h"
#include"String.h"

using namespace std;

void printArray(const Array& a)
{
	a.show();
}

int main()
{
	String st;
	st.input("  Hello ,      World!  C++");
	st.print();
	cout << st.getLen() << endl;
	cout << st.countWords() << endl;
	st.clear();
	st.input();
	st.print();

	//Time t(1, 1);
	/*Time* t1 = new Time(1, 1, 1);
	Array* arr = new Array(5);
	arr->setRand();

	Student s1(1, "Vasya", 30);
	Array a(10);
	a.setRand();
	a.show();

	printArray(a);*/

	/*const Array arr(10);
	
	arr.setRand();
	arr.show();*/


	//arr.setRand();
	//arr.show();
	//arr.add(10);
	//arr.remove(4);
	//arr.show();
	//arr.insert(32, 6);
	//arr.show();
	//arr.sort();
	//arr.reverse();
	//arr.show();
	//arr.resize(5);
	//arr.show();
	//arr.fill(0);
	//arr.show();
	//arr.clear();
	//arr.create(10);
	//arr.setRand();
	//arr.show();


	//Student s1(1, "Vasya", 30);
	////cout << "Count of students: " << s1.getCount() << endl;

	//Student s2(2);
	////cout << "Count of students: " << s1.getCount() << endl;

	//s1.displayInfo();
	//s2.displayInfo();


	return 0;
}