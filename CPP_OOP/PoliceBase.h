#pragma once
#include<fstream>
#include<Windows.h>

#include"BTree.h"
#include"String.h"
#include"List.h"
#include"Date.h"

enum Color
{
	Black = 0, Blue = 1, Green = 2, Cyan = 3, Red = 4, Magenta = 5, Brown = 6, LightGray = 7, DarkGray = 8,
	LightBlue = 9, LightGreen = 10, LightCyan = 11, LightRed = 12, LightMagenta = 13, Yellow = 14, White = 15
};

void SetColor(int text, int background)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (WORD)((background << 4) | text));
}
 
//Реалізувати базу даних ДАІ по штрафних квитанціях
//за допомогою бінарного дерева. Ключем служитиме номер
//машини, значенням вузла — список правопорушень. Якщо
//квитанція додається в перший раз, то в дереві з’являється
//новий вузол, а в списку дані по правопорушенню; якщо
//немає, то дані заносяться в існуючий список. Необхідно
//також реалізувати такі операції :
//■ Повний друк бази даних (за номерами машин і списку
//	правопорушень, що закріплені за ними);
//■ Роздруківка даних за заданим номером;
//■ Роздруківка даних за діапазоном номерів.

class Notice
{
	String number;
	Date date;
	String notice;
	int fine;
	bool isPaid = false;

public:
	String getNumber();
	bool is_paid();
	int pay();
	void input();
	void input(String num, String d, String notice, int f, bool paid);
	String output();

	friend ostream& operator<<(ostream& out, const Notice& n);
};

String Notice::getNumber()
{
	return number;
}

bool Notice::is_paid()
{
	return isPaid;
}

int Notice::pay()
{
	isPaid = true;
	return fine;
}

void Notice::input()
{
	system("cls");
	cout << "======  Add a notice  ======\n";
	String num, d, fine_not, paid; int f;
	cout << "Enter vehicle's number plate (XX0000XX): "; num.input();
	cout << "Enter the date (yyyy-mm-dd hh:mm:ss): "; d.input();
	cout << "Enter the notice: "; fine_not.input();
	cout << "Enter the fine: "; cin >> f; cin.ignore();
	cout << "Was it paid? (Y/n): "; paid.input();
	input(num, d, fine_not, f, paid == "Y");
}
void Notice::input(String num, String d, String fine_not, int f, bool paid)
{
	number = num;
	date = Date(d);
	notice = fine_not;
	fine = f;
	isPaid = paid;
}

String Notice::output()
{
	String line = date.formDate(); line += ";";
	line += notice; line += ";";
	line += fine; line += ";";
	(isPaid) ? line += "1" : line += "0";
	return line;
}

ostream& operator<<(ostream& out, const Notice& n)
{
	out << n.notice << " issued " << n.date << ". Fine: " << n.fine << " (";
	if (n.isPaid == 0) out << "not ";
	out << "paid)\n";
	return out;
}

class PoliceBase
{
	BTree<String, List<Notice*>> base;

public:
	void addNotice(Notice* n);
	void addNotice();
	void addNotice(String num, String d, String notice, int f, bool paid);
	void print();
	void print(String number);
	void print(String number1, String number2);
	void save();
	void load();
	void pay();
};

void PoliceBase::addNotice(Notice* n)
{
	List<Notice*>* l = base.getValue(n->getNumber());
	if (l != nullptr)
	{
		l->push_back(n);
	}
	else
	{
		List<Notice*> newList;
		newList.push_back(n);
		base.push_r(n->getNumber(), newList);
	}
}
void PoliceBase::addNotice()
{
	Notice* n = new Notice;
	n->input();
	addNotice(n);
}
void PoliceBase::addNotice(String num, String d, String notice, int f, bool paid)
{
	Notice* n = new Notice;
	n->input(num, d, notice, f, paid);
	addNotice(n);
}

void PoliceBase::print()
{
	base.key_print("Number plate:");
}

void PoliceBase::print(String number)
{
	cout << "Number plate: " << number << endl;
	cout << *(base.getValue(number)) << endl;
}

void PoliceBase::print(String number1, String number2)
{
	List<String> keys; base.formKeys(keys);
	int start = keys.firstIndex(number1), end = keys.firstIndex(number2);
	while (start != end + 1)
	{
		cout << "Number plate: " << keys[start] << endl;
		cout << *(base.getValue(keys[start])) << endl;
		start++;
	}
}

void PoliceBase::save()
{
	List<String> keys; base.formKeys(keys);
	ofstream out("PoliceBase.txt");
	int size = keys.getSize();
	int s = 0, l = 0, n = 0;
	while (s < size)
	{
		List<Notice*> list = *(base.getValue(keys[s]));
		n = list.getSize();
		while (l < n)
		{
			out << keys[s] << ";";
			out << list[l++]->output() << endl;
		}
		l = 0;
		s++;
	}
	out.close();
}

void PoliceBase::load()
{
	ifstream in("PoliceBase.txt");
	int s = 0;
	String number(8), date(19), notice(200), fine(6), paid(1);
	while (
		in.getline(number, 9, ';') &&
		in.getline(date, 20, ';') &&
		in.getline(notice, 201, ';') &&
		in.getline(fine, 7, ';') &&
		in.getline(paid, 2))
	{
		addNotice(number, date, notice, int(fine), paid == "1");
	}
	in.close();
}

void PoliceBase::pay()
{
	List<String> keys; base.formKeys(keys);
	size_t size = keys.getSize();
	system("cls");
	cout << "======  Pay a notice  ======\n";
	for (size_t i = 0; i < size; i++)
	{
		cout << i + 1 << ". " << keys[i] << endl;
	}
	int plate, fine; bool n = false;
	cout << "Choose a plate number: "; cin >> plate; plate--;

	List<Notice*> notes = *(base.getValue(keys[plate]));
	size = notes.getSize();
	system("cls");
	cout << "======  Pay a notice  ======\n";
	for (size_t i = 0; i < size; i++)
	{
		if (!notes[i]->is_paid())
		{
			n = true;
			break;
		}
	}
	if (n)
	{
		for (size_t i = 0; i < size; i++)
		{
			cout << i + 1 << ". " << *notes[i];
		}
		cout << "Choose a fine to pay: "; cin >> fine; fine--;
		if (!notes[fine]->is_paid())
		{
			int paid = notes[fine]->pay();
			SetColor(LightGreen, Black);
			cout << paid << " of a fine is paid!\n";
			SetColor(White, Black);
		}
		else
		{
			cout << "This fine is already paid." << endl;
		}
	}
	else
	{
		SetColor(LightGreen, Black);
		cout << "All the fine notices are paid!" << endl;
		SetColor(White, Black);
	}
}
