#include "stdafx.h"
#include "Attack.h"

Attack::Attack(std::string aName) : Command(aName)
{
}

Attack::~Attack()
{
}

/// <summary>
/// Executes command
/// Two possible combinations, Attack object and Attack object with.
/// </summary>
/// <param name="p">The p.</param>
/// <param name="aText">a text.</param>
/// <returns>result</returns>
std::string Attack::Execute(Player* p, std::vector<std::string> aText)
{
	std::string result = "";

	if (aText.size() > 2 && aText.size() <= 4)							// Checks which version to use
	{
		if (aText[2] != "with")
		{
			result = aText[2] + "? try typing with.";
		}
		else
		{
			result = AttackWith(p, aText[1], aText[3]);
		}
	}
	else if (aText.size() == 2)
	{
		if (aText[1].length() == 0)
		{
			result = "What do you want to " + aText[0] + "?";
		}
		else
		{
			result = AttackWith(p, aText[1]);
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

std::string Attack::AttackWith(Player* aPlayer, std::string aObject)
{
	std::string result = "";

	if (aPlayer->getLocation()->fCharacters->hasChar(aObject))
	{
		aPlayer->getLocation()->fCharacters->getChar(aObject)->receiveDamage(aPlayer->getDamage());
		aPlayer->receiveDamage(aPlayer->getLocation()->fCharacters->getChar(aObject)->getDamage());

		result = "You attack " + aObject + "\n";
		result += std::to_string(aPlayer->getLocation()->fCharacters->getChar(aObject)->getHp());
	}
	else
	{
		result = "No " + aObject + " around!";
	}

	return result;
}

std::string Attack::AttackWith(Player* aPlayer, std::string aObject, std::string aItem)
{
	std::string result = "";

	return result;
}