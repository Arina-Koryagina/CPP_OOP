#pragma once
#include<fstream>

#include"String.h"

// Створіть ієрархію класів для роботи з файлами.
// Базовий клас вміє відкривати файл і виводити його вміст в консоль,
// перший клас нащадок відкриває файл і виводить вміст
// у вигляді ASCII - кодів символів, розташованих в файлі,
// другий клас нащадок відкриває файл і виводить його вміст
// у двійковому вигляді і т.д.
// Щоб продемонструвати вміст файлу в базовому класі визначена віртуальна функція:
// void Display(const char* path), де path — шлях до файлу.
// Нащадки створюють свою реалізацію віртуальної функції.

class File
{
	String path;

public:
	File(const char* p) : path(p) {}

	virtual ~File() {}

	String getPath();

	virtual void print(const char* line);

	void display();
	void display(const char* path);
};

String File::getPath()
{
	return path;
}

void File::print(const char* line)
{
	cout << line << endl;
}

void File::display()
{
	display(getPath());
}
void File::display(const char* path)
{
	char buffer[1024];
	ifstream in(path);
	if (in.is_open())
	{
		while (in.getline(buffer, 1024))
		{
			print(buffer);
		}
	}
	in.close();
	cout << endl;
}


class ASCIIFile : public File
{
public:

	ASCIIFile(const char* p) : File(p) {}

	~ASCIIFile() {}

	virtual void print(const char* line) override;
};

void ASCIIFile::print(const char* line)
{
	int size = strlen(line);
	for (int i = 0; i < size; i++)
	{
		cout << int(line[i]) << " ";
	}
	cout << endl;
}


class BinFile : public File
{
	String int_to_bin(int number);

public:

	BinFile(const char* p) : File(p) {}

	~BinFile() {}

	virtual void print(const char* line) override;
};

String BinFile::int_to_bin(int number)
{
	if (number == 0) { return "00000000"; }
	String res(""); int digit;
	while (number > 0)
	{
		digit = number % 2;
		if (digit == 1)
		{
			res += "1";
		}
		else
		{
			res += "0";
		}
		number /= 2;
	}
	while (strlen(res) < 8)
	{
		res += "0";
	}
	res.reverse();
	return res;
}

void BinFile::print(const char* line)
{
	int size = strlen(line);
	for (int i = 0; i < size; i++)
	{
		cout << int_to_bin(int(line[i])) << " ";
	}
	cout << endl;
}