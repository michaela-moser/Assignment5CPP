#include "Mytime.h"

Time::Time() {
	hours = minutes = 0;
}

Time::Time(int anHour, int aMinute) {
	hours = anHour;
	minutes = aMinute;
}

void Time::AddMin(int a) {
	minutes += a;
	hours += minutes / 60;
	minutes %= 60;
}

void Time::AddHr(int anHour) {
	hours += anHour;
}

void Time::Reset(int anHour, int aMinute) {
	hours = anHour;
	minutes = aMinute;
}

Time operator+(const Time & a, const Time & b) {
	Time sum;
	sum.minutes = a.minutes + b.minutes;
	sum.hours = a.hours + b.hours + sum.minutes / 60;
	sum.minutes %= 60;
	return sum;
}

Time operator-(const Time & a, const Time & b) {
	Time diff;
	int total1, total2;
	total1 = a.minutes + 60 * a.hours;
	total2 = b.minutes + 60 * b.hours;
	diff.minutes = (total2 - total1) % 60;
	diff.hours = (total2 - total1) / 60;
	return diff;
}

Time operator*(const Time & t, const double m) {
	Time result;
	long totalminutes = t.hours * m * 60 + t.minutes * m;
	result.hours = totalminutes / 60;
	result.minutes = totalminutes % 60;
	return result;
}

std::ostream & operator<<(std::ostream & os, const Time & t) {
	os << t.hours << " hours, " << t.minutes << " minutes";
	return os;
}