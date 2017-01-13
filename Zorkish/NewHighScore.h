#pragma once
#include "GameState.h"
#include "Player.h"

class NewHighScore :
	public GameState
{
public:
	NewHighScore(Player* aPlayer);
	~NewHighScore();

	void display();
	void logic();
	int handle_event();
private:
	Player* fPlayer;
};