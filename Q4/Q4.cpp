// Q4.cpp : Defines the entry point for the console application.
//
#pragma hdrstop
#include "stdafx.h"
#include <conio.h>
#include <iostream>

#include <string>
using namespace std;

class Wheel
{
public:
	Wheel() : pressure(32){ ptrSize = new int(32); }
	Wheel(int s, int p) : pressure(p){ ptrSize = new int(s); }
	~Wheel() { delete ptrSize; }

	void pump(int amount) { pressure += amount; }

private:
	int *ptrSize;
	int pressure;
};

class RacingCar
{
public:
	RacingCar() { RacingCar(0); }
	RacingCar(int);
	~RacingCar();
	RacingCar(const RacingCar &oldobject)
	{

	}

private:
	int speed;
	Wheel* carWheels[4];
};

RacingCar::RacingCar(int s)
{
	speed = s;
	for (int i = 0; i < 4; i++)
	{
		carWheels[i] = new Wheel();
	}

}

RacingCar :: ~RacingCar()
{

}

int _tmain(int argc, _TCHAR* argv[])
{
	RacingCar rc;
	RacingCar rc2( 5 );
	RacingCar *ptrRcar = new RacingCar(6);

	delete ptrRcar;
	return 0;
}

