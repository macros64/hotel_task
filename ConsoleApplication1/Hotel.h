#pragma once
#define _CRT_SECURE_NO_WARNINGS
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
 * �������� �����. ������-������.
 */
class Hotel {

public:

	vector<Room> *rooms;				// �������� ���� �����
	map <RoomType, float> *prices;
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
	vector<Room> getFreeRooms(RoomType _type, time_t startdate, time_t enddate);

	// ����� ��������� �������������� ������� �� ��������� ���� � 
	Reservation* reserveRoom(Room &room, RoomType desiredRoomType, string owner, time_t startdate, time_t enddate);

	// ��������� �� �������� ����� � ��������� ����
	void showStats(time_t date);

private:
	int Status;
	string name;

	int getRoomsCount(RoomType type); // ���������� ����� �������� ���������� ������ ������������ ����
	float getRoomPrice(RoomType type); // ���������� ����� ������ ���� �� ��������� ��� ������
	int getRoomsOccupied(RoomType type, time_t date); 
};

