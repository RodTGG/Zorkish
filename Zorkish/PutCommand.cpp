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
		else if (aText[2] != "in")
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
		if (aText[1].length() == 0)
		{
			result = "Put what?";
		}
		else
		{
			putItem(p, aText[1]);
		}
	}

	return result;
}

std::string PutCommand::putItem(Player* p, std::string aObject)
{
	std::string result = "";


	p->currentLocation()->mapItems->Put(p->inv->Take(aObject));

	if (!p->currentLocation()->mapItems->HasItem(aObject))
	{
		result = "unable to drop item in this location";
	}
	if (p->Locate(aObject))
	{
		result = "unable to remove item from user";
	}
	else
	{
		result = "you dropped " + p->inv->Fetch(aObject)->FullDesc();
	}

return result;
}

std::string PutCommand::putItem(Player* p, std::string aObject, std::string aContainer)
{
	std::string result = "";

	if (p->Locate(aContainer) == NULL)
	{
		result = "You do not have" + aContainer;
	}
	else
	{
		if (p->Locate(aObject) == NULL)
		{
			result = "You do not have " + aObject + " in " + aContainer;
		}
		else
		{
			if (p->AreYou(aContainer))
			{
				p->inv->Put(p->currentLocation()->mapItems->Take(aObject));
				result = "you take " + p->inv->Fetch(aObject)->FullDesc();

				if (!p->currentLocation()->mapItems->HasItem(aObject))
				{
					result = "unable to drop item in this location";
				}
				if (p->Locate(aObject))
				{
					result = "unable to remove item from user";
				}
				else 
				{
					result = "you dropped " + p->inv->Fetch(aObject)->FullDesc() + " into " + aContainer;
				}
			}
		}
	}

	return result;
}