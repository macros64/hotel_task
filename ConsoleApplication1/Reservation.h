#pragma once

#include "common.h"
#include <string>

using namespace std;

/*
 * записи резервирования номеров
 */
class Reservation
{
public:

	string roomOwner;		// верховный постоялец
	int roomNumber;			// номер зарезервированой комнаты
	float pricePerNight;	// итоговая цена за ночь
	// start date here
	// end date here

	Reservation();
	~Reservation();
};

