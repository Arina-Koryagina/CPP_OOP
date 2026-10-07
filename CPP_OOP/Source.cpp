#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<Windows.h>

//#include"Student.h"
//#include"Time.h"
//#include"Reservoir.h"
//#include"Fraction.h"
//#include"var.h"
//#include"Calc.h"
//#include"Brackets.h"
#include"Array.h"
#include"String.h"
#include"Stack.h"
#include"Queue.h"
#include"PriorityQueue.h"
#include"Traffic.h"


using namespace std;

int main()
{
	srand(time(0));
	system("cls");

	//Time t(1, 2, 3.3);
	//cout << t << endl;
	//Time t1(3600);
	//cout << t1 << endl;

	Station station;
	//station.simulate();
	station.simulate(2, 10, 10);

	//PriorityQueue<int> pq;
	//pq.enqueue(10, 1);
	//pq.enqueue(20, 2);
	//pq.enqueue(10, 1);
	//pq.enqueue(30, 3);
	//pq.enqueue(20, 2);
	//pq.print();

	//PriorityQueue<Fraction, float> p;
	//p.enqueue(Fraction(2, 3), (float)Fraction(2, 3));
	//p.enqueue(Fraction(1, 3), (float)Fraction(1, 3));
	//p.enqueue(Fraction(3, 3), (float)Fraction(3, 3));
	//p.enqueue(Fraction(5, 3), (float)Fraction(5, 3));
	//p.enqueue(Fraction(1, 3), (float)Fraction(1, 3));
	//p.print();

	//Queue<int> q = { 1, 2, 3 };
	//q.enqueue(10);
	//q.print();
	//cout << q.peek() << endl;
	////q.clear();
	//q.dequeue();
	//q.print();
	//q.ring();
	//q.print();

	//Array<int> arr(10);
	//arr.add(1);
	//arr.add(2);
	//arr.add(3);
	//arr.add(4);
	//cout << arr.getUpperBound();

	/*Array<int> arr(5);
	arr.setRand();
	arr.show();
	cout << arr.getSize() << endl;
	arr.setSize(5);
	arr.show();
	cout << arr.getSize() << endl;
	arr.add(12);
	arr.show();
	cout << arr.getSize() << endl;
	arr.add(15);
	arr.show();
	cout << arr.getSize() << endl;*/
	//Array<int> arr2(5);
	//arr2.setRand();
	//arr2.show();

	//Array<int> arr3;
	//arr3 = arr + arr2;
	//arr3.show();
	//cout << arr3.getSize() << endl;
	//arr += arr2;
	//arr.show();

	//arr.append(arr2);
	//arr.show();
	//cout << arr.getData() << endl;

	//Brackets a("({x-y-z}*[x+2y]+(z+4x));");
	//Brackets b("({x - y - z} * [x + 2y] + (z + 4x));");
	//b.check();
	//Brackets c("([x - y - z} * [x + 2y) + {z + 4x)];");
	//c.check();

	/*Calc c("6*2+2^2+2-6*1");
	cout << c.getResult() << endl;*/

	//Stack<int, 5> s;
	//s.push(10);
	//s.push(5);
	//s.push(20);
	//s.push(15);
	//s.push(25);
	//s.push(35);
	//s.print();
	//Stack<int, 5> a(s);
	//a.print();
	//Stack<int, 5> b;
	//b = a;
	//b.print();
	//cout << s.peek() << endl;
	//s.pop();
	//s.pop();
	//s.print();
	//s.clear();
	//s.print();

	//var a = 15;
	//var b = "Hello";
	//var c = 7.8;
	//var d = "50";
	//b = a + d;
	//b.Show();
	//if (a == b)
	//{
	//	cout << "Equal\n";
	//}
	//else
	//{
	//	cout << "Not Equal\n";
	//}
	//var a = 10, b = "120", c;
	//c = a + b;
	//c.Show();
	//c = b + a;
	//c.Show();
	//a = "Microsoft", b = "Windows";
	//c = a * b;
	//c.Show();
	//c = a / b;
	//c.Show();


	//var n("Hello, World!");
	//n.Show();
	//cout << n << endl;

	//Array<int> arr(10);
	//arr.setRand();
	//arr.show();
	//cout << arr[2] << endl;

	//Array<Fraction> f(10);
	//f.show();

	//Array<Student> s(5);
	//s.setRand();

	// + - ++ --
	// + - * / += -= /= % %=
	// !
	// > < >= <= == != && ||
	// () [] << >>


	//Fraction f1(3, 5);
	//f1.show();
	//Fraction f2(0, 3);
	//f2.show();

	//if (f1 && f2)
	//{
	//	cout << "<<<" << endl;
	//}
	//else
	//{
	//	cout << ">>>" << endl;
	//}
	//f2(2, 5);
	//cout << f1["num"] << endl;
	//cout << f1 << endl;

	//cin >> f2;
	//cout << f2 << endl;
	
	/*f1 = f2 + 5;
	f1 = 5 + f2;
	f1.show();*/

	////Fraction f4 = f1 + f2;
	////f4.show();
	//Fraction f3 = -f1;
	//f3.show();

	//(f2++).show();
	//f2.show();
	//(++f2).show();

	//Reservoir::menu();

	//Reservoir a;

	//a.displayInfo();
	//a.setName("Black Sea");
	//a.setType(ReservoirType::Sea);
	//a.displayInfo();
	//a.getName().print();
	//cout << ReturnEnum(a.getType()) << endl;

	//cout << endl;
	//a.getName().print();
	//cout << endl;
	//a.getJob().print();
	//cout << endl;
	//cout << a.getYear() << endl;
	//cout << a.getMoney() << endl;

	//Student a(1);
	////Array m(10);
	////m.setRand();

	//a.setName("Brian");
	//a.setAge(15);
	//a.setMark(5);
	//a.setMark(10);
	///*for (int i = 0; i < 10; i++)
	//{
	//	a.setMark(m[i]);
	//}*/
	//a.displayInfo();
	//Student b(a);
	//b.displayInfo();



	/*String s("mama");
	s.print();
	String st(s);
	st.print();
	s.print();*/
	
	/*Array a(10);
	a.setRand();
	a.show();
	printArray(a);
	a.show();*/

	//String st;
	//st.input("  Hello ,      World!  C++");
	//st.print();
	//cout << st.getLen() << endl;
	//cout << st.countWords() << endl;
	//st.clear();
	//st.input();
	//st.print();

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