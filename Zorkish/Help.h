#pragma once
#include "GameState.h"

class Help :
	public GameState
{
public:
	Help();
	~Help();

	void display();
	void logic();
	int handle_event();
};