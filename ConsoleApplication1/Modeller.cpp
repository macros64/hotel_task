#include "pch.h"
#include "Modeller.h"


void Modeller::initHotel()
{
	int std = 0, dbl = 0, dblp = 0, lux = 0, luxd = 0, luxp = 0;
	// стандартные пусть будут половина номеров от общего количества, остальные поровну из оставшихс€.
	std = K / 2;
	luxp = K / 10; // (K/2)/5, 5 - оставшиес€ категории номеров
	luxd = K / 10;
	lux = K / 10;
	dblp = K / 10;
	dbl = K - std - luxp - luxd - lux - dblp; // разница а не частное исключительно дл€ того чтобы сумма сошлась
	
	_hotel = new Hotel("test hotel", std, dbl, dblp, lux, luxd, luxp);
}

string Modeller::getRandomClientName()
{
	string s;
	int len = 10;
	char alphabet[] = "0123456789"
		"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
		"abcdefghijklmnopqrstuvwxyz";

	for (int i = 0; i < len; ++i) {
		s += alphabet[rand() % (sizeof(alphabet) - 1)];
	}

	s += '\0';
	return s;
}

Modeller::Modeller()
{
	initHotel();
}


Modeller::~Modeller()
{
}

void Modeller::doModelling()
{
	int day = 0, clients = 0;
	int clientsPerDay = clientsCount / M;
	cout << "Ќачинаем моделирование." << endl;

	time_t _now = time(NULL);
	int seconds_per_day = 3600 * 24;

	while (day < M && clients < clientsCount) {
		time_t _start = _now + day * seconds_per_day;
		time_t _end = _start + 2 * seconds_per_day;
		string _owner = getRandomClientName();

		vector<Room> rooms = _hotel->getFreeRooms(RoomType::STD, _start, _end);
		Reservation r = _hotel->reserveRoom(rooms[0], RoomType::STD, _owner, _start, _end);

		clientsCount++; // we need to increase overall clients count
		cout << &r << endl;
	}
}

void Modeller::printResults()
{
	cout << "–езультаты моделировани€" << endl;
}
