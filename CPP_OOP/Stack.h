#pragma once
#include<cassert>

#include"Node.h"


template<class T, size_t maxSize>
class Stack
{
	Node<T>* first;
	size_t   size;

public:
	Stack();
	~Stack();
	Stack(const Stack& obj);
	Stack& operator=(const Stack& obj);

	void   push(const T& value);
	void   pop();
	T&     peek() const;
	bool   IsEmpty() const;
	void   clear();
	size_t getSize() const;
	void   print() const;
};

template<class T, size_t maxSize>
Stack<T, maxSize>::Stack() : first(nullptr), size(0) { }

template<class T, size_t maxSize>
Stack<T, maxSize>::~Stack()
{
	clear();
}

template<class T, size_t maxSize>
Stack<T, maxSize>::Stack(const Stack& obj) : first(nullptr), size(obj.size)
{
	if (obj.first == nullptr)
	{
		return;
	}

	first = new Node<T>(obj.first->value);

	Node<T>* current = first;
	Node<T>* lower = obj.first->next;
	for (size_t i = 0; i < size - 1; i++)
	{
		current->next = new Node<T>(lower->value);
		current = current->next;
		lower = lower->next;
	}
}

template<class T, size_t maxSize>
Stack<T, maxSize>& Stack<T, maxSize>::operator=(const Stack& obj)
{
	if (this == &obj)
	{
		return *this;
	}

	size = obj.size;
	first = new Node<T>(obj.first->value);

	Node<T>* current = first;
	Node<T>* lower = obj.first->next;
	for (size_t i = 0; i < size - 1; i++)
	{
		current->next = new Node<T>(lower->value);
		current = current->next;
		lower = lower->next;
	}

	return *this;
}

template<class T, size_t maxSize>
void Stack<T, maxSize>::push(const T& value)
{
	if (size < maxSize)
	{
		if (size == 0)
		{
			first = new Node<T>(value);
		}
		else
		{
			Node<T>* newNode = new Node<T>(value);
			newNode->next = first;
			first = newNode;
		}
		size++;
	}
	else
	{
		cout << "Stack Overflow!\n";
	}
}

template<class T, size_t maxSize>
void Stack<T, maxSize>::pop()
{
	if (size > 0)
	{
		Node<T>* temp = first;
		first = first->next;
		delete temp;
		size--;
	}
}

template<class T, size_t maxSize>
T& Stack<T, maxSize>::peek() const
{
	assert(size > 0);
	return first->value;
}

template<class T, size_t maxSize>
bool Stack<T, maxSize>::IsEmpty() const
{
	return size == 0;
}

template<class T, size_t maxSize>
void Stack<T, maxSize>::clear()
{
	Node<T>* temp = first;
	while (temp)
	{
		first = first->next;
		delete temp;
		temp = first;
	}
	size = 0;
}

template<class T, size_t maxSize>
size_t Stack<T, maxSize>::getSize() const
{
	return size;
}

template<class T, size_t maxSize>
void Stack<T, maxSize>::print() const
{
	Node<T>* temp = first;
	while (temp)
	{
		cout << temp->value << " ";
		temp = temp->next;
	}
	cout << endl;
}
