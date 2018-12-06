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
		rooms = new vector<Room>();
		prices = new map<RoomType, float>();
		reservations = new vector<Reservation>();

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
		prices->insert(make_pair(RoomType::STD, 70.0));
		prices->insert(make_pair(RoomType::DBL, 85.0));
		prices->insert(make_pair(RoomType::DBL_PLUS, 100.0));
		prices->insert(make_pair(RoomType::LUX, 85.0));
		prices->insert(make_pair(RoomType::LUX_DBL, 105.0));
		prices->insert(make_pair(RoomType::LUX_PLUS, 120.0));

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
	vector<Room> retVal;

	while (retVal.size() < 1 && _type <= RoomType::LUX_PLUS)
	{
		for (int i = 0; i < rooms->size(); i++) 
		{
			vector<Reservation> roomReservations;
			Room room = rooms->at(i);
			if (room.type == _type) // our room type
			{
				// search all reservations
				for (int j = 0; j < reservations->size(); j++)
					if (reservations->at(j).roomNumber == room.number)
						roomReservations.push_back(reservations->at(j));

				// analyze reservations
				bool hasIntersection = false;
				for (int j = 0; j < roomReservations.size(); j++)
				{
					Reservation reserv = roomReservations.at(j);
					hasIntersection |= startdate >= reserv.startDate && startdate < reserv.endDate; // requested start date within some reservation period
					hasIntersection |= enddate >= reserv.startDate && enddate < reserv.endDate; // requested end date within some reservation period
					hasIntersection |= reserv.startDate <= startdate && reserv.endDate >= enddate; // requested interval includes reservation period
					hasIntersection |= reserv.startDate >= startdate && reserv.endDate <= enddate; // reservation period includes requested interval
				}

				if (!hasIntersection)
					retVal.push_back(room);
			}
		}
		// if no rooms found we have to change searchable rom type
		if (retVal.size() == 0)
			_type = (RoomType)(_type + 1);
	}

	return retVal;
}

Reservation* Hotel::reserveRoom(Room & room, RoomType desiredRoomType, string owner, time_t startdate, time_t enddate)
{
	// TODO: ideally we need to check if room is available
	float pricePerNight = getRoomPrice(room.type);
	float typeDiscount = (room.type - desiredRoomType) * 0.1; // 10% discount per 1 room level
	pricePerNight *= (1.0 - typeDiscount);

	Reservation *r = new Reservation(owner, &room, pricePerNight, startdate, enddate);
	reservations->push_back(*r);
	return r;
}

void Hotel::showStats(time_t date)
{
	cout << "Hotel load: "
		<< "STD: " << getRoomsOccupied(RoomType::STD, date) << "/" << getRoomsCount(RoomType::STD) << " "
		<< "DBL: " << getRoomsOccupied(RoomType::DBL, date) << "/" << getRoomsCount(RoomType::DBL) << " "
		<< "DBL+: " << getRoomsOccupied(RoomType::DBL_PLUS, date) << "/" << getRoomsCount(RoomType::DBL_PLUS) << " "
		<< "LUX: " << getRoomsOccupied(RoomType::LUX, date) << "/" << getRoomsCount(RoomType::LUX) << " "
		<< "LUX2: " << getRoomsOccupied(RoomType::LUX_DBL, date) << "/" << getRoomsCount(RoomType::LUX_DBL) << " "
		<< "LUX+: " << getRoomsOccupied(RoomType::LUX_PLUS, date) << "/" << getRoomsCount(RoomType::LUX_PLUS);


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
	if (prices->find(type) != prices->end())
		return prices->at(type);
	else 
		return -1.0F;
}

int Hotel::getRoomsOccupied(RoomType type, time_t date)
{
	// �� ���� ����� ���������� ������� �������� ����� ������ ���
	tm *day = localtime(&date);
	day->tm_hour = 0;
	day->tm_min = 0;
	day->tm_sec = 0;

	time_t start = mktime(day);
	time_t end = start + 3600 * 24 - 1; // ����� ���

	int counter = 0;
	for (int i = 0; i < reservations->size(); i++) // ���������� ���� �������� ����������
	{
		Reservation r = reservations->at(i);
		if (r.roomType == type &&
			r.startDate <= start &&
			r.endDate >= end)
			counter++;
	}

	return counter;
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