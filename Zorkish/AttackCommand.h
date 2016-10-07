#pragma once
#include "Command.h"

class AttackCommand :
	public Command
{
public:
	AttackCommand(std::string aName);
	~AttackCommand();

	std::string Execute(Player* p, std::vector<std::string> aText) override;
	std::string Attack(Player* aPlayer, std::string aObject);
	std::string AttackWith(Player* aPlayer, std::string aObject, std::string aItem);
};
