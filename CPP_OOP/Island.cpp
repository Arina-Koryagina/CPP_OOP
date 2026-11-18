#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

#include"Island.h"

int main()
{
	srand(time(0));

	Island isl;
	isl.simulate();

	return 0;
}