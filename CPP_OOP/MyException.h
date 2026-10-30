#pragma once
#include<iostream>
#include<fstream>

using namespace std;

class MyException
{
	int    line;
	string file;
	string date;
	string time;
	string msg;

public:
	MyException(string d, string t, string f, int l, string m) : date(d), time(t), file(f), line(l), msg(m)
	{

	}

	void getConsoleError()
	{
		cerr << date << " | " << time << " | " << file << " | " << line << " | " << msg << endl;
	}

	void saveToFile()
	{
		ofstream out("log.txt", ios::app);
		out << date << ";" << time << ";" << file << ";" << line << ";" << msg << endl;
		out.close();
	}
};