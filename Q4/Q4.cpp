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
	int getPressure() { return pressure; }

private:
	int *ptrSize;
	int pressure;
};

class RacingCar
{
public:
	RacingCar();
	RacingCar(int);
	RacingCar(const RacingCar &oldobject);
	Wheel *getWheel(int wheel) { return carWheels[wheel]; }
	void printCar();
	~RacingCar();

private:
	int speed;
	RacingCar *carbonCopy;
	Wheel* carWheels[4];
};

RacingCar::RacingCar()
{
	speed = 0;
	for (int i = 0; i < 4; i++)
	{
		carWheels[i] = new Wheel();
	}
}

RacingCar::RacingCar(int s)
{
	speed = s;
	for (int i = 0; i < 4; i++)
	{
		carWheels[i] = new Wheel();
	}
}

RacingCar::RacingCar(const RacingCar &oldobject)
{
	speed = oldobject.speed;
	for (int i = 0; i < 4; i++)
	{
		carWheels[i] = new Wheel(32, oldobject.carWheels[i] ->getPressure() );
	}
}

void RacingCar::printCar()
{
	cout << "Wheel pressure: " << endl;
	for (int i = 0; i < 4; i++)
	{
		printf("Wheel no.%i = %i \n", i+1, carWheels[i] ->getPressure() );
	}
	cout << endl;
}

RacingCar :: ~RacingCar()
{

}

int _tmain(int argc, _TCHAR* argv[])
{
	RacingCar *rc = new RacingCar;
	RacingCar *rc2 = new RacingCar( 5 );
	RacingCar *ptrRcar = new RacingCar(6);

	cout << "Racing Car - rc" << endl;
	rc->printCar();

	RacingCar rcCopy = *rc;
	cout << "Racing Car - rcCopy" << endl;
	rcCopy.printCar();

	//pump air into 3 wheel of car rc
	rc -> getWheel(2) ->pump(20);
	rc -> getWheel(3) ->pump(-20);
	
	cout << "Racing Car - rc" << endl;
	rc->printCar();
	cout << "Racing Car - rcCopy" << endl;
	rcCopy.printCar();

	delete ptrRcar;
	delete rc;
	delete rc2;
	_getch();
	return 0;
}

