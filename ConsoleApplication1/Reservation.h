#pragma once

#include "common.h"
#include <string>
#include <ctime>

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

	time_t startDate;		// дата заезда
	time_t endDate;			// дата выезда

	// время создания резервирования
	time_t reservationCreatedTime;

	Reservation(string owner, int roomNum, float price, time_t start, time_t end)
	{
		roomOwner = owner;
		roomNumber = roomNum;
		pricePerNight = price;
		startDate = start;
		endDate = end;
		reservationCreatedTime = time(NULL);
	}

	Reservation();
	~Reservation();
};

