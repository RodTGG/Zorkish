#include "stdafx.h"
#include "Item.h"

using namespace Zorkish;

Item::Item(std::string name, std::string desc, std::string idents[2]) : GameObject(name, desc, idents)
{
}

Item::Item(std::string name, std::string desc, std::string idents[2], Damage* aDmg) : GameObject(name, desc, idents, aDmg)
{
}

Item::~Item()
{
}

std::string Item::getFullDesc()
{
	return fDescription;
}