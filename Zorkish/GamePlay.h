#pragma once
#include "GameState.h"
#include "GameMode.h"
#include "CommandProcessor.h"

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
private:
	Player* myPlayer;
	Graph* myGraph = NULL;
	GameMode* fGameMode = NULL;
	bool fDebugging = false;

protected:
	CommandProcessor* fcp = NULL;
};
