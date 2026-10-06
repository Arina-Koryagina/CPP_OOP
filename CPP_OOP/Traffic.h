#pragma once
#include <conio.h>
#include<Windows.h>

#include"String.h"
#include"PriorityQueue.h"
#include"Queue.h"
#include"Time.h"

enum Color
{
	Black = 0, Blue = 1, Green = 2, Cyan = 3, Red = 4, Magenta = 5, Brown = 6, LightGray = 7, DarkGray = 8,
	LightBlue = 9, LightGreen = 10, LightCyan = 11, LightRed = 12, LightMagenta = 13, Yellow = 14, White = 15
};

void SetColor(int text, int background)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (WORD)((background << 4) | text));
}

#define maxNum 89
#define minNum 13
#define maxSeat 10
#define minSeat 0

class Bus
{
	int number;
	int freeSeats;

public:
	Bus();
	Bus(int n, int free);

	int getSeats() const;
	void setSeats();

	static Bus newBus();
	friend ostream& operator<<(ostream& out, const Bus& obj);
};

Bus::Bus() : Bus(0, 0) {}
Bus::Bus(int num, int free)
{
	number = num;
	freeSeats = free;
}

int Bus::getSeats() const
{
	return freeSeats;
}

void Bus::setSeats()
{
	freeSeats = rand() % (maxSeat - minSeat + 1) + minSeat;
}

Bus Bus::newBus()
{
	int num = rand() % (maxNum - minNum + 1) + minNum;
	int free = rand() % (maxSeat - minSeat + 1) + minSeat;
	return Bus(num, free);
}

ostream& operator<<(ostream& out, const Bus& obj)
{
	SetColor(LightGray, Black);
	cout << "Number: " << obj.number << ", free seats: ";
	SetColor(White, Black);
	cout << obj.freeSeats;
	return out;
}


class People
{
	int priority;

public:
	People();
	People(int pri);
};

People::People() : People(0) {}
People::People(int pri)
{
	priority = pri;
}


class Station
{
	int waiting = 0;
	int departed = 0;
	int waitingTime = 0;

public:

	Station();
	Station(int wait, int depart, int waitT);

	Time getAvgWaitT() const;

	void simulate();
	void simulate(int tPass, int tBus, int N);
};

Station::Station() : Station(0, 0, 0) {}
Station::Station(int wait, int depart, int waitT)
{
	waiting = wait;
	departed = depart;
	waitingTime = waitT;
}

Time Station::getAvgWaitT() const
{
	return Time(((100 * waitingTime) / departed)/100.); // rounding to the nearest hundredth
}

void Station::simulate()
{
	int tPass, tBus, N;
	cout << "Enter next values\n";
	cout << "Average time for a new passenger to arrive: "; cin >> tPass;
	cout << "Average time for a new bus to arrive: "; cin >> tBus;
	cout << "Maximum amount of passengers waiting: "; cin >> N;
	simulate(tPass, tBus, N);
}

void Station::simulate(int tPass, int tBus, int N)
{
	int buses = 5;
	Queue<Bus> bus;
	for (int i = 0; i < buses; i++)
	{
		bus.enqueue(Bus::newBus());
	}
	Queue<People> p;
	system("cls");
	SetColor(LightBlue, Black);
	cout << "Press Space to stop the simulation from running.\n";
	SetColor(White, Black);
	
	SetColor(LightGreen, Black);
	cout << "Total buses on the route: ";
	SetColor(White, Black);
	cout << buses << endl;

	int circle = buses * tBus;

	int i = 0, waiting = 0, nextBus;
	bool newBus = false;
	while (true)
	{
		if (_kbhit())
		{
			if (_getch() == ' ')
			{
				cout << "Total passengers departed: " << departed << endl;
				cout << "Total time simulated: " << i << endl;
				cout << "Average waiting time: " << getAvgWaitT() << endl;
				break;
			}
		}

		if (waiting > N && newBus == false)
		{
			newBus = true;
			bus.enqueue(Bus::newBus());
			buses++;
			tBus = circle / buses;
			SetColor(LightGreen, Black);
			cout << "New bus added on the route. Total: ";
			SetColor(White, Black);
			cout << buses << endl;
		}

		if (i % 10 == 0)
		{
			SetColor(LightGray, Black);
			cout << "Time: " << i << " s\n";
			SetColor(White, Black);
		}

		if (i % tPass == 0)
		{
			SetColor(DarkGray, Black);
			cout << "Passenger arrived\n";
			SetColor(White, Black);
			p.enqueue(People());
			waiting++;
		}

		if (i > 0)
		{
			if (i % nextBus == 0)
			{
				SetColor(LightGreen, Black);
				cout << "Bus arrived\n";
				newBus = false;
				SetColor(White, Black);

				Bus& b = bus.peek();
				cout << b << endl;
				int seats = b.getSeats();
				int taken = (seats < waiting) ? seats : waiting;
				for (int i = 0; i < taken; i++)
				{
					p.dequeue();
				}
				b.setSeats();

				bus.ring();
				waiting -= taken;
				departed += taken;
			}
		}

		waiting = p.getSize();
		waitingTime += waiting;
		nextBus = tBus;

		SetColor(LightRed, Black);
		cout << "Passengers waiting: ";
		SetColor(White, Black);
		cout << waiting << endl;

		Sleep(1000);
		i++;
	}
}
