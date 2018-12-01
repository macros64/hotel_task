#pragma once

#include <string>
#include <iostream>
#include <iomanip>
#include <vector>
#include <map>

#include "common.h"
#include "Room.h"
#include "Reservation.h"

using namespace std;

enum StatusErr
{
	OK, Error
};

/*
 * сущность отеля. мастер-объект.
 */
class Hotel {

public:

	vector<Room> *rooms;				// номерной фонд отеля
	map <RoomType, float> *prices;
	vector<Reservation> *reservations;	// записи резервирования номеров

	Hotel() { Status = Error; } //Конструктор класса по умолчанию
	/*В констукторе задаём название гостиницы, количество мест всего, количество стандратных номеров, количество люксовых номеров,
	количество одноместых номеров, количество двухместных номеров, количество двухместных номеров с раскладным диваном.*/
	Hotel(string _name, int _countStandardSingleRoom, int _countStandardDoubleRoom, int _countStandardDoubleAndHalfRoom,
		int _countLuxurySingleRoom, int _countLuxuryDoubleRoom, int _countLuxuryDoubleAndHalfRoom);
	~Hotel();
	friend ostream& operator << (ostream &os, Hotel* &pr);

	/*Геттеры*/
	string getName();
	int getCountRooms();
	int getCountStandardSingleRoom();
	int getCountStandardDoubleRoom();
	int getCountStandardDoubleAndHalfRoom();
	int getCountLuxurySingleRoom();
	int getCountLuxuryDoubleRoom();
	int getCountLuxuryDoubleAndHalfRoom();

	float getPriceStandardSingleRoom();
	float getPriceStandardDoubleRoom();
	float getPriceStandardDoubleAndHalfRoom();
	float getPriceLuxurySingleRoom();
	float getPriceLuxuryDoubleRoom();
	float getPriceLuxuryDoubleAndHalfRoom();

	// метод возвращает список свободных комнат по заданным условиям: даты и тип
	// если нет комнат нужного типа на нужные даты - берутся комнаты классом выше
	vector<Room> getFreeRooms(RoomType _type, time_t startdate, time_t enddate);

	// метод выполняет резервирование комнаты на указанные даты и 
	Reservation reserveRoom(Room &room, RoomType desiredRoomType, string owner, time_t startdate, time_t enddate);

private:
	int Status;
	string name;

	int getRoomsCount(RoomType type); // внутренний метод подсчета количества комнат определеного типа
	float getRoomPrice(RoomType type); // внутренний метод поиска цены за указанный тип номера
};

