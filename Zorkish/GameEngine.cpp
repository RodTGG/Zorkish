#include "stdafx.h"
#include "GameEngine.h"


GameEngine::GameEngine()
{
}


GameEngine::~GameEngine()
{
	delete fGsm;
}

void GameEngine::HandleInput()
{
	fGsm->ExecuteState();
}

void GameEngine::UpdateGame()
{
	fGsm->change_state();
}

void GameEngine::Render()
{
	fGsm->Display();
}

bool GameEngine::exiting()
{
	if (exit)
	{
		return true;
	}
	else
	{
		return false;
	}
}