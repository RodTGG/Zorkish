#include "stdafx.h"
#include "OpenCommand.h"


OpenCommand::OpenCommand(std::string aName) : Command(aName)
{
}


OpenCommand::~OpenCommand()
{
}

std::string OpenCommand::Execute(Player* aPlayer, std::vector<std::string> aText) 
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
			result = OpenWith(aPlayer, aText[1], aText[3]);
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
			result = Open(aPlayer, aText[1]);
		}
	}
	else if (aText.size() == 1)
	{
		result = "You yell open, but nothing happens.";
	}
	else
	{
		result = "well that aint right...";
	}

	return result;
}

std::string OpenCommand::Open(Player* aPlayer, std::string aObject)
{
	std::string result = "";

	if (aPlayer->AreYou(aObject))
	{
		result = "To open yourself, you must first open your heart.\n";
		result += "You feel sad, looks like trying to find a deeper meaning for life just isnt for you.\n";
	}
	else if (aPlayer->getLocation()->fInventory->HasItem(aObject))
	{
		if (!aPlayer->getLocation()->fInventory->Fetch(aObject)->isContainer())
		{
			result = "You cant open that...";
		}
		else 
		{
			if (aPlayer->getLocation()->fInventory->getContainer(aObject)->isLocked())
			{
				result = "Its locked, need something to open it with";
			}
			else
			{
				result = "Its already open...";
			}
		}
	}
	else
	{
		result = "No " + aObject + " around to open.";
	}

	return result;
}

std::string OpenCommand::OpenWith(Player* aPlayer, std::string aObject, std::string aItem)
{
	std::string result = "";

	if (aPlayer->AreYou(aObject))
	{
		result = "To open yourself, you must first open your heart.\n";
		result += "You feel sad, looks like trying to find a deeper meaning for life just isnt for you.\n";
	}
	else if (!aPlayer->getInventory()->HasItem(aItem)) 
	{
		result = "You dont have " + aItem;
	}
	else if (aPlayer->getLocation()->fInventory->HasItem(aObject))
	{
		if (!aPlayer->getLocation()->fInventory->Fetch(aObject)->isContainer())
		{
			result = "You cant open that...";
		}
		else
		{
			if (aPlayer->getLocation()->fInventory->getContainer(aObject)->isLocked())
			{
				aPlayer->getLocation()->fInventory->getContainer(aObject)->open(aPlayer->getInventory()->Fetch(aItem));
				result = "You attempt to open " + aObject + " with " + aItem + "\n";

				if (aPlayer->getLocation()->fInventory->getContainer(aObject)->isLocked())
				{
					result = "You failed to open the chest with this key\n";
				}
				else 
				{
					aPlayer->getInventory()->Take(aItem);
					result = "You succeed!";
				}
			}
			else
			{
				result = "Its already open...";
			}
		}
	}
	else if (aPlayer->getInventory()->HasItem(aObject)) 
	{
		if (!aPlayer->getInventory()->Fetch(aObject)->isContainer())
		{
			result = "You cant open that...";
		}
		else
		{
			if (aPlayer->getInventory()->getContainer(aObject)->isLocked())
			{
				aPlayer->getInventory()->getContainer(aObject)->open(aPlayer->getInventory()->Fetch(aItem));
				result = "You attempt to open " + aObject + " with " + aItem + "\n";

				if (aPlayer->getInventory()->getContainer(aObject)->isLocked())
				{
					result = "You failed to open the chest with this key\n";
				}
				else
				{
					aPlayer->getInventory()->Take(aItem);
					result = "You succeed!";
				}
			}
			else
			{
				result = "Its already open...";
			}
		}
	}
	else
	{
		result = "No " + aObject + " around to open.";
	}

	return result;
}