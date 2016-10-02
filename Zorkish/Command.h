#pragma once
#include "IdeableObject.h"
#include "Player.h"

namespace Zorkish {
	class Command
	{
	public:
		Command(std::string aName) { fname = aName; };

		virtual std::string Execute(Player* p, std::vector<std::string> aText) = 0;

		virtual std::string name() { return fname; };
	private:
		std::string fname;
	};
}