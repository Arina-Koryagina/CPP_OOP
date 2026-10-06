#pragma once
#include <iostream>

using namespace std;
class Time
{
	int hour;
	int minute;
	double second;

public:
	Time() : Time(0) {}
	Time(double s) : Time(0, s) {}
	Time(int m, double s) : Time(0, m, s) {}
	Time(int h, int m, double s) : hour(h), minute(m), second(s) {}

	double getSeconds() const;

	friend ostream& operator<<(ostream& out, const Time& obj);

};

double Time::getSeconds() const
{
	return second;
}

ostream& operator<<(ostream& out, const Time& obj)
{
	if (obj.minute)
	{
		if (obj.hour)
		{
			cout << obj.hour << "h ";
		}
		cout << obj.minute << "m ";
	}
	cout << obj.second << "s";
	return out;
}