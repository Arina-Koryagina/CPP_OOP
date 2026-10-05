#pragma once
#include<iostream>

#include"Stack.h"


using namespace std;

class Calc
{
	string expression;

	int isoperation(char oper);
	int calculate(int a, int b, char oper);

public:
	Calc(const string& exp) : expression(exp) {}

	int getResult();
};

int Calc::isoperation(char oper)
{
	switch (oper)
	{
	case '+': case '-': return 1;
	case '*': case '/': return 2;
	case '^':           return 3;
	default:            return 0;
	}
}

int Calc::calculate(int a, int b, char oper)
{
	switch (oper)
	{
	case '+': return a + b;
	case '-': return b - a;
	case '*': return a * b;
	case '/': return b / a;
	case '^': return pow(b, a);
	}
}

int Calc::getResult()
{
	Stack<int, 10> numbers;
	Stack<char, 10> operators;

	int i = 0;
	char exp = expression[i];
	while (exp != '\0')
	{
		if (isdigit(exp)) { numbers.push(exp - 48); }
		else if (isoperation(exp))
		{
			if (operators.IsEmpty() || isoperation(operators.peek()) <= isoperation(exp))
			{
				operators.push(exp);
			}
			else if (isoperation(operators.peek()) > isoperation(exp))
			{
				while (isoperation(operators.peek()) > isoperation(exp))
				{
					int a = numbers.peek(); numbers.pop();
					int b = numbers.peek(); numbers.pop();
					char oper = operators.peek(); operators.pop();
					numbers.push(calculate(a, b, oper));
				}
				operators.push(exp);
			}
		}
		i++;
		exp = expression[i];
	}

	while (!operators.IsEmpty())
	{
		int a = numbers.peek(); numbers.pop();
		int b = numbers.peek(); numbers.pop();
		char oper = operators.peek(); operators.pop();
		numbers.push(calculate(a, b, oper));
	}

	return numbers.peek();
}