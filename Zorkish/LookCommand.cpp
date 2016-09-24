#include "stdafx.h"
#include "LookCommand.h"


LookCommand::LookCommand() : Command(new std::string[2]{ "look", "l" })
{
}

LookCommand::LookCommand(std::string ids[2]) : Command(ids)
{
}

LookCommand::~LookCommand()
{
}

std::string LookCommand::Execute(Player* p, std::vector<std::string> aText)
{
	std::string result = "";

	if (aText.size() >= 3 && aText.size() <= 5)
	{
		if (aText[0] != "look")
		{
			result = "Thats not look";
		}
		else if (aText[1] != "at" && aText[1] != "in")
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
				result = lookAtIn(p, aText[2], aText[2]);
			}
		}
	}
	else
	{
		if (aText.size() == 1)
		{
			result = "just look? you can do better than that";
		}
	}

	return result;
}

std::string LookCommand::lookAtIn(Player* p, std::string aItem, std::string aContainer)
{
	std::string result = "";

	if (aItem != aContainer) {
		if (p->Locate(aContainer) == NULL)
		{
			result = "You do not have" + aContainer;
		}
		else
		{
			if (p->Locate(aItem) == NULL)
			{
				result = "You do not have " + aItem + " in " + aContainer;
			}
			else
			{
				result = p->Locate(aItem)->FullDesc();
			}
		}
	}
	else 
	{
		if (p->currentLocation()->mapItems->HasItem(aItem)) 
		{
			result = p->currentLocation()->mapItems->Fetch(aItem)->FullDesc();
		}
		else 
		{
			result = "Could not find item";
		}
	}

	return result;
}