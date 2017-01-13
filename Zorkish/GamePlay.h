#pragma once
#include "GameState.h"
#include "CommandProcessor.h"
#include "Graph.h"

class GamePlay :
	public GameState
{
public:
	GamePlay(Player* p, bool aDebug = false);
	~GamePlay();

	void display() override;
	void logic() override;
	int handle_event() override;

	void setupGame();
private:
	Player* fPlayer;
	Graph* fGraph;
	bool fDebugging;

protected:
	CommandProcessor* fCommandProcessor;;
};