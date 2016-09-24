#pragma once
#include "GameState.h"
#include "GameMode.h"
#include "Player.h"

class GameStateManager
{
public:
	GameStateManager();
	~GameStateManager();

	void set_next_state(int aState);
	void change_state();
	int CurrentState();

	void Display();
	void ExecuteState();
private:
	int stateID = NULL;
	int nextState = NULL;

	GameState* fState = NULL;
	Player* fPlayer = new Player();
	GameMode* fGameMode = NULL;
};
