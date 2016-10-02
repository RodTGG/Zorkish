#pragma once
#include "GameState.h"

class HallofFame :
	public GameState
{
public:
	HallofFame();
	~HallofFame();

	void display();
	void logic();
	int handle_event();
};