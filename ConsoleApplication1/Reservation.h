#pragma once

#include "common.h"
#include <string>

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
	// start date here
	// end date here

	Reservation();
	~Reservation();
};

