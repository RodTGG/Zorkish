#pragma once
#include "GameState.h"
#include "Player.h"
class GamePlay :
	public GameState
{
public:
	GamePlay(Player* p);
	~GamePlay();

	void display();
	void logic();
	int handle_event();
private:
	Player* myPlayer;
};

