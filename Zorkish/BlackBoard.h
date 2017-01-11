#pragma once
#include "Player.h"

class BlackBoard
{
public:
	BlackBoard();
	~BlackBoard();

	void SendMessage(Player* aP, std::string aMessage);
};
