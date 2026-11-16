#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <limits>

#include"Time.h"
#include"Func.h"

//#define DEBUG

using namespace std;

// Написати програму «Автоматизована інформаційна система залізничного вокзалу».
// Система містить: відомості про відправлення поїздів далекого прямування.
// Для кожного поїзда вказуємо: номер, час відправлення, станцію призначення.
// Забезпечити:
//	■ Введення даних в систему;
//  ■ Виведення інформації про всі поїзди;
//  ■ Виведення інформації про запитувані поїзди.
// Використовувати контейнерний клас vector.

class Train
{
	size_t line_number;
	Time   depart_time;
	string end_station;
public:
	Train(size_t line, Time time, string station) : line_number(line), depart_time(time), end_station(station) {}

	size_t getLine() const { return line_number; }
	Time   getTime() const { return depart_time; }
	string getStat() const { return end_station; }

	friend ostream& operator<<(ostream& out, const Train& obj);
};

ostream& operator<<(ostream& out, const Train& obj)
{
	out << "Train No." << obj.line_number << " departs to " << obj.end_station << " at " << obj.depart_time;
	return out;
}

class RailwayStation
{
	vector<Train> routes;

public:
	void addRoute();
	void addRoute(size_t line, Time time, string station);

	void showRoutes();
	void showRoutesIf();

	void menu()
	{
#ifdef DEBUG
		routes.emplace_back(size_t(14), Time(string("10:27")), "Kyiv");
		routes.emplace_back(size_t(42), Time(string("18:30")), "Berlin");
		routes.emplace_back(size_t(79), Time(string("17:05")), "Prague");
		routes.emplace_back(size_t(81), Time(string("14:12")), "Vienna");
		routes.emplace_back(size_t(42), Time(string("19:45")), "Paris");
#endif

		while (true)
		{
			int choice;
			system("cls");
			cout << "========   STATION  MENU   ========\n"
				"1. Add route\n"
				"2. Show all routes\n"
				"3. Show by information\n"
				"0. Exit\n"
				"Choose : "; cin >> choice; cin.ignore();

			switch (choice)
			{
			case 1:
				addRoute();
				break;
			case 2:
				system("cls");
				cout << "========   ROUTES   LIST   ========\n";
				showRoutes();
				break;
			case 3:
				showRoutesIf();
				system("pause");
				break;
			case 0:
				SetColor(LightRed, Black);
				cout << "Exit\n";
				SetColor(White, Black);
				exit(0);
			default:
				cout << "Invalid input.\n";
				system("pause");
				break;
			}
		}
	}
};

void RailwayStation::addRoute()
{
	size_t num; string time, stat;
	system("cls");
	cout << "========   ADD  A  ROUTE   ========\n";

	cout << "Enter train's number        : "; cin >> num; cin.ignore();
	cout << "Enter destination           : "; getline(cin, stat);
	cout << "Enter departure time (00:00): "; getline(cin, time);

	addRoute(num, Time(time), stat);
}
void RailwayStation::addRoute(size_t line, Time time, string station)
{
	routes.emplace_back(line, time, station);
}

void RailwayStation::showRoutes()
{
	for (Train& elem : routes)
	{
		cout << elem << endl;
	}
	system("pause");
}

void RailwayStation::showRoutesIf()
{
	int choice;
	cout << "1. Train number\n"
			"2. Destination\n"
			"3. Departure time\n"
			"What kind of routes would you like to find? ";
	cin >> choice; cin.ignore();
	
	system("cls");
	cout << "========   ROUTES   LIST   ========\n";
	switch (choice)
	{
	case 1:
	{
		size_t num;
		cout << "Enter train number: ";
		cin >> num;

		for (const Train& elem : routes)
		{
			if (elem.getLine() == num)
			{
				cout << elem << endl;
			}
		}

		break;
	}
	case 2:
	{
		string station;
		cout << "Enter destination: ";
		getline(cin, station);

		for (const Train& elem : routes)
		{
			if (elem.getStat() == station)
			{
				cout << elem << endl;
			}
		}

		break;
	}
	case 3:
	{
		string time;
		cout << "Enter departure time: ";
		getline(cin, time);

		for (const Train& elem : routes)
		{
			if (elem.getTime() == Time(time))
			{
				cout << elem << endl;
			}
		}

		break;
	}
	default:
		break;
	}
}
