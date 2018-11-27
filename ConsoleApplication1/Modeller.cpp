#include "pch.h"
#include "Modeller.h"


void Modeller::initHotel()
{
	int std = 0, dbl = 0, dblp = 0, lux = 0, luxd = 0, luxp = 0;
	// ����������� ����� ����� �������� ������� �� ������ ����������, ��������� ������� �� ����������.
	std = K / 2;
	luxp = K / 10; // (K/2)/5, 5 - ���������� ��������� �������
	luxd = K / 10;
	lux = K / 10;
	dblp = K / 10;
	dbl = K - std - luxp - luxd - lux - dblp; // ������� � �� ������� ������������� ��� ���� ����� ����� �������
	
	_hotel = new Hotel("test hotel", std, dbl, dblp, lux, luxd, luxp);
}

Modeller::Modeller()
{
}


Modeller::~Modeller()
{
}

void Modeller::doModelling()
{
	cout << "������������� � ��������" << endl;
}

void Modeller::printResults()
{
	cout << "���������� �������������" << endl;
}
