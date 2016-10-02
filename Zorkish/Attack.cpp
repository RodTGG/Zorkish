#include "stdafx.h"
#include "Attack.h"

using namespace Zorkish;

Attack::Attack(std::string aName) : Command(aName)
{
}

Attack::~Attack()
{
}

std::string Attack::Execute(Player* p, std::vector<std::string> aText)
{
	std::string result = "";

	if (aText.size() > 2 && aText.size() <= 4)
	{
		
	}
	if (aText.size() == 2)
	{
		if (aText[2].length() == 0)
		{
			result = "What do you want to " + aText[0] + "?";
		}
		else
		{
			result = AttackAt(p, aText[2]);
		}
	}
	else if (aText.size() == 1)
	{
		result = "You look in your book but cant seem to find that combo.";
	}
	else
	{
		result = "well that aint right...";
	}

	return result;
}

std::string Attack::AttackAt(Player* aPlayer, std::string aObject)
{
	std::string result = "";

	if (aPlayer->getLocation()->fCharacters->hasChar(aObject)) 
	{
	
	}

	return result;
}