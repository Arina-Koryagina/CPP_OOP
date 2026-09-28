#pragma once
#include<iostream>
#include<cassert>

using namespace std;

#include"Fraction.h"

template<class T>
class Array
{
	T* arr = nullptr;
	int size = 0;

public:

	Array();

	explicit Array(int s);

	Array(const Array& obj);

	Array& operator=(const Array& obj);

	~Array();

	void create(int s);

	bool IsEmpty() const;

	void setRand() const;

	void show() const;

	void add(int value);

	void remove(int index);

	void insert(const T& value, int index);

	void sort() const;

	void reverse() const;

	void clear();

	void resize(int newSize);

	void setSize(int s, int grow);

	void fill(const T& value) const;

	int getSize() const;

	int countValue(const T& value) const;

	int findValue(const T& value) const;

	T get(int index) const;

	void set(int index, const T& value) const;

	bool contains(const T& value) const;

	T& operator[](int index);
};

template<class T>
Array<T>::Array() : arr(nullptr), size(0) { }

template<class T>
Array<T>::Array(int s)
{
	create(s);
	//cout << "Constr " << arr << endl;
}

template<class T>
Array<T>::Array(const Array& obj)
{
	size = obj.size;
	arr = new T[size];
	for (int i = 0; i < size; i++)
	{
		arr[i] = obj.arr[i];
	}
	//cout << "CopyConstr " << arr << endl;
}

template<class T>
Array<T>& Array<T>::operator=(const Array& obj)
{
	if (this == &obj)
	{
		return *this;
	}

	delete[] arr;

	size = obj.size;
	arr = new T[size];
	for (int i = 0; i < size; i++)
	{
		arr[i] = obj.arr[i];
	}

	return *this;
}

template<class T>
Array<T>::~Array()
{
	//cout << "Destr " << arr << endl;
	delete[] arr;
}

template<class T>
void Array<T>::create(int s)
{
	if (s <= 0)
	{
		return;
	}
	size = s;
	arr = new T[size];
}

template<class T>
bool Array<T>::IsEmpty() const
{
	return arr == nullptr;
}

template<class T>
void Array<T>::setRand() const
{
	cout << "no implemention for " << typeid(T).name() << endl;
}

template<>
void Array<int>::setRand() const
{
	cout << "int realisation\n";
	int minValue = 0, maxValue = 9;
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % (maxValue - minValue + 1) + minValue;
	}
}
//template<>
//void Array<Fraction>::setRand() const
//{
//	cout << "Fraction realisation\n";
//	int minValue = 0, maxValue = 9;
//	for (int i = 0; i < size; i++)
//	{
//		arr[i] = rand() % (maxValue - minValue + 1) + minValue;
//	}
//}

template<class T>
void Array<T>::show() const
{
	if (arr != nullptr)
	{
		for (int i = 0; i < size; i++)
		{
			cout << arr[i] << " ";
		}
	}

	cout << endl;
}

template<class T>
void Array<T>::add(int value)
{
	T* temp = new T[size + 1];
	for (int i = 0; i < size; i++)
	{
		temp[i] = arr[i];
	}
	temp[size] = value;
	delete[] arr;
	size++;
	arr = temp;
}

template<class T>
void Array<T>::remove(int index)
{
	if (index < 0 || index >= size)
	{
		return;
	}
	T* temp = new T[size - 1];
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

template<class T>
void Array<T>::insert(const T& value, int index)
{
	if (index < 0 || index > size)
	{
		return;
	}
	T* temp = new T[size + 1];
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

template<class T>
void Array<T>::sort() const
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

template<class T>
void Array<T>::reverse() const
{
	for (int i = 0; i < size / 2; i++)
	{
		swap(arr[i], arr[size - 1 - i]);
	}
}

template<class T>
void Array<T>::clear()
{
	delete[] arr;
	arr = nullptr;
	size = 0;
}

template<class T>
void Array<T>::resize(int newSize)
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

template<class T>
void Array<T>::fill(const T& value) const
{
	for (int i = 0; i < size; i++)
	{
		arr[i] = value;
	}
}

template<class T>
int Array<T>::getSize() const
{
	return size;
}

template<class T>
int Array<T>::countValue(const T& value) const
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

template<class T>
int Array<T>::findValue(const T& value) const
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

template<class T>
T Array<T>::get(int index) const
{
	if (index < 0 || index >= size)
	{
		return 0;
	}
	return arr[index];
}

template<class T>
void Array<T>::set(int index, const T& value) const
{
	if (index < 0 || index >= size)
	{
		return;
	}
	arr[index] = value;
}

//int Array::getMax() const
//{
//	if (size == 0)
//	{
//		return 0;
//	}
//	int maxVal = arr[0];
//	for (int i = 1; i < size; i++)
//	{
//		if (maxVal < arr[i])
//		{
//			maxVal = arr[i];
//		}
//	}
//	return maxVal;
//}
//
//int Array::getMin() const
//{
//	if (size == 0)
//	{
//		return 0;
//	}
//	int minVal = arr[0];
//	for (int i = 1; i < size; i++)
//	{
//		if (minVal > arr[i])
//		{
//			minVal = arr[i];
//		}
//	}
//	return minVal;
//}
//
//int Array::getSum() const
//{
//	int sum = 0;
//	for (int i = 0; i < size; i++)
//	{
//		sum += arr[i];
//	}
//	return sum;
//}
//
//double Array::getAverage() const
//{
//	if (size == 0)
//	{
//		return 0;
//	}
//	return (double)getSum() / size;
//}

template<class T>
bool Array<T>::contains(const T& value) const
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


template<class T>
T& Array<T>::operator[](int index)
{
	assert(index >= 0 && index < size);
	return arr[index];
}