#pragma once


template<class T>
class SmartPointer
{
	T* ptr;

public:
	SmartPointer(T* p) : ptr(p) {}
	~SmartPointer() { delete ptr; }
	T& operator*() { return *ptr; }
	T* operator->() { return ptr; }

	SmartPointer(const SmartPointer& obj) = delete;
	SmartPointer& operator=(const SmartPointer& obj) = delete;

	SmartPointer(SmartPointer&& obj)
	{
		ptr = obj.ptr;
		obj.ptr = nullptr;
	}

	SmartPointer& operator=(SmartPointer&& obj)
	{
		if (&obj == this)
			return *this;

		delete ptr;

		ptr = obj.ptr;
		obj.ptr = nullptr;

		return *this;
	}
};

template<class T>
class SharedPointer
{
	T*   ptr;
	int* count;

public:
	SharedPointer() : ptr(nullptr)
	{
		count = new int(0);
	}
	SharedPointer(T* p) : ptr(p)
	{
		count = new int(1);
	}
	~SharedPointer()
	{
		if ((*count) == 1)
		{
			delete ptr;
			delete count;
		}
		else
		{
			(*count)--;
		}
	}
	T& operator*() { return *ptr; }
	T* operator->() { return ptr; }

	SharedPointer(const SharedPointer& obj)
	{
		ptr = obj.ptr;
		count = obj.count;
		(*count)++;
	}

	SharedPointer(SharedPointer&& obj)
	{
		ptr = obj.ptr;
		count = obj.count;
		obj.ptr = nullptr;
		obj.count = nullptr;
	}

	SharedPointer& operator=(const SharedPointer& obj)
	{
		if (&obj == this)
			return *this;

		ptr = obj.ptr;
		count = obj.count;
		(*count)++;

		return *this;
	}
};
