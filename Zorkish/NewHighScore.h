#pragma once
#include "GameState.h"
#include "Player.h"
#include "GameMode.h"

class NewHighScore :
	public GameState
{
public:
	NewHighScore(Player* aPlayer, GameMode* aGameMode);
	~NewHighScore();

	void display();
	void logic();
	int handle_event();
private:
	Player* fPlayer;
	GameMode* game = new GameMode();
};
