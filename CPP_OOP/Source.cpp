#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

#include"String.h"
#include"Animal.h"

using namespace std;

int main()
{
	Animal* c = new Kitten("Gerard", 8);
	cout << c->getType() << endl;
	delete c;

	//Animal& a = c;
	//cout << a.getType() << endl;
	//Animal* aa = &c;
	//cout << aa->getType() << endl;
	//Animal* c = new Kitten("Gerard", 8);
	//cout << c->getType() << endl;
	//Animal* a = c;
	//cout << a->getType() << endl;


	//Animal* a = new Animal("No name", 0);
	//cout << a->getName() << endl;
	//cout << a->getType() << endl;
	//cout << a->getVoice() << endl;
	//cout << endl;

	//Animal* c = new Kitten("Gerard", 8);
	//cout << c->getName() << endl;
	//cout << c->getType() << endl;
	//cout << c->getVoice() << endl;
	//cout << endl;

	//Animal* d = new Puppy("Frank", 6);
	//cout << d->getName() << endl;
	//cout << d->getType() << endl;
	//cout << d->getVoice() << endl;
	//cout << endl;

	//Animal* w = new BritishKitten("William", 1);

	//Animal* aa[] = { c, d, w, new Snail("Gary", 1)};
	//for (size_t i = 0; i < 4; i++)
	//{
	//	cout << aa[i]->getType() << endl;
	//	cout << aa[i]->getName() << endl;
	//	cout << aa[i]->getVoice() << endl;
	//	cout << endl;
	//}


	//Router r(123, 456, 789, 999);
	//cout << r.LANDevice::getID() << endl;

	//r.LANDevice::Device::id = 10;
	//cout << r.LANDevice::Device::id << endl;
	//cout << r.WiFiDevice::Device::id << endl;
	//r.WiFiDevice::Device::id = 20;
	//cout << r.LANDevice::Device::id << endl;
	//cout << r.WiFiDevice::Device::id << endl;


	return 0;
}