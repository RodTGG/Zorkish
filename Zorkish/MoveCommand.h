#pragma once
#include "Command.h"
class MoveCommand :
	public Command
{
public:
	MoveCommand();
	MoveCommand(std::string ids[2]);
	~MoveCommand();

	std::string Execute(Player* p, std::vector<std::string> aText) override;
	std::string ChangeLocation(Player* p, std::string direction);
};
