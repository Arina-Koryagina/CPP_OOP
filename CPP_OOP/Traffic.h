#pragma once
#include<conio.h>
#include<Windows.h>

#include"String.h"
//#include"PriorityQueue.h"
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

// Створити імітаційну модель «зупинка маршрутних таксі».
// Необхідно вводити наступну інформацію: середній час між появою пасажирів/маршруток на зупинці.
// Необхідно визначити: середній час перебування людини на зупинці,
// достатній інтервал часу між приїздом маршруток, щоб на зупинці перебувало не більше N людей одночасно.
// Кількість вільних місць в маршрутці є випадковою величиною.

#define N 10
#define BUS 5
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

	double getAvgWaitT() const;

	void simulate();
	void simulate(int tPass, int tBus);
};

Station::Station() : Station(0, 0, 0) {}
Station::Station(int wait, int depart, int waitT)
{
	waiting = wait;
	departed = depart;
	waitingTime = waitT;
}

double Station::getAvgWaitT() const
{
	return double(waitingTime) / (departed + waiting);
}

void Station::simulate()
{
	int tPass, tBus;
	SetColor(LightBlue, Black);
	cout << "Enter next values to start simulation\n";
	SetColor(White, Black);
	cout << "Average time for a new passenger to arrive: "; cin >> tPass;
	cout << "Average time for a new bus to arrive: "; cin >> tBus;
	simulate(tPass, tBus);
}

void Station::simulate(int tPass, int tBus)
{
	int buses = BUS;
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
	SetColor(LightRed, Black);
	cout << "Passenger queue size limit: ";
	SetColor(White, Black);
	cout << N << endl;
	cout << endl;
	SetColor(LightGray, Black);
	cout << "Time: 0s\n";

	int circle = buses * tBus;

	int i = 0, nextBus = tBus, emptyCount = 0, queuePrediction;
	bool newBus = false;
	while (true)
	{
		if (_kbhit())
		{
			if (_getch() == ' ')
			{
				double t = int(round(100 * getAvgWaitT())) / 100.; // rounding to the nearest hundredth
				Time avgWaitT = Time(t);
				cout << "Total time simulated             : " << Time(i) << endl;
				cout << "Average waiting time (passenger) : " << avgWaitT << endl;
				cout << "Bus arrival span (at the moment) : " << Time(tBus) << endl;
				break;
			}
		}


		if (i > 0)
		{
			if (i % 10 == 0)
			{
				cout << endl;
				SetColor(LightGray, Black);
				cout << "Time: " << Time(i) << endl;
				SetColor(White, Black);
			}

			if (i % tPass == 0)
			{
				SetColor(DarkGray, Black);
				cout << "Passenger arrived\n";
				SetColor(White, Black);
				p.enqueue(People());
				waiting++;
				SetColor(LightRed, Black);
				cout << "Passengers waiting: ";
				SetColor(White, Black);
				cout << waiting << endl;
			}
			 
			queuePrediction = waiting + tBus / tPass;
			if (queuePrediction - bus.peek().getSeats() >= N)
			{
				if (!newBus)
				{
					newBus = true;
					bus.enqueue(Bus::newBus());
					buses++;
					tBus = circle / buses; //reschedule
					nextBus = i;
					SetColor(LightGreen, Black);
					cout << Time(i) << ": New bus added on the route. Total: ";
					SetColor(White, Black);
					cout << buses << endl;
				}
			}
			else
			{
				if (emptyCount == 3 && bus.getSize() > 1)
				{
					emptyCount = 0;
					bus.dequeue();
					buses--;
					nextBus -= tBus;
					tBus = circle / buses;
					nextBus += tBus;
					SetColor(LightGreen, Black);
					cout << Time(i) << ": A bus taken off the route. Total: ";
					SetColor(White, Black);
					cout << buses << endl;
				}
			}

			if (i == nextBus)
			{
				SetColor(LightGreen, Black);
				cout << "\nBus arrived at " << Time(i) << endl;
				newBus = false;
				nextBus += tBus;
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

				SetColor(LightRed, Black);
				cout << "Left at the station: ";
				SetColor(White, Black);
				cout << waiting << endl;
				cout << endl;
				(waiting == 0) ? emptyCount++ : emptyCount = 0;
			}
		}

		waitingTime += waiting;
		Sleep(1000);
		i++;
	}
}
