#include "pch.h"
#include "Hotel.h"


Hotel::Hotel(string _name, int _countRooms, int _countStandardSingleRoom, int _countStandardDoubleRoom, int _countStandardDoubleAndHalfRoom,
	int _countLuxurySingleRoom, int _countLuxuryDoubleRoom, int _countLuxuryDoubleAndHalfRoom) { /*�������� ��������, �� ����� ��� �� ����� ��� ��� ��� ���������� �������� �� ��������� ���������*/
	if (_name == "" || _countRooms < 20 || _countRooms > 30) {
		Status = Error;
	}
	else {
		name = _name;
		countRooms = _countRooms;
		countStandardSingleRoom = _countStandardSingleRoom;
		countStandardDoubleRoom = _countStandardDoubleRoom;
		countStandardDoubleAndHalfRoom = _countStandardDoubleAndHalfRoom;
		countLuxurySingleRoom = _countLuxurySingleRoom;
		countLuxuryDoubleRoom = _countLuxuryDoubleRoom;
		countLuxuryDoubleAndHalfRoom = _countLuxuryDoubleAndHalfRoom;
		/*�� ������� �������, ��� ��� ���������� ������ ������������ ��������� ���� �� ������ ����� ���� �����������.*/
		priceStandardSingleRoom = 70;
		priceStandardDoubleRoom = 85;
		priceStandardDoubleAndHalfRoom = 100;
		priceLuxurySingleRoom = 85;
		priceLuxuryDoubleRoom = 105;
		priceLuxuryDoubleAndHalfRoom = 120;
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
	if (Status == OK) return countRooms;
	else return -1;
}

int Hotel::getCountStandardSingleRoom() {
	if (Status == OK) return countStandardSingleRoom;
	else return -1;
}

int Hotel::getCountStandardDoubleRoom() {
	if (Status == OK) return countStandardDoubleRoom;
	else return -1;
}


int Hotel::getCountStandardDoubleAndHalfRoom() {
	if (Status == OK) return countStandardDoubleAndHalfRoom;
	else return -1;
}

int Hotel::getCountLuxurySingleRoom() {
	if (Status == OK) return countLuxurySingleRoom;
	else return -1;
}

int Hotel::getCountLuxuryDoubleRoom() {
	if (Status == OK) return countLuxuryDoubleRoom;
	else return -1;
}


int Hotel::getCountLuxuryDoubleAndHalfRoom() {
	if (Status == OK) return countLuxuryDoubleAndHalfRoom;
	else return -1;
}

int Hotel::getPriceStandardSingleRoom() {
	if (Status == OK) return priceStandardSingleRoom;
	else return -1;
}

int Hotel::getPriceStandardDoubleRoom() {
	if (Status == OK) return priceStandardDoubleRoom;
	else return -1;
}

int Hotel::getPriceStandardDoubleAndHalfRoom() {
	if (Status == OK) return priceStandardDoubleAndHalfRoom;
	else return -1;
}

int Hotel::getPriceLuxurySingleRoom() {
	if (Status == OK) return priceLuxurySingleRoom;
	else return -1;
}

int Hotel::getPriceLuxuryDoubleRoom() {
	if (Status == OK) return priceLuxuryDoubleRoom;
	else return -1;
}

int Hotel::getPriceLuxuryDoubleAndHalfRoom() {
	if (Status == OK) return priceLuxuryDoubleAndHalfRoom;
	else return -1;
}

ostream& operator << (ostream &os, Hotel* &pr)
{
	if (pr->Status == Error)
	{
		return cout;
	}
	cout << "���������� � ���������:";
	cout << "��������: " << pr->name << endl;
	cout << "���������� ����������� ����������� �������: " << pr->countStandardSingleRoom << endl;
	cout << "���������� ����������� ����������� �������: " << pr->countStandardDoubleRoom << endl;
	cout << "���������� ����������� ����������� ������� � ����������� �������: " << pr->countStandardDoubleAndHalfRoom << endl;
	cout << "���������� �������� ����������� �������: " << pr->countLuxurySingleRoom << endl;
	cout << "���������� �������� ����������� �������: " << pr->countLuxuryDoubleRoom << endl;
	cout << "���������� �������� ����������� ������� � ����������� �������: " << pr->countLuxuryDoubleAndHalfRoom << endl;
	cout << "���� ����������� ����������� �������: " << pr->priceStandardSingleRoom << endl;
	cout << "���� ����������� ����������� �������: " << pr->priceStandardDoubleRoom << endl;
	cout << "���� ����������� ����������� ������� � ����������� �������: " << pr->priceStandardDoubleAndHalfRoom << endl;
	cout << "���� �������� ����������� �������: " << pr->priceLuxurySingleRoom << endl;
	cout << "���� �������� ����������� �������: " << pr->priceLuxuryDoubleRoom << endl;
	cout << "���� �������� ����������� ������� � ����������� �������: " << pr->priceLuxuryDoubleAndHalfRoom << endl;
	cout << "_______________________________________________________________" << endl;
	cout << endl;
}