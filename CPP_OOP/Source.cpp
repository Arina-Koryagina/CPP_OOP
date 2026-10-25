#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

#include"String.h"
#include"FileHandler.h"

using namespace std;

int main()
{
	String path = "The Little Prince.txt";
	BinFile f(path);
	f.display();

	ASCIIFile ascii(path);
	File& file = ascii;
	file.display();

	File TLP(path);
	TLP.display();

	return 0;
}