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
		
		if (p->currentLocation()->fInventory->HasItem(aObject))
		{
			result = "Unable to remove item";
		}
		if (!p->Locate(aObject)) 
		{
			result = "Unable to add item to player";
		}
		else 
		{
			result = "You grabbed " + p->Locate(aObject)->fullDesc();
		}
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

	if (p->currentLocation()->fInventory->HasItem(aContainer))
	{
		p->currentLocation()->fInventory->getContainer(aContainer)->Put(p->inv->Take(aObject));
	}
	else if (p->Locate(aContainer) == NULL)
	{
		result = "You do not have " + aContainer;
	}
	else
	{
		if (p->Locate(aObject) == NULL)
		{
			result = "You do not have " + aObject + " in " + aContainer;
		}
		else
		{
			result = p->Locate(aObject)->fullDesc();
			p->inv->Put((Item*)p->Locate(aObject));

			if (p->currentLocation()->fInventory->HasItem(aObject))
			{
				result = "unable to remove item";
			}
			if (!p->Locate(aObject))
			{
				result = "unable to add item to player";
			}
			else
			{
				result = "You grabbed " + p->Locate(aObject)->fullDesc();
			}
		}
	}

	return result;
}