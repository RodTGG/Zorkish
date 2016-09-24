#pragma once
#include "IdeableObject.h"
#include "Player.h"

class Command :
	public IdeableObject
{
public:
	Command(std::string ids[2]);
	~Command();

	virtual std::string Execute(Player* p, std::vector<std::string> aText) = 0;
private:
};
