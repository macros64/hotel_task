#include "pch.h"
#include "Reservation.h"

Reservation::Reservation(string owner, Room * room, float price, time_t start, time_t end)
{
	roomOwner = owner;
	roomNumber = room->number;
	roomType = room->type;
	pricePerNight = price;
	startDate = start;
	endDate = end;
	reservationCreatedTime = time(NULL);

	switch (roomType)
	{
	case RoomType::STD:
		roomTypeStr = "STD";
		break;
	case RoomType::DBL:
		roomTypeStr = "DBL";
		break;
	case RoomType::DBL_PLUS:
		roomTypeStr = "DBL_PLUS";
		break;
	case RoomType::LUX:
		roomTypeStr = "LUX";
		break;
	case RoomType::LUX_DBL:
		roomTypeStr = "LUX_DBL";
		break;
	case RoomType::LUX_PLUS:
		roomTypeStr = "LUX_PLUS";
		break;
	default:
		roomTypeStr = "ERR";
		break;
	}
}

Reservation::Reservation()
{
}


Reservation::~Reservation()
{
}

ostream& operator<<(ostream& os, const Reservation &r)
{
	char *start_tm = new char[11], *end_tm = new char[11];
	struct tm *_start = localtime(&r.startDate);
	struct tm *_end = localtime(&r.endDate);
	strftime(start_tm, 11, "%Y-%m-%d", _start);
	strftime(end_tm, 11, "%Y-%m-%d", _end);
	os << "Room " << r.roomNumber 
		<<"("<< r.roomTypeStr <<")"
		<< " was reserver for " << r.roomOwner 
		<< " from " << start_tm
		<< " to " << end_tm
		<< ". Price: " << r.pricePerNight;
	return os;
}