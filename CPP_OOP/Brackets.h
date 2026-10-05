#pragma once
#include<iostream>

#include"Stack.h"
#include"String.h"


using namespace std;

class Brackets
{
	String expression;

	int isbracket(char oper);

public:
	Brackets(const String& exp) : expression(exp) {}

	void check();
};

int Brackets::isbracket(char oper)
{
	switch (oper)
	{
	case'(': return -3;
	case'{': return -2;
	case'[': return -1;
	case']': return 1;
	case'}': return 2;
	case')': return 3;
	default: return 0;
	}
}

void Brackets::check()
{
	Stack<int, 10> brackets;
	Stack<int, 10> inds;
	bool error = false;
	int i = 0, iError = -1;

	while (expression[i] != ';')
	{
		int br = isbracket(expression[i]);
		if (br < 0)
		{
			brackets.push(br);
			inds.push(i);
		}
		else if (br > 0)
		{
			if (brackets.IsEmpty() || -br != brackets.peek())
			{
				error = true;
				iError = i;
				break;
			}
			else
			{
				brackets.pop();
				inds.pop();
			}
		}
		i++;
	}
	if (!error && !brackets.IsEmpty())
	{
		error = true;
		iError = inds.peek();
	}

	if (error)
	{
		for (size_t i = 0; i <= iError; i++)
		{
			cout << expression[i];
		}
		cout << " <- error\n";
	}
	else
	{
		cout << "The expression is written correctly.\n";
	}
}