#include "stdafx.h"
#include "Damage.h"

using namespace Zorkish;

Damage::Damage()
{
	for (unsigned int i = 0; i < 4; i++)
	{
		fDmg[i] = 0;
	}
}

Damage::Damage(int aDmg[4])
{
	for (unsigned int i = 0; i < 4; i++) 
	{
		fDmg[i] = aDmg[i];
	}
}

Damage::~Damage()
{
}

int Damage::getFireDmg()
{
	return fDmg[0];
}

int Damage::getIceDmg()
{
	return fDmg[1];
}

int Damage::getLightningDmg()
{
	return fDmg[2];
}

int Damage::getDarkDmg()
{
	return fDmg[3];
}

void Damage::setFire(int aDamage)
{
	fDmg[0] = aDamage;
}

void Damage::setIce(int aDamage)
{
	fDmg[1] = aDamage;
}

void Damage::setLightning(int aDamage)
{
	fDmg[2] = aDamage;
}

void Damage::setDark(int aDamage)
{
	fDmg[3] = aDamage;
}