#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<Windows.h>

#include"WarOfWorld.h"

using namespace std;

int main()
{
	SetConsoleTitleA("DnD Style Combat");
	srand(time(0));

	WarOfWorld battle(6);
	battle.game();

	return 0;
}