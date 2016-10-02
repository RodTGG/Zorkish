#include "stdafx.h"
#include "Character.h"

using namespace Zorkish;

Character::Character(std::string aName, std::string aDesc, std::string aId[2]) : GameObject(aName, aDesc, aId)
{
	fInventory = new Container("myInventory","Your invetory", new std::string[2]{ "inv","Inv" });
}

Character::Character(std::string aName, std::string aDesc, std::string aId[2], Damage* aDmg) : GameObject(aName, aDesc, aId, aDmg)
{
	fInventory = new Container("myInventory", "Your invetory", new std::string[2]{ "inv","Inv" });
}


Character::Character(std::string aName, std::string aDesc, std::string aId[2], Damage* aDmg, int aResistance[4]) : GameObject(aName, aDesc, aId, aDmg, aResistance)
{
	fInventory = new Container("myInventory", "Your invetory", new std::string[2]{ "inv","Inv" });

}


Character::~Character()
{
}

void Character::updateCharacter()
{
	if (fHp <= 0)
	{
		fAlive = false;
	}
}

void Character::receiveDamage(Damage* aDamage)
{
	unsigned int resultDmg = 0;

	resultDmg += aDamage->getFireDmg() - getFireResistance();
	resultDmg += aDamage->getIceDmg() - getIceResistance();
	resultDmg += aDamage->getLightningDmg() - getLightningResistance();
	resultDmg += aDamage->getDarkDmg() - getDarkResistance();

	fHp -= resultDmg;
}

std::string Character::getFullDesc()
{
	return  fName + "\n" + fDescription + fInventory->getFullDesc();
}

GameObject * Character::Locate(std::string aId)
{
	GameObject* result = NULL;

	if (AreYou(aId))
	{
		result = this;
	}
	else
	{
		if (fInventory->HasItem(aId))
		{
			result = fInventory->Fetch(aId);
		}
		else
		{
			result = NULL;
		}
	}

	return result;
}

void Character::setLocation(MapNode* aLocation)
{
	flocation = aLocation;
}

Container* Character::getInventory()
{
	return fInventory;
}

MapNode* Character::getLocation()
{
	return flocation;
}

const int Character::getHp()
{
	return fHp;
}

const bool Character::isAlive()
{
	return fAlive;
}