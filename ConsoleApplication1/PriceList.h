#pragma once

#include "common.h"

/*
 * ���� �� ���������� ������
 */
class PriceList
{
public:
	RoomType roomType; // ��� �������. �� common.h
	float price;  // ���� �� ����� � ����������� ��������
public:
	PriceList();
	PriceList(RoomType _type, float _price) { roomType = _type; price = _price; }
	~PriceList();
};

