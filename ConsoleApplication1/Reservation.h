#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include "common.h"
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
	float pricePerNight;	// �������� ���� �� ����

	time_t startDate;		// ���� ������
	time_t endDate;			// ���� ������

	// ����� �������� ��������������
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

