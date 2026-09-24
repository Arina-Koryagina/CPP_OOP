#pragma once
#include<iostream>

#include"Array.h"
#include"String.h"

#define JOB 4

enum class Occupation
{
	Unknown, CEO, TeamLead, Engineer
};

const char* ReturnEnum(Occupation name)
{
	switch (name)
	{
	case Occupation::Unknown:  return "Unknown";
	case Occupation::CEO:      return "CEO";
	case Occupation::TeamLead: return "TeamLead";
	case Occupation::Engineer: return "Engineer";
	}
}

// Створіть клас Worker. Необхідно зберігати дані: ПІБ, посада, рік вступу на роботу, зарплата.
// Створити масив об’єктів. Вивести:
// - список працівників, стаж роботи яких на цьому підприємстві перевершує задане число років;
// - список працівників, зарплата яких перевищує задану;
// - список працівників, які займають задану посаду.
// Використовуйте explicit - конструктор і константні функції - члени.

class Worker
{
	String name;
	Occupation job;
	int year;
	double money;

	//const int id;

public:
	Worker();
	Worker(String name, Occupation job, int year, double money);

	void displayInfo();

	void setName(const char* FullName);

	void setJob(Occupation j);

	void setYear(int YearStarted);

	void setMoney(double Salary);

	String getName();

	String getJob();
	//Occupation getJob();

	int getYear();

	double getMoney();
};

Worker::Worker() : Worker("Unknown", Occupation::Unknown, 0, 0.) { }
Worker::Worker(String FullName, Occupation JobTitle, int YearStarted, double Salary)
{
	name = FullName;
	job = JobTitle;
	year = YearStarted;
	money = Salary;
}

void Worker::displayInfo()
{
	cout << "Full name: "; name.print();
	cout << "Job title: " << ReturnEnum(job) << endl;
	cout << "Year started: " << year << endl;
	cout << "Salary: " << money << endl;
}

void Worker::setName(const char* FullName)
{
	name = FullName;
}

// 1 - CEO, 2 - Team Lead, 3 - Engineer; 0 - Unknown
void Worker::setJob(Occupation j)
{
	job = j;
}

void Worker::setYear(int YearStarted)
{
	year = YearStarted;
}

void Worker::setMoney(double Salary)
{
	money = Salary;
}

String Worker::getName()
{
	return name;
}

String Worker::getJob()
{
	return ReturnEnum(job);
}
//Occupation Worker::getJob()
//{
//	return job;
//}

int Worker::getYear()
{
	return year;
}

double Worker::getMoney()
{
	return money;
}