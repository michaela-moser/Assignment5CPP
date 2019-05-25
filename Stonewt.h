#pragma once
#ifndef STONEWT_H_
#define STONEWT_H_
#include <iostream>
using namespace std;
enum my_Mode { STONE, INT_POUNDS, FLOAT_POUNDS };

class Stonewt {
public:
	enum Mode { STONE, INT_POUNDS, FLOAT_POUNDS };
	
	enum { LBS_PER_STONE = 14 };     
public:
	int stone;                    
	double pdsLeft;              
	double pounds;
	Mode mode;
public:
	Stonewt(double lbs, Mode mode = FLOAT_POUNDS);        
	Stonewt(int stone, double pounds, Mode mode = STONE); 
	Stonewt();                    
	~Stonewt();
	void setMode(Mode m);
	friend ostream & operator << (ostream & os, const Stonewt & st);
	friend Stonewt & operator + (const Stonewt & st1, const Stonewt & st2);
	friend Stonewt & operator - (const Stonewt & st1, const Stonewt & st2);
	friend Stonewt & operator * (const Stonewt & st1, const double n);
	friend Stonewt & operator * (const double a, const Stonewt & st1) {
		return st1 * a;
	};

};
#endif
