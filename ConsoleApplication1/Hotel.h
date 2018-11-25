#pragma once

#include <string>
#include <iostream>
#include <iomanip>
#include <vector>

#include "common.h"
#include "Room.h"
#include "Reservation.h"
#include "PriceList.h"

using namespace std;

enum StatusErr
{
	OK, Error
};

/*
 * �������� �����. ������-������.
 */
class Hotel {

public:

	vector<Room> *rooms;				// �������� ���� �����
	vector<PriceList> *prices;			// ���� �� ������ �� ����������
	vector<Reservation> *reservations;	// ������ �������������� �������

	Hotel() { Status = Error; } //����������� ������ �� ���������
	/*� ����������� ����� �������� ���������, ���������� ���� �����, ���������� ����������� �������, ���������� �������� �������,
	���������� ���������� �������, ���������� ����������� �������, ���������� ����������� ������� � ���������� �������.*/
	Hotel(string _name, int _countStandardSingleRoom, int _countStandardDoubleRoom, int _countStandardDoubleAndHalfRoom,
		int _countLuxurySingleRoom, int _countLuxuryDoubleRoom, int _countLuxuryDoubleAndHalfRoom);
	~Hotel();
	friend ostream& operator << (ostream &os, Hotel* &pr);

	/*�������*/
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

	// ����� ���������� ������ ��������� ������ �� �������� ��������: ���� � ���
	// ���� ��� ������ ������� ���� �� ������ ���� - ������� ������� ������� ����
	vector<Room> getFreeRooms(RoomType _type /*startdate, enddate*/);

	// ����� ��������� �������������� ������� �� ��������� ���� � 
	bool reserveRoom(Room &room, float pricePerNight, string owner /*startdate enddate*/);

private:
	int Status;
	string name;

	int getRoomsCount(RoomType type); // ���������� ����� �������� ���������� ������ ������������ ����
	float getRoomPrice(RoomType type); // ���������� ����� ������ ���� �� ��������� ��� ������
};

