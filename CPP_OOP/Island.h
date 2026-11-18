#pragma once
#include <iostream>
#include <conio.h>

#include"Func.h"
#include"String.h"
#include"Array.h"
#include"List.h"

#define SIDE 20

enum Sex
{
	Male, Female
};

namespace func
{
	int rand()
	{
		return (std::rand() % 3) - 1;
	}
};

class IPrintable
{
public:
	virtual void print() const = 0;
};

class Rabit : public IPrintable
{
	int x;
	int y;

public:
	Rabit(int x, int y) : x(x), y(y) {};

	int getX() const
	{
		return x;
	}
	int getY() const
	{
		return y;
	}

	void move()
	{
		if (std::rand() % 9 == 0)
		{
			if (func::rand() < 0 && x > 0)
			{
				x--;
			}
			else if (func::rand() > 0 && x < SIDE - 1)
			{
				x++;
			}
			if (func::rand() < 0 && y > 0)
			{
				y--;
			}
			else if (func::rand() > 0 && y < SIDE - 1)
			{
				y++;
			}
		}
	}

	void multiply(List<Rabit*>* rabits)
	{
		if (std::rand()%5==0)
		{
			bool x_axis = false, y_axis = false;
			int newX = x, newY = y;
			do
			{
				if (std::rand() % 2 == 0 && newX > 0)
				{
					newX--; x_axis = true;
				}
				else if (std::rand() % 2 == 1 && newX < SIDE - 1)
				{
					newX++; x_axis = true;
				}
				if (std::rand() % 2 == 0 && newY > 0)
				{
					newY--; y_axis = true;
				}
				else if (std::rand() % 2 == 1 && newY < SIDE - 1)
				{
					newY++; y_axis = true;
				}
			} while (!x_axis || !y_axis);
			rabits->push_back(new Rabit(newX, newY));
		}
	}

	virtual void print() const final override
	{
		SetColor(LightGreen, Black);
		cout << "r";
	}
};

class Wolf : public IPrintable
{
	Sex    sex;
	size_t score = 1;
	int x;
	int y;

public:
	Wolf(Sex s, int x, int y) : sex(s), x(x), y(y) {};

	int getX() const
	{
		return x;
	}
	int getY() const
	{
		return y;
	}

	void eat(List<Rabit*>* rabits, size_t ind)
	{
		rabits->remove(ind);
		score++;
	}
	void noEat()
	{
		score -= 0.1;
	}

	void move()
	{
		bool x_axis = false, y_axis = false;
		do
		{
			if (std::rand() % 2 == 0 && x > 0)
			{
				x--; x_axis = true;
			}
			else if (std::rand() % 2 == 1 && x < SIDE - 1)
			{
				x++; x_axis = true;
			}
			if (std::rand() % 2 == 0 && y > 0)
			{
				y--; y_axis = true;
			}
			else if (std::rand() % 2 == 1 && y < SIDE - 1)
			{
				y++; y_axis = true;
			}
		}while (!x_axis || !y_axis);
	}

	virtual void print() const override
	{
		cout << "W";
	}
};

class MaleWolf : public Wolf
{
public:
	MaleWolf(int x, int y) : Wolf(Male, x, y) {};

	virtual void print() const final override
	{
		SetColor(LightBlue, Black);
		Wolf::print();
	}
};

class FemaleWolf : public Wolf
{
public:
	FemaleWolf(int x, int y) : Wolf(Female, x, y) {};

	virtual void print() const final override
	{
		SetColor(LightRed, Black);
		Wolf::print();
	}
};

class Island
{
	int side;
	List<Rabit*> rabits;
	List<MaleWolf*> males;
	List<FemaleWolf*> females;

public:
	Island(int size = SIDE, int rab = 5, int male = 2, int fem = 2) : side(size)
	{
		int creatures = rab + male + fem;
		int x, y; String position = "";
		Array<String> pos;
		Array<int> xs, ys;
		for (int i = 0; i < creatures; i++)
		{
			do
			{
				x = std::rand() % side;
				y = std::rand() % side;
				position += x;
				position += y;
			} while (pos.contains(position));
			xs.add(x);
			ys.add(y);
			pos.add(position);
		}

		for (int i = 0; i < rab; i++)
		{
			rabits.push_back(new Rabit(xs[i], ys[i]));
		}
		for (int i = rab; i < rab+male; i++)
		{
			males.push_back(new MaleWolf(xs[i], ys[i]));
		}
		for (int i = rab+male; i < creatures; i++)
		{
			females.push_back(new FemaleWolf(xs[i], ys[i]));
		}
	};

	void print() const
	{
		for (size_t j = 0; j < side; j++)
		{
			for (size_t i = 0; i < side; i++)
			{
				SetColor(LightGray, Black);
				cout << "C ";
			}
			cout << endl;
		}
		int rab = rabits.getSize(), male = males.getSize(), fem = females.getSize();
		for (int i = 0; i < rab; i++)
		{
			int x = rabits[i]->getX();
			int y = rabits[i]->getY();
			SetCursor(x*2, y);
			rabits[i]->print();
		}
		for (int i = 0; i < male; i++)
		{
			int x = males[i]->getX();
			int y = males[i]->getY();
			SetCursor(x*2, y);
			males[i]->print();
		}
		for (int i = 0; i < fem; i++)
		{
			int x = females[i]->getX();
			int y = females[i]->getY();
			SetCursor(x*2, y);
			females[i]->print();
		}

		SetCursor(side*2+5, 0); SetColor(White, Black);
		cout << "       Rabits: "; SetColor(LightGreen, Black);
		cout << rabits.getSize() << endl;
		SetCursor(side*2+5, 1); SetColor(White, Black);
		cout << "  Male Wolves: "; SetColor(LightBlue, Black);
		cout << males.getSize() << endl;
		SetCursor(side*2+5, 2); SetColor(White, Black);
		cout << "Female Wolves: "; SetColor(LightRed, Black);
		cout << females.getSize() << endl; SetColor(White, Black);
		SetCursor(0, 25);
	}

	void simulate()
	{
		system("cls");

		while (true)
		{
			if (_kbhit())
			{
				if (_getch() == ' ')
				{
					break;
				}
			}
			SetCursor(0, 0);
			print();
			rabits[0]->move();
			rabits[0]->multiply(&rabits);
			rabits[1]->move();
			rabits[1]->multiply(&rabits);
			rabits[2]->move();
			rabits[2]->multiply(&rabits);
			rabits[3]->move();
			rabits[3]->multiply(&rabits);
			rabits[4]->move();
			rabits[4]->multiply(&rabits);
			males[0]->move();
			males[1]->move();
			females[0]->move();
			females[1]->move();
			Sleep(1000);
		}
	}
};