#include "stdafx.h"
#include "Player.h"

Player::Player() : Character("Player1", "You", new std::string[2]{ "me", "inv" })
{
	fDescription = "You are Carrying: \n";
	fDamage = new Damage(new int[4]{ 0,0,0,1 });
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