#include "stdafx.h"
#include "Player.h"

Player::Player() : Character("Mark", "A very pretty boy", new std::string[2]{ "me", "inv" })
{
	fDamage = new Damage(new int[4]{ 0,0,0,1 });
	fShortdesc = "You";
}

Player::Player(std::string aName, std::string aDesc) : Character(aName, aDesc, new std::string[2]{ "me", "inv" })
{
	fDescription = aDesc;
	fShortdesc = "You";
}

Player::~Player()
{
	delete this;
}

const int Player::getScore()
{
	return fScore;
}

const int Player::getMoves()
{
	return fMoves;
}