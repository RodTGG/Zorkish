#pragma once
#include "Command.h"
class GrabCommand :
	public Command
{
public:
	GrabCommand(std::string aName);
	~GrabCommand();

	std::string Execute(Player* p, std::vector<std::string> aText) override;
	std::string grabItem(Player* p, std::string aObject);
	std::string grabItem(Player* p, std::string aObject, std::string aContainer);
};

