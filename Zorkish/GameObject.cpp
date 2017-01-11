#include "stdafx.h"
#include "GameObject.h"

GameObject::GameObject(std::string aName, std::string aDesc, std::string aId[2]) : IdeableObject(aId)
{
	fIdObject = new IdeableObject(aId);
	fDamage = new Damage();
	fName = aName;
	fDescription = aDesc;
	fShortdesc = fName + "(" + FirstId() + ")";
	fResistance = new Resistance();
}

GameObject::GameObject(std::string aName, std::string aDesc, std::string aId[2], Damage* aDmg) : IdeableObject(aId)
{
	fIdObject = new IdeableObject(aId);
	fDamage = aDmg;
	fName = aName;
	fDescription = aDesc;
	fShortdesc = fName + "(" + FirstId() + ")";
	fResistance = new Resistance();
}

GameObject::GameObject(std::string aName, std::string aDesc, std::string aId[2], Damage* aDmg, Resistance* aResistance) : IdeableObject(aId)
{
	fIdObject = new IdeableObject(aId);
	fDamage = aDmg;
	fName = aName;
	fDescription = aDesc;
	fShortdesc = fName + "(" + FirstId() + ")";
	fResistance = aResistance;
}

GameObject::~GameObject()
{
	delete fIdObject;
}

const Damage* GameObject::getDamage()
{
	return fDamage;
}

int GameObject::getFireResistance()
{
	return fResistance->getFireRes();
}

int GameObject::getIceResistance()
{
	return fResistance->getIceRes();
}

int GameObject::getLightningResistance()
{
	return fResistance->getLightningRes();
}

int GameObject::getDarkResistance()
{
	return fResistance->getDarkRes();
}

void GameObject::update()
{
	std::string lMessage = "";
	if (!bMessages.empty())
	{
		lMessage = bMessages.front();
		bMessages.erase(bMessages.begin());

		if (lMessage == "look")
		{
			std::cout << fName + "\t" + getFullDesc() << std::endl;
		}
	}
}

void GameObject::addBMessage(std::string aMessage)
{
	bMessages.push_back(aMessage);
}