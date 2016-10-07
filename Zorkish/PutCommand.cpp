#include "stdafx.h"
#include "PutCommand.h"

PutCommand::PutCommand(std::string aName) : Command(aName)
{
}

PutCommand::~PutCommand()
{
}

std::string PutCommand::Execute(Player* p, std::vector<std::string> aText)
{
	std::string result = "";

	if (aText.size() >= 3 && aText.size() <= 4)
	{
		if (aText[1].length() == 0)
		{
			result = "Put what?";
		}
		else if (aText[2] != "in" && aText[2] != "from")
		{
			result = "in is needed";
		}
		else if (aText[3].length() == 0)
		{
			result = "in where?";
		}
		else
		{
			result = putItem(p, aText[1], aText[3]);
		}
	}
	else
	{
		if (aText.size() == 1)
		{
			result = "....just " + aText[0] + " wont do.";
		}
		else
		{
			result = putItem(p, aText[1]);
		}
	}

	return result;
}

std::string PutCommand::putItem(Player* p, std::string aObject)
{
	std::string result = "";

	if (p->getInventory()->HasItem(aObject))
	{
		p->getLocation()->fInventory->Put(p->getInventory()->Take(aObject));
		result = "You dropped " + aObject;

		if (p->getInventory()->HasItem(aObject))
		{
			Error::Display("Unable to take " + aObject + " from player");
		}
		if (!p->getLocation()->fInventory->HasItem(aObject))
		{
			Error::Display("Unable to add " + aObject + " to mapnode");
		}
	}
	else
	{
		result = "You do not have " + aObject;
	}

	return result;
}

std::string PutCommand::putItem(Player* p, std::string aObject, std::string aContainer)
{
	std::string result = "";

	if (!p->getInventory()->HasItem(aObject))
	{
		result = "You do not have " + aObject;
	}
	else if (p->getLocation()->fInventory->HasItem(aContainer))
	{
		if (p->AreYou(aObject))
		{
			result = "You hear a tear and stop.";
		}
		else
		{
			if (p->getLocation()->fInventory->getContainer(aContainer)->isLocked())
			{
				result = "Its locked.";
			}
			else 
			{
				p->getLocation()->fInventory->getContainer(aContainer)->Put(p->getInventory()->Take(aObject));
				result = "You put " + aObject + " in " + aContainer;
			}
		}
	}
	else if (!p->getInventory()->HasItem(aContainer))
	{
		result = "You do not have " + aContainer;
	}
	else if (p->Locate(aObject) == p)
	{
		result = "You try to fit in " + aContainer + " but only get half way :(";

	}
	else
	{
		if (p->AreYou(aContainer))
		{
			result = "item already there...";
		}
		else
		{
			Container* myContainer = p->getInventory()->getContainer(aContainer);

			if (myContainer->isLocked())
			{
				result = "Its locked.";
			}
			else
			{
				p->getInventory()->getContainer(aContainer)->Put(p->getInventory()->Take(aObject));
				result = "You put " + aObject + " in " + aContainer;
			}
		}
	}

	return result;
}