#pragma once

#include"Time.h"
#include"String.h"

class Date
{
	int day;
	int month;
	int year;
	Time time;

public:
	Date();
	Date(int d, int m, int y, Time t);
	Date(String s);

	String formDate() const;

	friend ostream& operator<<(ostream& out, const Date& obj);
};

Date::Date() : Date(0, 0, 0, 0) {}

Date::Date(int d, int m, int y, Time t)
{
	day = d;
	month = m;
	year = y;
	time = t;
}

Date::Date(String s) //s = "yyyy-mm-dd Time"
{
	year  = int(s[0] - '0') * 1000 + int(s[1] - '0') * 100 + int(s[2] - '0') * 10 + int(s[3] - '0');
	month = int(s[5] - '0') * 10 + int(s[6] - '0');
	day   = int(s[8] - '0') * 10 + int(s[9] - '0');
	char t[8]; for (int i = 0; i < 8; i++) t[i] = s[i + 11];
	time = Time(t);
}

String Date::formDate() const
{
	String date(20); date = "";
	date += year;    date += "-";
	if (month < 10)  date += "0";
	date += month;   date += "-";
	if (day < 10)    date += "0";
	date += day;     date += " ";
	date += time.formTime();

	return date;
}

ostream& operator<<(ostream& out, const Date& obj)
{
	out << obj.formDate();
	return out;
}