#pragma once
#include<iostream>

#include"String.h"

#define JOB 4

enum class Occupation
{
	Unknown, CEO, TeamLead, ProjectManager, SoftwareEngineer, QAEngineer, UIUXDesigner, HRManager, Accountant, SalesManager, MarketingManager
};
const char* ReturnEnum(Occupation name)
{
	switch (name)
	{
	case Occupation::Unknown:          return "Unknown"; break;
	case Occupation::CEO:              return "CEO"; break;
	case Occupation::TeamLead:         return "Team Lead"; break;
	case Occupation::ProjectManager:   return "Project Manager"; break;
	case Occupation::SoftwareEngineer: return "Software Engineer"; break;
	case Occupation::QAEngineer:       return "QA Engineer"; break;
	case Occupation::UIUXDesigner:     return "UI/UX Designer"; break;
	case Occupation::HRManager:        return "HR Manager"; break;
	case Occupation::Accountant:       return "Accountant"; break;
	case Occupation::SalesManager:     return "Sales Manager"; break;
	case Occupation::MarketingManager: return "Marketing Manager"; break;
	default:                           return "Unknown"; break;
	}
}

class Worker
{
	int id;
	String name;
	Occupation job;
	int year;
	double money;

	//const int id;

public:
	Worker();
	explicit Worker(int id);
	Worker(int id, String name, Occupation job, int year, double money);

	Worker& operator=(const Worker& obj);

	void displayInfo() const;

	void setName(const char* FullName);

	void setJob(Occupation j);

	void setYear(int YearStarted);

	void setMoney(double Salary);

	int getID() const;

	const String& getName() const;

	Occupation getJob() const;

	int getYear() const;

	double getMoney() const;

	void setRand();
};

Worker::Worker() : Worker(0, "Unknown", Occupation::Unknown, 0, 0.) { }
Worker::Worker(int id) : Worker(id, "Unknown", Occupation::Unknown, 0, 0.) { }
Worker::Worker(int id, String FullName, Occupation JobTitle, int YearStarted, double Salary) : id{id}
{
	name = FullName;
	job = JobTitle;
	year = YearStarted;
	money = Salary;
}

Worker& Worker::operator=(const Worker& obj)
{
	if (this == &obj)
	{
		return *this;
	}

	id = obj.id;
	name = obj.name;
	job = obj.job;
	year = obj.year;
	money = obj.money;

	return *this;
}

void Worker::displayInfo() const
{
	cout << "ID: " << id << endl;
	cout << "Full name: "; name.print();
	cout << "Job title: " << ReturnEnum(job) << endl;
	cout << "Year started: " << year << endl;
	cout << "Salary: " << money << " USD a month.\n\n";
}

void Worker::setName(const char* FullName)
{
	name = FullName;
}

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

int Worker::getID() const
{
	return id;
}

const String& Worker::getName() const
{
	return name;
}

Occupation Worker::getJob() const
{
	return job;
}

int Worker::getYear() const
{
	return year;
}

double Worker::getMoney() const
{
	return money;
}

int Random(int minValue, int maxValue)
{
	return rand() % (maxValue - minValue + 1) + minValue;
}

void Worker::setRand()
{
	String names[] {"John", "Mary", "Brian", "Stefan", "Kate", "Cody", "Helen"};
	String surnames[] {"Smith", "Jane", "Molko", "Olsdal", "Bush", "Armstrong", "Berg"};
	name = names[Random(0, 6)] + " " + surnames[Random(0, 6)];
	setJob(Occupation(Random(1, 10)));
	year = Random(1965, 2025);
	money = Random(35, 130) * 100;
}