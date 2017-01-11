#include "stdafx.h"
#include "AttackCommand.h"

AttackCommand::AttackCommand(std::string aName) : Command(aName)
{
}

AttackCommand::~AttackCommand()
{
}

/// <summary>
/// Executes command
/// Two possible combinations, Attack object and Attack object with.
/// </summary>
/// <param name="p">The p.</param>
/// <param name="aText">a text.</param>
/// <returns>result</returns>
std::string AttackCommand::Execute(Player* p, std::vector<std::string> aText)
{
	std::string result = "";

	if (aText.size() > 2 && aText.size() <= 4)
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
			result = Attack(p, aText[1]);
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

/// <summary>
/// Executes command
/// Receives attack object
/// Deals 1 damage if player hits themselves, regardless of item.
/// </summary>
/// <param name="p">The p.</param>
/// <param name="aText">a text.</param>
/// <returns>result</returns>
std::string AttackCommand::Attack(Player* aPlayer, std::string aObject)
{
	std::string result = "";

	if (aPlayer->AreYou(aObject))
	{
		result = "Ouch! you hit yourself. Your stats go down... and your self-esteem.";
		aPlayer->receiveDamage(aPlayer->getDamage());
	}
	else if (aPlayer->getLocation()->fCharacters->hasChar(aObject) && aPlayer->getLocation()->fCharacters->getChar(aObject)->isAlive())
	{
		aPlayer->getLocation()->fCharacters->getChar(aObject)->receiveDamage(aPlayer->getDamage());
		aPlayer->receiveDamage(aPlayer->getLocation()->fCharacters->getChar(aObject)->getDamage());

		result = "You attack " + aObject + "\n";
		result += std::to_string(aPlayer->getLocation()->fCharacters->getChar(aObject)->getHp()) + "\n";

		if (!aPlayer->getLocation()->fCharacters->getChar(aObject)->isAlive())
		{
			result += "You killed " + aObject;
		}
	}
	else if (!aPlayer->getLocation()->fCharacters->hasChar(aObject))
	{
		result = "You check the room but find no one named " + aObject;
	}
	else
	{
		result = "You cant hit " + aObject;
	}

	return result;
}

std::string AttackCommand::AttackWith(Player* aPlayer, std::string aObject, std::string aItem)
{
	std::string result = "";

	if (aPlayer->AreYou(aObject))
	{
		if (aPlayer->getInventory()->HasItem(aItem))
		{
			aPlayer->receiveDamage(aPlayer->getInventory()->Fetch(aObject)->getDamage());
			result = "I know the situation is looking grim, but dont give up yet!";
		}
		else
		{
			result = "You dont have " + aItem;
		}
	}
	else if (aPlayer->getLocation()->fCharacters->hasChar(aObject) && aPlayer->getLocation()->fCharacters->getChar(aObject)->isAlive())
	{
		if (aPlayer->getInventory()->HasItem(aItem))
		{
			aPlayer->getLocation()->fCharacters->getChar(aObject)->receiveDamage(aPlayer->getInventory()->Fetch(aItem)->getDamage());
			aPlayer->receiveDamage(aPlayer->getLocation()->fCharacters->getChar(aObject)->getDamage());

			result = "You attack " + aObject + "\n";
			result += std::to_string(aPlayer->getLocation()->fCharacters->getChar(aObject)->getHp()) + "\n";

			if (!aPlayer->getLocation()->fCharacters->getChar(aObject)->isAlive())
			{
				result += "You killed " + aObject;
			}
		}
		else
		{
			result = "You dont have " + aItem;
		}
	}
	else if (!aPlayer->getLocation()->fCharacters->hasChar(aObject))
	{
		result = "You check the room but find no one named " + aObject;
	}
	else
	{
		result = "You cant hit " + aObject;
	}

	return result;
}