#pragma once
#include<iostream>
#include<Windows.h>

#include"String.h"

using namespace std;

#define DEBUG

enum Color
{
	Black = 0, Blue = 1, Green = 2, Cyan = 3, Red = 4, Magenta = 5, Brown = 6, LightGray = 7, DarkGray = 8,
	LightBlue = 9, LightGreen = 10, LightCyan = 11, LightRed = 12, LightMagenta = 13, Yellow = 14, White = 15
};

void SetColor(int text, int background)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (WORD)((background << 4) | text));
}

enum class ReservoirType
{
	Unknown, Ocean, Sea, Lake, River, Pond, Lagoon
};

// Розробити клас Reservoir (водойма). Клас обов’язково повинен мати поле «назва».
// Клас повинен містити: конструктор за замовчуванням, конструктор з параметрами, за необхідності реалізувати деструктор.
// Додати методи для :
// 1. Визначення приблизного обсягу (ширина * довжина * максимальна глибина);
// 2. Визначення площі водної поверхні;
// 3. Метод для перевірки, чи належать водойми до одного типу (море - море; басейн - ставок);
// 4. Для порівняння площі водної поверхні водойм одного типу;
// 5. Для копіювання об’єктів;
// 6. Решта методів на розсуд розробника (методи set і get).
// Написати інтерфейс для роботи з класом. Реалізувати динамічний масив об’єктів класу з можливістю додавання, видалення об’єктів з масиву.
// Використовуйте explicit конструктор і константні функції - члени (наприклад, для відображення даних про водойму і т.д.).

const char* ReturnEnum(ReservoirType type)
{
	switch (type)
	{
	case ReservoirType::Unknown: return "Unknown";
	case ReservoirType::Ocean:   return "Ocean";
	case ReservoirType::Sea:     return "Sea";
	case ReservoirType::Lake:    return "Lake";
	case ReservoirType::River:   return "River";
	case ReservoirType::Pond:    return "Pond";
	case ReservoirType::Lagoon:  return "Lagoon";
	}
}

template<class T>
bool greaterA(const T& a, const T& b)
{
	return a > b;
}

class Reservoir
{
	String name;
	ReservoirType type;
	double width = 0;
	double length = 0;
	double height = 0;

public:
	Reservoir();
	explicit Reservoir(const char* name, ReservoirType t);
	Reservoir(const char* n, ReservoirType t, double w, double l, double h);

	Reservoir(const Reservoir& obj);

	String getName() const;

	ReservoirType getType() const;

	void setName(String n);

	void setType(ReservoirType t);

	void setParam(double w, double l, double h);

	double Volume(double w, double l, double h) const;
	double Volume() const;

	double Area(double w, double l) const;
	double Area() const;
	
	static bool typeCheck(const Reservoir& one, const Reservoir& two);

	static bool AreaCompare(const Reservoir& one, const Reservoir& two);
	
	void displayInfo() const;

	static void menu();
};

Reservoir::Reservoir() : Reservoir("Unknown", ReservoirType::Unknown, 0, 0, 0) {}
Reservoir::Reservoir(const char* n, ReservoirType t) : Reservoir(n, t, 0, 0, 0) {}
Reservoir::Reservoir(const char* n, ReservoirType t, double w, double l, double h)
{
	name = n;
	type = t;
	width = w;
	length = l;
	height = h;
}

String Reservoir::getName() const
{
	return name;
}

ReservoirType Reservoir::getType() const
{
	return type;
}

void Reservoir::setName(String n)
{
	name = n;
}

void Reservoir::setType(ReservoirType t)
{ 
	type = t;
}

void Reservoir::setParam(double w, double l, double h)
{
	width = w;
	length = l;
	height = h;
}

double Reservoir::Volume(double w, double l, double h) const
{
	return w * l * h;
}
double Reservoir::Volume() const
{
	return Volume(width, length, height);
}

double Reservoir::Area(double w, double l) const
{
	return w * l;
}
double Reservoir::Area() const
{
	return Area(width, length);
}

bool Reservoir::typeCheck(const Reservoir& one, const Reservoir& two)
{
	return one.getType() == two.getType();
}

bool Reservoir::AreaCompare(const Reservoir& one, const Reservoir& two)
{
	//if (typeCheck(one, two))
	//{
		return greaterA(one.Area(), two.Area());
	//}
	//return false;
}

void Reservoir::displayInfo() const
{
	cout << "Name: "; name.print();
	cout << "Type: " << ReturnEnum(type) << endl;
	cout << "Parameters (w x l x h): " << width << " x " << length << " x " << height << endl;
}

void printArray(Reservoir*& arr, int& size)
{
	for (int i = 0; i < size; i++)
	{
		cout << i + 1 << ". "; arr[i].getName().print();
	}
}

void addReservoir(Reservoir*& arr, int& size)
{
	system("cls");
	cout << "=====   ADD  RESERVOIR   =====\n";
	String n;
	int T; ReservoirType t;
	double w, l, h;
	Reservoir r;

	cout << "Enter the name: "; n.input();
	r.setName(n);

	cout << "0 - Unknown\n";
	cout << "1 - Ocean\n";
	cout << "2 - Sea\n";
	cout << "3 - Lake\n";
	cout << "4 - River\n";
	cout << "5 - Pond\n";
	cout << "6 - Lagoon\n";
	cout << "Enter the type: "; cin >> T;
	switch (T)
	{
	case 0: t = ReservoirType::Unknown; break;
	case 1: t = ReservoirType::Ocean; break;
	case 2: t = ReservoirType::Sea; break;
	case 3: t = ReservoirType::Lake; break;
	case 4: t = ReservoirType::River; break;
	case 5: t = ReservoirType::Pond; break;
	case 6: t = ReservoirType::Lagoon; break;
	default:
		t = ReservoirType::Unknown;
		break;
	}
	r.setType(t);

	cout << "Enter the width  (m): "; cin >> w;
	cout << "Enter the length (m): "; cin >> l;
	cout << "Enter the height (m): "; cin >> h;
	r.setParam(w, l, h);

	Reservoir* temp = new Reservoir[size + 1];
	for (int i = 0; i < size; i++)
	{
		temp[i] = arr[i];
	}
	temp[size] = r;
	delete[] arr;
	arr = temp;
	size++;

	SetColor(LightGreen, Black);
	cout << "Added!\n";
	SetColor(White, Black);
	system("pause");
}

void deleteReservoir(Reservoir*& arr, int& size)
{
	system("cls");
	cout << "=====  DELETE RESERVOIR  =====\n";
	if (size > 1)
	{
		int ind;
		printArray(arr, size);
		do
		{
			cout << "Choose number to delete: "; cin >> ind; ind--;
			if (ind < 0 || ind >= size)
			{
				cout << "Number must be within the 1-" << size << " range.\n";
			}
		} while (ind < 0 || ind >= size);
		
		Reservoir* temp = new Reservoir[size - 1];
		for (int i = 0; i < ind; i++)
		{
			temp[i] = arr[i];
		}
		for (int i = ind; i < size - 1; i++)
		{
			temp[i] = arr[i + 1];
		}
		delete[] arr;
		arr = temp;
		size--;

		SetColor(LightGreen, Black);
		cout << "Done!\n";
		SetColor(White, Black);
	}
	else
	{
		cout << "List should include at least one reservoir!" << endl;
	}
	system("pause");
}

void ReservoirInfo(Reservoir*& arr, int& size)
{
	system("cls");
	int ind;
	cout << "=====   RESERVOIR INFO   =====\n";
	printArray(arr, size);
	do
	{
		cout << "Reservoir number to display: "; cin >> ind; ind--;
		if (ind < 0 || ind >= size)
		{
			cout << "Number must be within the 1-" << size << " range.\n";
		}
	} while (ind < 0 || ind >= size);

	system("cls");
	cout << "=====   RESERVOIR INFO   =====\n";
	arr[ind].displayInfo();
	system("pause");
}

void ReservoirVolume(Reservoir*& arr, int& size)
{
	system("cls");
	int ind;
	cout << "=====  RESERVOIR VOLUME  =====\n";
	cout << "0. Custom size\n";
	printArray(arr, size);
	do
	{
		cout << "Choose a reservoir to see volume: "; cin >> ind;
		if (ind < 0 || ind > size)
		{
			cout << "Number must be within the 0-" << size << " range.\n";
		}
	} while (ind < 0 || ind > size);

	system("cls");
	cout << "=====  RESERVOIR VOLUME  =====\n";
	if (ind == 0)
	{
		Reservoir r;
		double w, l, h;
		cout << "Enter the width  (m): "; cin >> w;
		cout << "Enter the length (m): "; cin >> l;
		cout << "Enter the height (m): "; cin >> h;
		
		cout << "The volume is " << r.Volume(w, l, h) << " m^3\n";
	}
	else
	{
		ind--;
		cout << "Volume of the "; arr[ind].getName().print();
		cout << arr[ind].Volume() << " m^3\n";
	}
	system("pause");
}

void ReservoirArea(Reservoir*& arr, int& size)
{
	system("cls");
	int ind;
	cout << "=====   RESERVOIR AREA   =====\n";
	cout << "0. Custom size\n";
	printArray(arr, size);
	do
	{
		cout << "Choose a reservoir to see surface area: "; cin >> ind;
		if (ind < 0 || ind > size)
		{
			cout << "Number must be within the 0-" << size << " range.\n";
		}
	} while (ind < 0 || ind > size);

	system("cls");
	cout << "=====   RESERVOIR AREA   =====\n";
	if (ind == 0)
	{
		Reservoir r;
		double w, l;
		cout << "Enter the width  (m): "; cin >> w;
		cout << "Enter the length (m): "; cin >> l;

		cout << "The surcafe area is " << r.Area(w, l) << " m^2\n";
	}
	else
	{
		ind--;
		cout << "Surface area of the "; arr[ind].getName().print();
		cout << arr[ind].Area() << " m^2\n";
	}
	system("pause");
}

void ReservoirTypeCheck(Reservoir*& arr, int& size)
{
	system("cls");
	cout << "=====   COMPARE   TYPE   =====\n";
	int* inds = new int[2] {-1, -1};
	printArray(arr, size);
	for (int i = 0; i < 2; i++)
	{
		int ind;
		do
		{
			cout << "Choose a reservoir to compare: "; cin >> ind; ind--;
			if (ind < 0 || ind >= size || ind == inds[0])
			{
				cout << "Number must be within the 1-" << size << " range and must not repeat.\n";
			}
		} while (ind < 0 || ind >= size || ind == inds[0]);
		inds[i] = ind;
	}
	if (Reservoir::typeCheck(arr[inds[0]], arr[inds[1]]))
	{
		cout << "Both are " << ReturnEnum(arr[inds[0]].getType()) << ".\n";
	}
	else
	{
		cout << "They are not the same type.\n";
	}
	delete[] inds;
	system("pause");
}

void ReservoirAreaCheck(Reservoir*& arr, int& size)
{
	system("cls");
	cout << "=====   COMPARE   AREA   =====\n";
	int* inds = new int[2] {-1, -1};
	printArray(arr, size);
	for (int i = 0; i < 2; i++)
	{
		int ind;
		do
		{
			cout << "Choose a reservoir to compare: "; cin >> ind; ind--;
			if (ind < 0 || ind >= size || ind == inds[0])
			{
				cout << "Number must be within the 1-" << size << " range and must not repeat.\n";
			}
		} while (ind < 0 || ind >= size || ind == inds[0]);
		inds[i] = ind;
	}
	cout << "Bigger surface area has ";
	if (Reservoir::AreaCompare(arr[inds[0]], arr[inds[1]]))
	{
		arr[inds[0]].getName().print();
	}
	else
	{
		arr[inds[1]].getName().print();
	}
	delete[] inds;
	system("pause");
}

void Reservoir::menu()
{
	Reservoir* list = nullptr;
	int size = 0;
#ifdef DEBUG
	size = 5;
	list = new Reservoir[size];
	list[0].setName("Black Sea");
	list[0].setType(ReservoirType::Sea);
	list[0].setParam(100, 200, 50);

	list[1].setName("Blue Lake");
	list[1].setType(ReservoirType::Lake);
	list[1].setParam(50, 80, 20);

	list[2].setName("Big Pond");
	list[2].setType(ReservoirType::Pond);
	list[2].setParam(20, 30, 5);

	list[3].setName("Inhul");
	list[3].setType(ReservoirType::River);
	list[3].setParam(100, 500, 10);

	list[4].setName("White Sea");
	list[4].setType(ReservoirType::Sea);
	list[4].setParam(100, 200, 50);
#endif

	while (true)
	{
		int choice;
		system("cls");
		cout << "=====   RESERVOIR MENU   =====\n"
			"1. Add reservoir\n"
			"2. Delete reservoir\n"
			"3. Show all reservoirs\n"
			"4. Show reservoir information\n"
			"5. Calculate volume\n"
			"6. Calculate surface area\n"
			"7. Check same type\n"
			"8. Compare areas\n"
			"0. Exit\n"
			"Choose : "; cin >> choice; cin.ignore();

		switch (choice)
		{
		case 1:
			addReservoir(list, size);
			break;
		case 2:
			deleteReservoir(list, size);
			break;
		case 3:
			system("cls");
			cout << "===== LIST OF RESERVOIRS =====\n";
			printArray(list, size);
			system("pause");
			break;
		case 4:
			ReservoirInfo(list, size);
			break;
		case 5:
			ReservoirVolume(list, size);
			break;
		case 6:
			ReservoirArea(list, size);
			break;
		case 7:
			ReservoirTypeCheck(list, size);
			break;
		case 8:
			ReservoirAreaCheck(list, size);
			break;
		default:
			SetColor(LightRed, Black);
			cout << "Exit\n";
			SetColor(White, Black);
			exit(0);
			break;
		}
	}
	delete[] list;
}