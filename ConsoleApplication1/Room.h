#pragma once

#include "common.h"

/*
 * сущность комнаты отеля
 */
class Room
{

public:
	RoomType type; // тип комнаты, см common.h
	int number; // номер комнаты, можно было сделать строку, но лень =)

	Room();
	Room(RoomType tp, int num) { type = tp; number = num; }
	~Room();
};

