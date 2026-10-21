#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

#include"Pet.h"
#include"String.h"

using namespace std;

int main()
{
	BinString b("10");
	b.print();
	BinString s("11");
	s.print();
	BinString bn;

	bn = b;
	bn.print();
	bn = b + s;
	bn.print();
	bn += b;
	bn.print();

	if (b == s)
	{
		cout << "equal" << endl;
	}
	else
	{
		cout << "not equal" << endl;
	}


	return 0;
}