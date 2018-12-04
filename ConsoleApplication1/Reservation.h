#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include "common.h"
#include "Room.h"
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
	RoomType roomType;
	string roomTypeStr;
	float pricePerNight;	// итоговая цена за ночь

	time_t startDate;		// дата заезда
	time_t endDate;			// дата выезда

	// время создания резервирования
	time_t reservationCreatedTime;

	Reservation(string owner, Room* room, float price, time_t start, time_t end);
	Reservation();
	~Reservation();
	friend ostream& operator<<(ostream& os, const Reservation &r);
};

