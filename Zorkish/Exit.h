#pragma once
#include "GameState.h"

class Exit
	: public GameState
{
public:
	Exit();
	~Exit();

	void display() override;
	void logic() override;
	int handle_event() override;
};