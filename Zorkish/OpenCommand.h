#pragma once
#include "Command.h"
class OpenCommand :
	public Command
{
public:
	OpenCommand(std::string aName);
	~OpenCommand();

	std::string Execute(Player* p, std::vector<std::string> aText) override;
	std::string Open(Player* aPlayer, std::string aObject);
	std::string OpenWith(Player* aPlayer, std::string aObject, std::string aItem);
};

