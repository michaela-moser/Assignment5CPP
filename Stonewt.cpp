#include "Stonewt.h"

Stonewt::Stonewt(double pounds, Mode myMode) {
	stone = int(pounds) / LBS_PER_STONE;   
	pdsLeft = int(pounds) % LBS_PER_STONE + pounds - int(pounds);
	pounds = pounds;
	mode = myMode;
}
Stonewt::Stonewt(int stone, double pounds, Mode myMode) {
	stone = stone;
	pdsLeft = pounds;
	pounds = stone * LBS_PER_STONE + pounds;
	mode = myMode;
}

Stonewt::Stonewt() {   
	stone = 0;
	pounds = pdsLeft = .0;
	mode = FLOAT_POUNDS;
}

Stonewt::~Stonewt() {      
}

void Stonewt::setMode(Mode m) {
	this->mode = m;
}

ostream & operator << (ostream & os, const Stonewt & stone) {
	if (stone.mode == Stonewt::STONE) {
		os << stone.stone << " stone, " << stone.pdsLeft << " pounds\n";
	}
	else if (stone.mode == Stonewt::FLOAT_POUNDS) {
		os << stone.pounds << " pounds\n";
	}
	else if (stone.mode == Stonewt::INT_POUNDS) {
		os << (int)stone.pounds << " full pounds\n";
	}
	else
		os << "\nYou're code is broken like your soul !\n";
	return os;
}

Stonewt & operator + (const Stonewt & stone1, const Stonewt & stone2) {
	double sumPounds = stone1.pounds + stone2.pounds;
	double sumStones = sumPounds / stone1.LBS_PER_STONE;
	double sumPoundsLeft = fmod(sumPounds, stone1.LBS_PER_STONE);
	if (stone1.mode == Stonewt::STONE) {
		Stonewt summ((int)sumStones, sumPoundsLeft);
		return  summ;
	}
	else if ((stone1.mode == INT_POUNDS) || (stone1.mode == FLOAT_POUNDS)) {
		Stonewt summ(sumPounds);
		return  summ;
	}
	else {
		cout << "You suck and your code is broken and no one loves you\n";
	}
}

Stonewt & operator - (const Stonewt & stone1, const Stonewt & stone2) {
	double sumPounds = stone1.pounds - stone2.pounds;
	double sumStones = sumPounds / stone1.LBS_PER_STONE;
	double sumPoundsLeft = fmod(sumPounds, stone1.LBS_PER_STONE);
	if (stone1.mode == Stonewt::STONE) {
		Stonewt sum((int)sumStones, sumPoundsLeft, Stonewt::STONE);
		return  sum;
	}
	else if ((stone1.mode == INT_POUNDS) || (stone1.mode == FLOAT_POUNDS)) {
		Stonewt sum(sumPounds, FLOAT_POUNDS);
		return  sum;
	}
	else {
		cout << "You should look into a new career choice cause clearly you can't code!!\n";
	}
}

Stonewt & operator * (const Stonewt & st1, const double n) {
	double sumPounds = st1.pounds * n;
	double sumStones = sumPounds / st1.LBS_PER_STONE;
	double sumPoundsLeft = fmod(sumPounds, st1.LBS_PER_STONE);
	if (st1.mode == Stonewt::STONE) {
		Stonewt sum((int)sumStones, sumPoundsLeft, Stonewt::STONE);
		return  sum;
	}
	else if ((st1.mode == INT_POUNDS) || (st1.mode == FLOAT_POUNDS)) {
		Stonewt sum(sumPounds, FLOAT_POUNDS);
		return  sum;
	}
	else {
		cout << "You suck again\n";
	}
}