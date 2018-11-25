#pragma once

#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

enum StatusErr
{
	OK, Error
};
class Hotel {

public:
	Hotel() { Status = Error; } /* онструктор класса по умолчанию*/
	/*¬ констукторе задаЄм название гостиницы, количество мест всего, количество стандратных номеров, количество люксовых номеров,
	количество одноместых номеров, количество двухместных номеров, количество двухместных номеров с раскладным диваном.*/
	Hotel(string _name, int _countRooms, int _countStandardSingleRoom, int _countStandardDoubleRoom, int _countStandardDoubleAndHalfRoom,
		int _countLuxurySingleRoom, int _countLuxuryDoubleRoom, int _countLuxuryDoubleAndHalfRoom);
	~Hotel();
	friend ostream& operator << (ostream &os, Hotel* &pr);

	/*√еттеры*/
	string getName();
	int getCountRooms();
	int getCountStandardSingleRoom();
	int getCountStandardDoubleRoom();
	int getCountStandardDoubleAndHalfRoom();
	int getCountLuxurySingleRoom();
	int getCountLuxuryDoubleRoom();
	int getCountLuxuryDoubleAndHalfRoom();
	int getPriceStandardSingleRoom();
	int getPriceStandardDoubleRoom();
	int getPriceStandardDoubleAndHalfRoom();
	int getPriceLuxurySingleRoom();
	int getPriceLuxuryDoubleRoom();
	int getPriceLuxuryDoubleAndHalfRoom();

private:
	int Status;
	string name;
	int countRooms;
	int countStandardSingleRoom;
	int countStandardDoubleRoom;
	int countStandardDoubleAndHalfRoom;
	int countLuxurySingleRoom;
	int countLuxuryDoubleRoom;
	int countLuxuryDoubleAndHalfRoom;
	int priceStandardSingleRoom;
	int priceStandardDoubleRoom;
	int priceStandardDoubleAndHalfRoom;
	int priceLuxurySingleRoom;
	int priceLuxuryDoubleRoom;
	int priceLuxuryDoubleAndHalfRoom;
};

