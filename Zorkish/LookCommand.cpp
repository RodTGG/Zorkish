#include "stdafx.h"
#include "LookCommand.h"

LookCommand::LookCommand(std::string aName) : Command(aName)
{
}

LookCommand::~LookCommand()
{
}

std::string LookCommand::Execute(Player* p, std::vector<std::string> aText)
{
	std::string result = "";

	if (aText[1] == "at" && aText[2] == "all") 
	{
		blackbMessage(p);
	}

	else if (aText.size() >= 3 && aText.size() <= 5)
	{
		if (aText[1] != "at" && aText[1] != "in")
		{
			result = "look at what?";
		}
		if (aText.size() > 3)
		{
			if (aText[2].length() == 0)
			{
				result = "What do you want to look at?";
			}
			else if (aText[4].length() == 0)
			{
				result = "Where do you want to look?";
			}
			else
			{
				result = lookAtIn(p, aText[2], aText[4]);
			}
		}
		else
		{
			if (aText[2].length() == 0)
			{
				result = "What do you want to look at?";
			}
			else
			{
				result = lookAtIn(p, aText[2]);
			}
		}
	}
	else
	{
		if (aText.size() == 1)
		{
			result = "just " + aText[0] + "? you can do better than that.";
		}
	}

	return result;
}

std::string LookCommand::lookAtIn(Player* p, std::string aItem)
{
	std::string result = "";

	if (p->AreYou(aItem))
	{
		result = p->Locate(aItem)->getFullDesc();
	}
	else {
		if (p->getLocation()->fInventory->HasItem(aItem))
		{
			if (p->getLocation()->fInventory->Fetch(aItem)->isContainer()) 
			{
				if (p->getLocation()->fInventory->getContainer(aItem)->isLocked())
				{
					result = "You cant look inside its locked.";
				}
				else 
				{
					result = p->getLocation()->fInventory->Fetch(aItem)->getFullDesc();
				}
			}
			else
			{
				result = p->getLocation()->fInventory->Fetch(aItem)->getFullDesc();
			}
		}
		else
		{
			if (p->getInventory()->HasItem(aItem))
			{
				result = p->Locate(aItem)->getFullDesc();
			}
			else
			{
				result = "Could not find " + aItem;
			}
		}
	}

	return result;
}

std::string LookCommand::lookAtIn(Player* p, std::string aItem, std::string aContainer)
{
	std::string result = "";

	if (p->Locate(aContainer) == NULL)
	{
		result = "You do not have " + aContainer;
	}
	else
	{
		if (p->Locate(aItem) == NULL)
		{
			result = "You do not have " + aItem + " in " + aContainer;
		}
		else
		{
			result = p->Locate(aItem)->getFullDesc();
		}
	}

	return result;
}

void LookCommand::blackbMessage(Player* aP)
{
	fBlackboard->SendMessage(aP, "look");
}