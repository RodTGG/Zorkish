#pragma once
#include "Command.h"

class Attack :
	public Command
{
public:
	Attack(std::string aName);
	~Attack();

	std::string Execute(Player* p, std::vector<std::string> aText) override;
	std::string AttackWith(Player* aPlayer, std::string aObject);
	std::string AttackWith(Player* aPlayer, std::string aObject, std::string aItem);
};
