#include "stdafx.h"
#include "MoveCommand.h"

MoveCommand::MoveCommand() : Command(new std::string[2]{ "move", "go" })
{
}

MoveCommand::MoveCommand(std::string ids[2]) : Command(ids)
{
}

MoveCommand::~MoveCommand()
{
}

std::string MoveCommand::Execute(Player* p, std::vector<std::string> aText)
{
	std::string direction = aText[1];

	if (aText.size() > 1)
	{
		return ChangeLocation(p, direction);
	}
	else
	{
		return "Not enough arguments";
	}
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