#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

//#include"WarOfWorld.h"
#include"Animal.h"

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

int main()
{
	

	
	//WarOfWorld war(3, 5);
	//war.game();

	return 0;
}