#pragma once

#include "common.h"

/*
 * цены по категориям комнат
 */
class PriceList
{
public:
	RoomType roomType; // тип комнаты. см common.h
	float price;  // цена за номер в монгольских тугриках
public:
	PriceList();
	PriceList(RoomType _type, float _price) { roomType = _type; price = _price; }
	~PriceList();
};

