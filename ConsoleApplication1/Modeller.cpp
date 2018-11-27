#include "pch.h"
#include "Modeller.h"


void Modeller::initHotel()
{
	int std = 0, dbl = 0, dblp = 0, lux = 0, luxd = 0, luxp = 0;
	// стандартные пусть будут половина номеров от общего количества, остальные поровну из оставшихся.
	std = K / 2;
	luxp = K / 10; // (K/2)/5, 5 - оставшиеся категории номеров
	luxd = K / 10;
	lux = K / 10;
	dblp = K / 10;
	dbl = K - std - luxp - luxd - lux - dblp; // разница а не частное исключительно для того чтобы сумма сошлась
	
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
	cout << "Моделирование в процессе" << endl;
}

void Modeller::printResults()
{
	cout << "Результаты моделирования" << endl;
}
