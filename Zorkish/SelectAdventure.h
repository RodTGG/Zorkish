#pragma once
#include "GameState.h"

class SelectAdventure :
	public GameState
{
public:
	SelectAdventure();
	~SelectAdventure();

	void display();
	void logic();
	int handle_event();

private:
};