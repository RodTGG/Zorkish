#pragma once
#include "Command.h"

namespace Zorkish {
class PutCommand :
	public Command
{
public:
	PutCommand(std::string aName);
	~PutCommand();

	std::string Execute(Player* p, std::vector<std::string> aText) override;
	std::string putItem(Player* p, std::string aObject);
	std::string putItem(Player* p, std::string aObject, std::string aContainer);
};
}