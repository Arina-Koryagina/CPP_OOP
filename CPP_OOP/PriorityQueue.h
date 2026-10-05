#pragma once
#include<cassert>
#include<initializer_list>

#include"Node.h"

template<class T, class TPri = T>
class PriorityQueue
{
	Node<T, TPri>* first;
	Node<T, TPri>* last;
	size_t   size;

public:
	PriorityQueue();
	PriorityQueue(const PriorityQueue& obj);
	PriorityQueue& operator= (const PriorityQueue& obj);
	~PriorityQueue();

	void   enqueue(const T& value, TPri pri);
	void   dequeue();
	void   del_enqueue(const T& value);
	void   del_dequeue(TPri pri);
	T&     peek() const;

	void   print() const;
	void   clear();
	size_t getSize() const;
};

template<class T, class TPri>
PriorityQueue<T, TPri>::PriorityQueue() : first(nullptr), last(nullptr), size(0) { }

template<class T, class TPri>
PriorityQueue<T, TPri>::PriorityQueue(const PriorityQueue& obj) : first(nullptr), size(obj.size)
{
	if (obj.first == nullptr)
	{
		return;
	}

	first = new Node<T, TPri>(obj.first->value);

	Node<T, TPri>* current = first;
	Node<T, TPri>* lower = obj.first->next;
	for (size_t i = 0; i < size - 1; i++)
	{
		current->next = new Node<T, TPri>(lower->value);
		current = current->next;
		lower = lower->next;
	}
}

template<class T, class TPri>
PriorityQueue<T, TPri>& PriorityQueue<T, TPri>::operator=(const PriorityQueue& obj)
{
	if (this == &obj)
	{
		return *this;
	}

	size = obj.size;
	first = new Node<T, TPri>(obj.first->value);

	Node<T, TPri>* current = first;
	Node<T, TPri>* lower = obj.first->next;
	for (size_t i = 0; i < size - 1; i++)
	{
		current->next = new Node<T, TPri>(lower->value);
		current = current->next;
		lower = lower->next;
	}

	return *this;
}

template<class T, class TPri>
PriorityQueue<T, TPri>::~PriorityQueue()
{
	clear();
}

template<class T, class TPri>
void PriorityQueue<T, TPri>::enqueue(const T& value, TPri pri)
{
	Node<T, TPri>* newNode = new Node<T, TPri>(value, pri);
	
	if (size == 0)
	{
		first = last = newNode;
		size++;
		return;
	}

	if (pri > first->priority)
	{
		newNode->next = first;
		first = newNode;
	}
	else if (pri <= last->priority)
	{
		last->next = newNode;
		last = newNode;
	}
	else
	{
		Node<T, TPri>* pos = first;
		while (pri <= pos->next->priority)
		{
			pos = pos->next;
		}
		newNode->next = pos->next;
		pos->next = newNode;
	}
	size++;
}

template<class T, class TPri>
void PriorityQueue<T, TPri>::dequeue()
{
	if (size > 0)
	{
		Node<T, TPri>* temp = first;
		first = first->next;
		delete temp;
		size--;
	}

	if (size == 0) { last = nullptr; }
}

template<class T, class TPri>
void PriorityQueue<T, TPri>::del_enqueue(const T& value)
{
	if (size == 0)
	{
		first = last = new Node<T>(value);
	}
	else
	{
		last->next = new Node<T>(value);
		last = last->next;
	}
	size++;
}

template<class T, class TPri>
void PriorityQueue<T, TPri>::del_dequeue(TPri pri)
{
	if (size == 1)
	{
		clear();
		return;
	}

	//if (pri > first->priority)
	//{
	//	newNode->next = first;
	//	first = newNode;
	//}
	//else if (pri <= last->priority)
	//{
	//	last->next = newNode;
	//	last = newNode;
	//}
	//else
	//{
	//	Node<T, TPri>* pos = first;
	//	while (pri <= pos->next->priority)
	//	{
	//		pos = pos->next;
	//	}
	//	newNode->next = pos->next;
	//	pos->next = newNode;
	//}
	size--;

	if (size == 0)
	{
		last = nullptr;
		size = 0;
	}

}

template<class T, class TPri>
T& PriorityQueue<T, TPri>::peek() const
{
	assert(size > 0);
	return first->value;
}

template<class T, class TPri>
void PriorityQueue<T, TPri>::print() const
{
	Node<T, TPri>* temp = first;
	while (temp)
	{
		cout << temp->value << " ";
		temp = temp->next;
	}
	cout << endl;
}

template<class T, class TPri>
void PriorityQueue<T, TPri>::clear()
{
	Node<T, TPri>* temp = first;
	while (temp)
	{
		first = first->next;
		delete temp;
		temp = first;
	}
	size = 0;
	last = nullptr;
}

template<class T, class TPri>
size_t PriorityQueue<T, TPri>::getSize() const
{
	return size;
}
