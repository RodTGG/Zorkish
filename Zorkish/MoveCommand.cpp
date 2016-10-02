#include "stdafx.h"
#include "MoveCommand.h"

using namespace Zorkish;

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
		if (p->getLocation()->fNeighbor[0] != NULL)
		{
			p->setLocation((p->getLocation()->fNeighbor[0]));
			result += p->getLocation()->getDesciption();
		}
		else
		{
			result = "Cant go that way";
		}
	}
	else if (direction == "right" || direction == "east" || direction == "e")
	{
		if (p->getLocation()->fNeighbor[1] != NULL)
		{
			p->setLocation((p->getLocation()->fNeighbor[1]));
			result += p->getLocation()->getDesciption();
		}
		else
		{
			result = "Cant go that way";
		}
	}
	else if (direction == "s" || direction == "down" || direction == "south")
	{
		if (p->getLocation()->fNeighbor[2] != NULL)
		{
			p->setLocation((p->getLocation()->fNeighbor[2]));
			result += p->getLocation()->getDesciption();
		}
		else
		{
			result = "Cant go that way";
		}
	}
	else if (direction == "w" || direction == "left" || direction == "west")
	{
		if (p->getLocation()->fNeighbor[3] != NULL)
		{
			p->setLocation((p->getLocation()->fNeighbor[3]));
			result += p->getLocation()->getDesciption();
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