#include "pch.h"
#include "Hotel.h"


Hotel::Hotel(string _name, int _countStandardSingleRoom, int _countStandardDoubleRoom, int _countStandardDoubleAndHalfRoom,
	int _countLuxurySingleRoom, int _countLuxuryDoubleRoom, int _countLuxuryDoubleAndHalfRoom) 
{ 
	int romsCount = _countStandardSingleRoom + _countStandardDoubleRoom + _countStandardDoubleAndHalfRoom +
		_countLuxurySingleRoom + _countLuxuryDoubleRoom + _countLuxuryDoubleAndHalfRoom;
	// �������� ��������, �� ����� ��� �� ����� ��� ��� ��� ���������� �������� �� ��������� ���������
	if (_name == "" || romsCount < 20 || romsCount > 30) 
	{
		Status = Error;
	}
	else 
	{
		name = _name;
		int roomCounter = 1;

		for (int i = 0; i < _countStandardSingleRoom; i++)
			rooms->push_back(Room(RoomType::STD, roomCounter++));
		for (int i = 0; i < _countStandardDoubleRoom; i++)
			rooms->push_back(Room(RoomType::DBL, roomCounter++));
		for (int i = 0; i < _countStandardDoubleAndHalfRoom; i++)
			rooms->push_back(Room(RoomType::DBL_PLUS, roomCounter++));
		for (int i = 0; i < _countLuxurySingleRoom; i++)
			rooms->push_back(Room(RoomType::LUX, roomCounter++));
		for (int i = 0; i < _countLuxuryDoubleRoom; i++)
			rooms->push_back(Room(RoomType::LUX_DBL, roomCounter++));
		for (int i = 0; i < _countLuxuryDoubleAndHalfRoom; i++)
			rooms->push_back(Room(RoomType::LUX_PLUS, roomCounter++));
		
		// �� ������� �������, ��� ��� ���������� ������ ������������ ��������� ���� �� ������ ����� ���� �����������.
		prices->push_back(PriceList(RoomType::STD,			70.0));
		prices->push_back(PriceList(RoomType::DBL,			85.0));
		prices->push_back(PriceList(RoomType::DBL_PLUS,		100.0));
		prices->push_back(PriceList(RoomType::LUX,			85.0));
		prices->push_back(PriceList(RoomType::LUX_DBL,		105.0));
		prices->push_back(PriceList(RoomType::LUX_PLUS,		120.0));

		Status = OK;
		cout << "��������� � ��������� " << name << "��� ���������� ������ ������� ��������� ������������ � ��������� ������� �������!" << endl;
	}
}

Hotel::~Hotel() {
	cout << "��������� � ���������" << name << "������� �������" << endl;
}
/*���������� ��������*/
string Hotel::getName()
{
	if (Status == OK) return name;
	else return "";
}

int Hotel::getCountRooms() {
	if (Status == OK) return rooms->size();
	else return -1;
}

int Hotel::getCountStandardSingleRoom() {
	if (Status == OK) return getRoomsCount(RoomType::STD);
	else return -1;
}

int Hotel::getCountStandardDoubleRoom() {
	if (Status == OK) return getRoomsCount(RoomType::DBL);
	else return -1;
}


int Hotel::getCountStandardDoubleAndHalfRoom() {
	if (Status == OK) return getRoomsCount(RoomType::DBL_PLUS);
	else return -1;
}

int Hotel::getCountLuxurySingleRoom() {
	if (Status == OK) return getRoomsCount(RoomType::LUX);
	else return -1;
}

int Hotel::getCountLuxuryDoubleRoom() {
	if (Status == OK) return getRoomsCount(RoomType::LUX_DBL);
	else return -1;
}


int Hotel::getCountLuxuryDoubleAndHalfRoom() {
	if (Status == OK) return getRoomsCount(RoomType::LUX_PLUS);
	else return -1;
}

float Hotel::getPriceStandardSingleRoom() {
	if (Status == OK) return getRoomPrice(RoomType::STD);
	else return -1;
}

float Hotel::getPriceStandardDoubleRoom() {
	if (Status == OK) return getRoomPrice(RoomType::DBL);
	else return -1;
}

float Hotel::getPriceStandardDoubleAndHalfRoom() {
	if (Status == OK) return getRoomPrice(RoomType::DBL_PLUS);
	else return -1;
}

float Hotel::getPriceLuxurySingleRoom() {
	if (Status == OK) return getRoomPrice(RoomType::LUX);
	else return -1;
}

float Hotel::getPriceLuxuryDoubleRoom() {
	if (Status == OK) return getRoomPrice(RoomType::LUX_DBL);
	else return -1;
}

float Hotel::getPriceLuxuryDoubleAndHalfRoom() {
	if (Status == OK) return getRoomPrice(RoomType::LUX_PLUS);
	else return -1;
}

vector<Room> Hotel::getFreeRooms(RoomType _type, time_t startdate, time_t enddate)
{
	// ����� ������
	return vector<Room>();
}

bool Hotel::reserveRoom(Room & room, float pricePerNight, string owner, time_t startdate, time_t enddate)
{
	// TODO: ideally we need to check if room is available
	Reservation r(owner, room.number, pricePerNight, startdate, enddate);
	reservations->push_back(r);
	return true;
}

int Hotel::getRoomsCount(RoomType type)
{
	int retVal = 0;
	for (int i = 0; i < rooms->size(); i++)
	{
		Room r = rooms->at(i);
		if (r.type == type) retVal++;
	}
	return retVal;
}

float Hotel::getRoomPrice(RoomType type)
{
	for (int i = 0; i < prices->size(); i++)
	{
		PriceList pl = prices->at(i);
		if (pl.roomType == type) return pl.price;
	}
	return 0.0F;
}

ostream& operator << (ostream &os, Hotel* &pr)
{
	if (pr->Status == Error)
	{
		return cout;
	}
	cout << "���������� � ���������:";
	cout << "��������: " << pr->name << endl;
	cout << "���������� ����������� ����������� �������: " << pr->getCountStandardSingleRoom() << endl;
	cout << "���������� ����������� ����������� �������: " << pr->getCountStandardDoubleRoom() << endl;
	cout << "���������� ����������� ����������� ������� � ����������� �������: " << pr->getCountStandardDoubleAndHalfRoom() << endl;
	cout << "���������� �������� ����������� �������: " << pr->getCountLuxurySingleRoom() << endl;
	cout << "���������� �������� ����������� �������: " << pr->getCountLuxuryDoubleRoom() << endl;
	cout << "���������� �������� ����������� ������� � ����������� �������: " << pr->getCountLuxuryDoubleAndHalfRoom() << endl;
	cout << "���� ����������� ����������� �������: " << pr->getPriceStandardSingleRoom() << endl;
	cout << "���� ����������� ����������� �������: " << pr->getPriceStandardDoubleRoom() << endl;
	cout << "���� ����������� ����������� ������� � ����������� �������: " << pr->getPriceStandardDoubleAndHalfRoom() << endl;
	cout << "���� �������� ����������� �������: " << pr->getPriceLuxurySingleRoom() << endl;
	cout << "���� �������� ����������� �������: " << pr->getPriceLuxuryDoubleRoom() << endl;
	cout << "���� �������� ����������� ������� � ����������� �������: " << pr->getPriceLuxuryDoubleAndHalfRoom() << endl;
	cout << "_______________________________________________________________" << endl;
	cout << endl;
}