#pragma once
#include "Command.h"

namespace Zorkish {
	class Attack :
		public Command
	{
	public:
		Attack(std::string aName);
		~Attack();

		std::string Execute(Player* p, std::vector<std::string> aText) override;
		std::string AttackAt(Player* aPlayer, std::string aObject);
	};
}
