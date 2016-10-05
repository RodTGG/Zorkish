#include "stdafx.h"
#include "Resistance.h"

Resistance::Resistance()
{
	for (unsigned int i = 0; i < 4; i++)
	{
		fRes[i] = 0;
	}
}

Resistance::Resistance(int aRes[4])
{
	for (unsigned int i = 0; i < 4; i++)
	{
		fRes[i] = aRes[i];
	}
}

Resistance::~Resistance()
{
}

int Resistance::getFireRes()
{
	return fRes[0];
}

int Resistance::getIceRes()
{
	return fRes[1];
}

int Resistance::getLightningRes()
{
	return fRes[2];
}

int Resistance::getDarkRes()
{
	return fRes[3];
}

void Resistance::setFireRes(int aResistance)
{
	fRes[0] = aResistance;
}

void Resistance::setIceRes(int aResistance)
{
	fRes[1] = aResistance;
}

void Resistance::setLightningRes(int aResistance)
{
	fRes[2] = aResistance;
}

void Resistance::setDarkRes(int aResistance)
{
	fRes[3] = aResistance;
}
