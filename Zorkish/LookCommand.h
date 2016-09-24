#pragma once
#include "Command.h"
class LookCommand :
	public Command
{
public:
	LookCommand();
	LookCommand(std::string ids[2]);
	~LookCommand();

	std::string Execute(Player* p, std::vector<std::string> aText) override;
	std::string lookAtIn(Player* p, std::string aItem, std::string aContainer);
private:

};

