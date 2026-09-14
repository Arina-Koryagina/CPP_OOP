#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

#include"Student.h"

using namespace std;


int main()
{
	Student s1;
	Student s2("Vasya", 30);
	//s1.setName("John");
	//s1.setAge(20);
	s2.setMark(5);

	s1.displayInfo();
	s2.displayInfo();

	return 0;
}