#pragma once
#include<iostream>
#include <cmath>

#define RAD_CONVERT (3.141592653589793 / 180)

class AreaCalc
{
	static int count;

public:

	// Клас повинен надавати функціональність для підрахунку
	// площі трикутника за різними формулами, площі прямокутника,
	// площі квадрата, площі ромба.Функції - члени для
	// підрахунку площі повинні бути реалізовані за допомогою
	// статичних функцій - членів.Також клас повинен читати
	// кількість підрахунків площі і повертати це значення за
	// допомогою статичної функції - члена.

	static double triangle(double a);
	static double triangle(double a, double hA);
	static double triangle(double a, double b, double deg);
	static double semiperimeter(double a, double b, double c);
	static double triangle(double a, double b, double c, double p);

	static double rectangle(double a, double b);

	static double square(double a);
	
	static double rhombus(double d1, double d2);

	static int getCount();
};

int AreaCalc::count = 0;

// Сторона (для правильного трикутника)
double AreaCalc::triangle(double a)
{
	count++;
	return (a * a * sqrt(3))/4;
}
// Сторона і висота, проведену до неї
double AreaCalc::triangle(double a, double hA)
{
	count++;
	return 0.5 * a * hA;
}
// Дві сторони і кут між ними
double AreaCalc::triangle(double a, double b, double deg)
{
	count++;
	return 0.5 * a * b * sin(deg * RAD_CONVERT);
}
double AreaCalc::semiperimeter(double a, double b, double c)
{
	return (a + b + c) / 2;
}
// Три сторони і півпериметр (semiperimeter)
double AreaCalc::triangle(double a, double b, double c, double p)
{
	count++;
	return sqrt(p * (p - a) * (p - b) * (p - c));
}
// Довжина і ширина
double AreaCalc::rectangle(double a, double b)
{
	count++;
	return a * b;
}
// Сторона
double AreaCalc::square(double a)
{
	return rectangle(a, a);
}
// Дві діагоналі
double AreaCalc::rhombus(double d1, double d2)
{
	count++;
	return 0.5 * d1 * d2;
}

int AreaCalc::getCount()
{
	return count;
}