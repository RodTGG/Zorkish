#include "stdafx.h"
#include "GrabCommand.h"

GrabCommand::GrabCommand(std::string aName) : Command(aName)
{
}

GrabCommand::~GrabCommand()
{
}

std::string GrabCommand::Execute(Player* p, std::vector<std::string> aText)
{
	std::string result = "";

	if (aText.size() >= 3 && aText.size() <= 4)
	{
		if (aText[1].length() == 0)
		{
			result = "Grab what?";
		}
		else if (aText[2] != "from")
		{
			result = "from is needed";
		}
		else if (aText[3].length() == 0)
		{
			result = "from where?";
		}
		else
		{
			result = grabItem(p, aText[1], aText[3]);
		}
	}
	else
	{
		if (aText.size() == 1)
		{
			result = "Try having more than just " + aText[0] + "...";
		}
		else
		{
			result = grabItem(p, aText[1]);
		}
	}

	return result;
}

std::string GrabCommand::grabItem(Player* p, std::string aObject)
{
	std::string result = "";

	if (p->getLocation()->fInventory->HasItem(aObject))
	{
		p->getInventory()->Put(p->getLocation()->fInventory->Take(aObject));

		if (!p->getInventory()->HasItem(aObject))
		{
			Error::Display("Error in grabCommand, unable to add " + aObject + " to player...");
		}
		if (p->getLocation()->fInventory->HasItem(aObject))
		{
			Error::Display("Error unable take" + aObject + " from mapnode " + p->getLocation()->fName + " inventory...");
		}

		result = "You grabbed " + aObject + " " + p->getInventory()->Fetch(aObject)->getFullDesc();
	}
	else
	{
		result = "You try really hard but you just cant seem to grab " + aObject;
	}

	return result;
}

std::string GrabCommand::grabItem(Player* p, std::string aObject, std::string aContainer)
{
	std::string result = "";
	Container* myContainer;

	if (p->getLocation()->fInventory->HasItem(aContainer))
	{
		myContainer = p->getLocation()->fInventory->getContainer(aContainer);

		if (myContainer != NULL)
		{
			if (myContainer->HasItem(aObject))
			{
				p->getInventory()->Put(p->getLocation()->fInventory->getContainer(aContainer)->Take(aObject));
				result = "You grabbed " + aObject + " from " + aContainer;
			}
		}
		else
		{
			result = "You dont have " + aContainer;
		}
	}
	else if (p->Locate(aContainer) == NULL)
	{
		result = "You do not have " + aContainer;
	}
	else if (p->Locate(aObject) == p)
	{
		result = "Hmmm you look in " + aContainer + " but cant seem to find your better self...";
	}
	else
	{
		myContainer = p->getInventory()->getContainer(aContainer);

		if (myContainer != NULL)
		{
			if (myContainer->HasItem(aObject))
			{
				p->getInventory()->Put(myContainer->Take(aObject));
				result = p->Locate(aObject)->getFullDesc();
			}
			else
			{
				result = aContainer + " does not have item" + aObject + "...";
			}
		}
		else
		{
			result = "You cannot grab " + aObject + " from " + aContainer;
		}
	}

	return result;
}