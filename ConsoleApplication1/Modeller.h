#pragma once
/*
 * класс выполняющие моделирование работы отеля
 */

#include "common.h"
#include "Hotel.h"

class Modeller
{
private:

	Hotel _hotel;
	void initHotel();
public:
	int K;				// общее количество номеров в отеле
	int M;				// период моледирования в днях
	int clientsCount;	// общее поличество клиентов

	Modeller(int k, int m, int clients) { K = k, M = m, clientsCount = clients; }
	Modeller();
	~Modeller();

	void doModelling();
	void printResults();
};

