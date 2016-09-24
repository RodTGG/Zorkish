#pragma once
#include "GameState.h"
class MainMenu : public GameState
{
public:
	MainMenu();
	~MainMenu();

	void display();
	void logic();
	int handle_event();
};
