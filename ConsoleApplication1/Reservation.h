#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include "common.h"
#include "Room.h"
#include <string>
#include <ctime>

using namespace std;

/*
 * ������ �������������� �������
 */
class Reservation
{
public:

	string roomOwner;		// ��������� ���������
	int roomNumber;			// ����� ���������������� �������
	RoomType roomType;
	string roomTypeStr;
	float pricePerNight;	// �������� ���� �� ����

	time_t startDate;		// ���� ������
	time_t endDate;			// ���� ������

	// ����� �������� ��������������
	time_t reservationCreatedTime;

	Reservation(string owner, Room* room, float price, time_t start, time_t end);
	Reservation();
	~Reservation();
	friend ostream& operator<<(ostream& os, const Reservation &r);
};

