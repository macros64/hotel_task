#include "pch.h"
#include "Modeller.h"


vector<string> namesList = { "Aaron", "Abraham", "Adam", "Adrian", "Aidan", "Alan", "Albert", "Alejandro", "Alex", "Alexander",
"Alfred", "Andrew", "Angel", "Anthony", "Antonio", "Ashton", "Austin", "Ada", "Adelina", "Agatha",
"Bailey", "Barbara", "Beatrice", "Belinda", "Brianna", "Bridjet", "Brooke", "Benjamin", "Bernard", "Blake",
"Brandon", "Caleb", "Carter", "Chase", "Christian", "Clifford", "Cody", "Colin", "Curtis", "Cyrus",
"Daisy", "Danielle", "Deborah", "Delia", "Destiny", "Diana", "Dorothy", "Donald", "Douglas", "Dylan",
"Edward", "Elijah", "Eric", "Ethan", "Evan", "Gloria", "Gabriella", "Gabrielle", "Gladys", "Grace" };

vector<string> surnamesList = { "Abramson", "Adamson", "Adderiy", "Addington", "Adrian", "Albertson", "Aldridge", "Allford", "Alsopp", "Anderson",
						   "Blomfield", "Boolman", "Bootman", "Bosworth", "Bradberry", "Bradshaw", "Brickman", "Brooks", "Brown", "Bush",
						   "Calhoun",	"Campbell", "Carey", "Carrington", 	"Carroll", 	"Carter", "Chandter", "Chapman", "Charlson", "Chesterton",
						   "Daniels",	"Davidson",	"Day",	"Dean", "Derrick", "Dickinson",	"Dodson", "Donaldson",  "Donovan", "Douglas",
						   "Faber", "Fane", "Farmer", "Farrell",  "Ferguson",	"Finch", "Fisher", "Fitzgerald", "Flannagan", "Flatcher",
						   "Mathews",	"Mercer", "Michaelson", "Miers", "Miller", 	"Miln", "Milton", "Molligan", "Morrison", "Murphy" };


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
	return namesList.at(rand() % (namesList.size() - 1)) + " " + surnamesList.at(rand() % (surnamesList.size() - 1)) + "\0";
}

Modeller::Modeller(int k, int m, int clients)
{
	K = k, M = m, clientsCount = clients;
	initHotel();
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
		Reservation *r = _hotel->reserveRoom(rooms[0], RoomType::STD, _owner, _start, _end);

		clients++; // we need to increase overall clients count
		cout << *r << endl;
	}
}

void Modeller::printResults()
{
	cout << "–езультаты моделировани€" << endl;
}
