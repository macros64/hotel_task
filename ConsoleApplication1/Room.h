#pragma once

#include "common.h"

/*
 * �������� ������� �����
 */
class Room
{

public:
	RoomType type; // ��� �������, �� common.h
	int number; // ����� �������, ����� ���� ������� ������, �� ���� =)

	Room();
	Room(RoomType tp, int num) { type = tp; number = num; }
	~Room();
};

