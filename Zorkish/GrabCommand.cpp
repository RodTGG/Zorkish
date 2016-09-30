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

	if (p->currentLocation()->fInventory->HasItem(aObject))
	{
		p->inv->Put(p->currentLocation()->fInventory->Take(aObject));

		if (!p->inv->HasItem(aObject))
		{
			Error::Display("Error in grabCommand, unable to add " + aObject + " to player...");
		}
		if (p->currentLocation()->fInventory->HasItem(aObject))
		{
			Error::Display("Error unable take" + aObject + " from mapnode " + p->currentLocation()->fname + " inventory...");
		}

		result = "You grabbed " + p->Locate(aObject)->fullDesc();
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
	Container* myContainer = new Container();

	if (p->currentLocation()->fInventory->HasItem(aContainer))
	{
		myContainer = p->currentLocation()->fInventory->getContainer(aContainer);

		if (myContainer != NULL)
		{
			p->inv->Put(p->currentLocation()->fInventory->getContainer(aContainer)->Take(aObject));
		}
		else
		{
			result = "You cant put " + aObject + " in " + aContainer;
		}
		if (!p->inv->HasItem(aObject))
		{
			Error::Display("Unable to grab " + aObject + " from " + aContainer + "...");
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
		myContainer = p->inv->getContainer(aContainer);

		if (myContainer != NULL)
		{
			if (myContainer->HasItem(aObject))
			{
				p->inv->Put(myContainer->Take(aObject));
				result = p->Locate(aObject)->fullDesc();

				if (p->currentLocation()->fInventory->HasItem(aObject))
				{
					Error::Display("");
				}
				if (!p->Locate(aObject))
				{
					Error::Display("");
				}
			}
			else 
			{
				result = aContainer + " does not have item sword...";
			}
		}
		else
		{
			result = "You cannot grab " + aObject + " from " + aContainer;
		}
	}

	return result;
}