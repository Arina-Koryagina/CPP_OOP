#pragma once
#include <iostream>

#include"String.h"

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
	Time(String s);

	String formTime() const;

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

Time::Time(String s) //s = "hh:mm:ss"
{
	hour   = int(s[0] - '0') * 10 + int(s[1] - '0');
	minute = int(s[3] - '0') * 10 + int(s[4] - '0');
	second = int(s[6] - '0') * 10 + int(s[7] - '0');
}

String Time::formTime() const
{
	String time(8);  time = "";
	if (hour < 10)   time += "0";
	time += hour;    time += ":";
	if (minute < 10) time += "0";
	time += minute;  time += ":";
	if (second < 10) time += "0";
	time += int(second);

	return time;
}

ostream& operator<<(ostream& out, const Time& obj)
{
	if (obj.hour) { out << obj.hour << "h "; }
	if (obj.minute) { out << obj.minute << "m "; }
	if (obj.second) { out << obj.second << "s"; }
	return out;
}