#include "stdafx.h"
#include "Item.h"

Item::Item(std::string name, std::string idents[]) : GameObject(name, idents)
{
}

Item::Item(std::string name, std::string desc, std::string idents[]) : GameObject(name, desc, idents)
{
}

Item::~Item()
{
}

std::string Item::fullDesc()
{
	return fdescription;
}