#pragma once
#include "Command.h"

namespace Zorkish {
class LookCommand :
	public Command
{
public:
	LookCommand(std::string aName);
	~LookCommand();

	std::string Execute(Player* p, std::vector<std::string> aText) override;
	std::string lookAtIn(Player* p, std::string aItem);
	std::string lookAtIn(Player* p, std::string aItem, std::string aContainer);
private:
	
};
}