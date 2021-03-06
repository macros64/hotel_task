// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include "Modeller.h"


using namespace std;

void work()
{
	cout << "Work. ";
}

void model()
{
	Modeller *m = new Modeller(25, 20, 80);

	m->doModelling();
	m->printResults();
}

int main()
{
	int input = 0;
	bool isThisTheEnd = false;
	setlocale(LC_ALL, "Russian");		// чтоб русский язык в консоли кракозябрами не выводился
	do
	{
		cout << "Выберите режим работы:" << endl
			<< "[1] - работа ресепшн" << endl
			<< "[2] - моделирование" << endl
			<< "[0] - выход" << endl;
		cin >> input;
		switch (input) 
		{
		case 1:
			work();
			break;
		case 2: 
			model();
			break;
		case 0:
			isThisTheEnd = true;
			break;
		default:
			cout << "Invalid input. ";
			break;
		}
	} while (!isThisTheEnd);
}