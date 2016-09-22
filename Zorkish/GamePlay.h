#pragma once
#include "GameState.h"
#include "Player.h"
class GamePlay :
	public GameState
{
public:
	GamePlay(Player* p);
	~GamePlay();

	void display() override;
	void logic() override;
	int handle_event() override;
private:
	Player* myPlayer;
	Graph* myGraph = new Graph();
};

