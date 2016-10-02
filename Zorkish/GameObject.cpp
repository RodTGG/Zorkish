#include "stdafx.h"
#include "GameObject.h"

using namespace Zorkish;

GameObject::GameObject(std::string aName, std::string aDesc, std::string aId[2]) : IdeableObject(aId)
{
	fIdObject = new IdeableObject(aId);
	fDamage = new Damage();
	fName = aName;
	fDescription = aDesc;
	fShortdesc = fName + "(" + FirstId() + ")";

	for (unsigned int i = 0; i < 4; i++)
	{
		fResistances[i] = 0;
	}
}

GameObject::GameObject(std::string aName, std::string aDesc, std::string aId[2], Damage* aDmg) : IdeableObject(aId)
{
	fIdObject = new IdeableObject(aId);
	fDamage = aDmg;
	fName = aName;
	fDescription = aDesc;
	fShortdesc = fName + "(" + FirstId() + ")";

	for (unsigned int i = 0; i < 4; i++)
	{
		fResistances[i] = 0;
	}
}

GameObject::GameObject(std::string aName, std::string aDesc, std::string aId[2], Damage* aDmg, int aResistance[4]) : IdeableObject(aId)
{
	fIdObject = new IdeableObject(aId);
	fDamage = aDmg;
	fName = aName;
	fDescription = aDesc;
	fShortdesc = fName + "(" + FirstId() + ")";

	for (unsigned int i = 0; i < 4; i++)
	{
		fResistances[i] = aResistance[i];
	}
}

GameObject::~GameObject()
{
	delete fIdObject;
}

Damage* GameObject::getDamage()
{
	return fDamage;
}

int GameObject::getFireResistance()
{
	return fResistances[0];
}

int GameObject::getIceResistance()
{
	return fResistances[1];
}

int GameObject::getLightningResistance()
{
	return fResistances[2];
}

int GameObject::getDarkResistance()
{
	return fResistances[3];
}