//#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//
//#include"Array.h"
//#include"Worker.h"
//
//using namespace std;
//
//int main()
//{
//	srand(time(0));
//
//	//Worker a;
//	//a.setName("Gerard Arthur Way");
//	//a.setJob(Occupation::TeamLead);
//	//a.setYear(1996);
//	//a.setMoney(8000);
//	//a.displayInfo();
//
//
//// Створіть клас Worker. Необхідно зберігати дані: ПІБ, посада, рік вступу на роботу, зарплата.
//// Створити масив об’єктів. Вивести:
//// - список працівників, стаж роботи яких на цьому підприємстві перевершує задане число років;
//// - список працівників, зарплата яких перевищує задану;
//// - список працівників, які займають задану посаду.
//// Використовуйте explicit - конструктор і константні функції - члени.
//
//	int size = 5, currentYear = 2026, start = 0, end = 10;
//	Array<Worker> staff;
//	for (int i = 0; i < size; i++)
//	{
//		Worker w(i+1);
//		w.setRand();
//		staff.add(w);
//	}
//	for (int i = 0; i < size; i++)
//	{
//		staff[i].displayInfo();
//	}
//
//	int exp;
//	cout << "\nEnter the max experience: "; cin >> exp;
//	for (int i = 0; i < size; i++)
//	{
//		if (currentYear - staff[i].getYear() > exp)
//		{
//			cout << "ID: " << staff[i].getID() << " - ";
//			staff[i].getName().print();
//		}
//	}
//
//	int money;
//	cout << "\nEnter the max salary: "; cin >> money;
//	for (int i = 0; i < size; i++)
//	{
//		if (staff[i].getMoney() > money)
//		{
//			cout << "ID: " << staff[i].getID() << " - ";
//			staff[i].getName().print();
//		}
//	}
//
//	cout << endl;
//	for (int i = start; i <= end; i++)
//	{
//		cout << i << ". " << ReturnEnum(Occupation(i)) << endl;
//	}
//	int job;
//	do
//	{
//		cout << "Enter the occupation: "; cin >> job;
//		if (job < start || job > end)
//		{
//			cout << "Number must be within the " << start << "-" << end << " range.\n";
//		}
//	} while (job < start || job > end);
//	for (int i = 0; i < size; i++)
//	{
//		if (staff[i].getJob() == Occupation(job))
//		{
//			cout << "ID: " << staff[i].getID() << " - ";
//			staff[i].getName().print();
//		}
//	}
//
//	return 0;
//}