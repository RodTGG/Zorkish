#pragma once
#include "GameState.h"
#include "GameMode.h"
#include "CommandProcessor.h"
#include "Graph.h"

class GamePlay :
	public GameState
{
public:
	GamePlay(Player* p, GameMode* aGame, bool aDebug);
	GamePlay(Player* p, GameMode* aGame);
	~GamePlay();

	void display() override;
	void logic() override;
	int handle_event() override;

	void setupGame();
private:
	Player* fPlayer;
	Graph* fGraph = NULL;
	GameMode* fGameMode = NULL;
	bool fDebugging = false;

protected:
	CommandProcessor* fCommandProcessor = NULL;
};