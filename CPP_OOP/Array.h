#pragma once
#include<iostream>

#include"Func.h"

using namespace std;

class Array
{
	int* arr = nullptr;
	int size = 0;

public:
	Array(int s);

	~Array();

	void create(int s);

	void setRand(int minValue = 0, int maxValue = 9);

	void show();

	void add(int value);

	void remove(int index);

	void insert(int value, int index);

	void sort();

	void reverse();

	void clear();

	void resize(int newSize);

	void fill(int value);

	int getSize();

	int countValue(const int& value);

	int findValue(const int& value);

	int get(int index);

	void set(int index, int value);

	int getMax();

	int getMin();

	int getSum();

	double getAverage();

	bool contains(int value);
};

Array::Array(int s)
{
	create(s);
}

Array::~Array()
{
	delete[] arr;
}

void Array::create(int s)
{
	if (s < 0)
	{
		return;
	}
	size = s;
	arr = new int[size];
}

void Array::setRand(int minValue, int maxValue)
{
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % (maxValue - minValue + 1) + minValue;
	}
}

void Array::show()
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

void Array::add(int value)
{
	int* temp = new int[size + 1];
	for (int i = 0; i < size; i++)
	{
		temp[i] = arr[i];
	}
	temp[size] = value;
	delete[] arr;
	size++;
	arr = temp;
}

void Array::remove(int index)
{
	if (index < 0 || index >= size)
	{
		return;
	}
	int* temp = new int[size - 1];
	for (int i = 0; i < index; i++)
	{
		temp[i] = arr[i];
	}
	for (int i = index; i < size - 1; i++)
	{
		temp[i] = arr[i + 1];
	}
	delete[] arr;
	size--;
	arr = temp;
}

void Array::insert(int value, int index)
{
	if (index < 0 || index > size)
	{
		return;
	}
	int* temp = new int[size + 1];
	for (int i = 0; i < index; i++)
	{
		temp[i] = arr[i];
	}
	temp[index] = value;
	for (int i = index + 1; i <= size; i++)
	{
		temp[i] = arr[i - 1];
	}
	delete[] arr;
	size++;
	arr = temp;
}

void Array::sort()
{
	for (int j = 0; j < size - 1; j++)
	{
		for (int i = 0; i < size - 1 - j; i++)
		{
			if (arr[i] > arr[i + 1])
			{
				swap(arr[i], arr[i + 1]);
			}
		}
	}
}

void Array::reverse()
{
	for (int i = 0; i < size / 2; i++)
	{
		swap(arr[i], arr[size - 1 - i]);
	}
}

void Array::clear()
{
	delete[] arr;
	arr = nullptr;
	size = 0;
}

void Array::resize(int newSize)
{
	if (newSize < 0)
	{
		return;
	}
	int limit = (newSize < size) ? newSize : size;
	int* temp = new int[newSize];
	for (int i = 0; i < limit; i++)
	{
		temp[i] = arr[i];
	}
	delete[] arr;
	size = newSize;
	arr = temp;
}

void Array::fill(int value)
{
	for (int i = 0; i < size; i++)
	{
		arr[i] = value;
	}
}

int Array::getSize()
{
	return size;
}

int Array::countValue(const int& value)
{
	int countValue = 0;
	for (size_t i = 0; i < size; i++)
	{
		if (arr[i] == value)
		{
			countValue++;
		}
	}

	return countValue;
}

int Array::findValue(const int& value)
{
	for (int i = 0; i < size; i++)
	{
		if (arr[i] == value)
		{
			return i;
		}
	}

	return -1;
}

int Array::get(int index)
{
	if (index < 0 || index >= size)
	{
		return 0;
	}
	return arr[index];
}

void Array::set(int index, int value)
{
	if (index < 0 || index >= size)
	{
		return;
	}
	arr[index] = value;
}

int Array::getMax()
{
	if (size == 0)
	{
		return 0;
	}
	int maxVal = arr[0];
	for (int i = 1; i < size; i++)
	{
		if (maxVal < arr[i])
		{
			maxVal = arr[i];
		}
	}
	return maxVal;
}

int Array::getMin()
{
	if (size == 0)
	{
		return 0;
	}
	int minVal = arr[0];
	for (int i = 1; i < size; i++)
	{
		if (minVal > arr[i])
		{
			minVal = arr[i];
		}
	}
	return minVal;
}

int Array::getSum()
{
	int sum = 0;
	for (int i = 0; i < size; i++)
	{
		sum += arr[i];
	}
	return sum;
}

double Array::getAverage()
{
	if (size == 0)
	{
		return 0;
	}
	return (double)getSum() / size;
}

bool Array::contains(int value)
{
	for (int i = 0; i < size; i++)
	{
		if (arr[i] == value)
		{
			return true;
		}
	}
	return false;
}