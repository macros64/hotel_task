#pragma once
/*
 * класс выполняющие моделирование работы отеля
 */
#define _CRT_SECURE_NO_WARNINGS
#include "common.h"
#include "Hotel.h"



class Modeller
{
private:

	Hotel *_hotel;
	void initHotel();
	string getRandomClientName();
public:
	int K;				// общее количество номеров в отеле
	int M;				// период моледирования в днях
	int clientsCount;	// общее поличество клиентов

	Modeller(int k, int m, int clients);
	Modeller();
	~Modeller();

	void doModelling();
	void printResults();
};

