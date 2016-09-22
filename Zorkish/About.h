#pragma once
#include "GameState.h"
class About :
	public GameState
{
public:
	About();
	~About();

	void display();
	void logic();
	int handle_event();
};

