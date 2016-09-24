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

MapNode* Player::currentLocation()
{
	return flocation;
}

void Player::setLocation(MapNode* aLocation)
{
	flocation = aLocation;
}