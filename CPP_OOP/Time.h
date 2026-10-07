#pragma once
#include <iostream>

using namespace std;
class Time
{
	int hour;
	int minute;
	double second;

public:
	Time();
	Time(double s);
	Time(int m, double s);
	Time(int h, int m, double s);

	friend ostream& operator<<(ostream& out, const Time& obj);

};

Time::Time() : Time(0) {}
Time::Time(double s) : Time(0, s) {}
Time::Time(int m, double s) : Time(0, m, s) {}
Time::Time(int h, int m, double s)
{
	if (s > 0 && int(s) / 60 > 0)
	{
		m += s / 60;
		s -= m * 60;
		if (m > 0 && m / 60 > 0)
		{
			h += m / 60;
			m -= h * 60;
		}
	}
	hour = h;
	minute = m;
	second = s;
}

ostream& operator<<(ostream& out, const Time& obj)
{
	if (obj.hour) { cout << obj.hour << "h "; }
	if (obj.minute) { cout << obj.minute << "m "; }
	if (obj.second) { cout << obj.second << "s"; }
	return out;
}