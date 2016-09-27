#include "stdafx.h"
#include "MoveCommand.h"

MoveCommand::MoveCommand(std::string aName) : Command(aName)
{
}

MoveCommand::~MoveCommand()
{
}

std::string MoveCommand::Execute(Player* p, std::vector<std::string> aText)
{
	std::string result = "";
	std::string direction = aText[1];										// get direction based on char

	if (aText.size() > 1)													// make sure there are enough arguments to create node
	{
		result = ChangeLocation(p, direction);
	}
	else
	{
		result = aText[0] + " where?";
	}

	return result;
}

std::string MoveCommand::ChangeLocation(Player* p, std::string direction)
{
	std::string result = "you have moved to ";

	if (direction == "n" || direction == "up" || direction == "north")
	{
		if (p->currentLocation()->fneighbor[0] != NULL)
		{
			p->setLocation((p->currentLocation()->fneighbor[0]));
			result += p->currentLocation()->getDesciption();
		}
		else
		{
			result = "Cant go that way";
		}
	}
	else if (direction == "right" || direction == "east" || direction == "e")
	{
		if (p->currentLocation()->fneighbor[1] != NULL)
		{
			p->setLocation((p->currentLocation()->fneighbor[1]));
			result += p->currentLocation()->getDesciption();
		}
		else
		{
			result = "Cant go that way";
		}
	}
	else if (direction == "s" || direction == "down" || direction == "south")
	{
		if (p->currentLocation()->fneighbor[2] != NULL)
		{
			p->setLocation((p->currentLocation()->fneighbor[2]));
			result += p->currentLocation()->getDesciption();
		}
		else
		{
			result = "Cant go that way";
		}
	}
	else if (direction == "w" || direction == "left" || direction == "west")
	{
		if (p->currentLocation()->fneighbor[3] != NULL)
		{
			p->setLocation((p->currentLocation()->fneighbor[3]));
			result += p->currentLocation()->getDesciption();
		}
		else
		{
			result = "Cant go that way";
		}
	}
	else
	{
		result = "Cant go that way";
	}

	return result;
}