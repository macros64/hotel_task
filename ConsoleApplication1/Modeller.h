#pragma once
/*
 * ����� ����������� ������������� ������ �����
 */

#include "common.h"
#include "Hotel.h"

class Modeller
{
private:

	Hotel *_hotel;
	void initHotel();
	string getRandomClientName();
public:
	int K;				// ����� ���������� ������� � �����
	int M;				// ������ ������������� � ����
	int clientsCount;	// ����� ���������� ��������

	Modeller(int k, int m, int clients) { K = k, M = m, clientsCount = clients; }
	Modeller();
	~Modeller();

	void doModelling();
	void printResults();
};

