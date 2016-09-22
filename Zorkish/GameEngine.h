#pragma once
#include "GameStateManager.h"

class GameEngine
{
private:
	GameStateManager* fGsm = new GameStateManager();
	bool exit;
	bool won;
public:
	GameEngine();
	~GameEngine();
	void HandleInput();
	void UpdateGame();
	void Render();
	bool exiting();
};

