#include "stdafx.h"
#include "Player.h"


Player::Player() : GameObject("Player1", "You", new std::string[2]{ "me", "inventory" })
{
	description = "You are Carrying: \n";
}

Player::Player(std::string name, std::string desc) : GameObject(name, desc, new std::string[2]{"me", "inventory"})
{
	description = desc;
	shortdesc = "You";
}

Player::~Player()
{
	delete this;
}

std::string Player::FullDesc()
{
	return  description + inv->ItemList();
}

GameObject * Player::Locate(std::string aId)
{
	GameObject* result = NULL;

	if (AreYou(aId))
	{
		result = this;
	}
	else 
	{
		result = &inv->Fetch(aId);
	}

	return result;
}

const int Player::hp()
{
	return fhp;
}

const int Player::score()
{
	return fscore;
}

const bool Player::alive()
{
	return falive;
}

const int Player::moves()
{
	return fmoves;
}

const MapNode* Player::currentLocation()
{
	return flocation;
}

void Player::setLocation(MapNode* aLocation)
{
	flocation = aLocation;
}

void Player::go(std::string aPlace) 
{
	if (aPlace == "n" || "up" || "north")
	{
		if (flocation->fneighbor[0] != NULL) 
		{
			flocation = flocation->fneighbor[0];
		}
		else 
		{
			std::cout << "Cant go that way" << std::endl;
		}
		
	}
	else if (aPlace == "right" || "east" || "e")
	{
		if (flocation->fneighbor[1] != NULL)
		{
			flocation = flocation->fneighbor[1];
		}
		else
		{
			std::cout << "Cant go that way" << std::endl;
		}
	}
	else if (aPlace == "s" || "down" || "south")
	{
		if (flocation->fneighbor[2] != NULL)
		{
			flocation = flocation->fneighbor[2];
		}
		else
		{
			std::cout << "Cant go that way" << std::endl;
		}
	}
	else if (aPlace == "w" || "left" || "west")
	{
		if (flocation->fneighbor[3] != NULL)
		{
			flocation = flocation->fneighbor[3];
		}
		else
		{
			std::cout << "Cant go that way" << std::endl;
		}
	}
	else
	{
		std::cout << "Not a place" << std::endl;
	}
}