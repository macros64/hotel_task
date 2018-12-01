#include "pch.h"
#include "Reservation.h"

Reservation::Reservation()
{
}


Reservation::~Reservation()
{
}

ostream& operator <<(ostream& os, const Reservation &r)
{
	struct tm *_start = localtime(&r.startDate);
	struct tm *_end = localtime(&r.endDate);
	os << "Room " << r.roomNumber << " was reserver for " << r.roomOwner << " from " << asctime(_start) << " to " << asctime(_end) << ". Price: " << r.pricePerNight;
	return os;
}
