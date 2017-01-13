#include "stdafx.h"
#include "GameStateManager.h"
#include "States.h"
#include "MainMenu.h"
#include "About.h"
#include "Help.h"
#include "HallofFame.h"
#include "NewHighScore.h"
#include "GamePlay.h"
#include "Exit.h"

GameStateManager::GameStateManager(bool aDebug)
{
	fDebug = aDebug;
	fState = new MainMenu();
	fPlayer = new Player();
}

GameStateManager::GameStateManager()
{
	fPlayer = new Player();
	fState = new MainMenu();
}

GameStateManager::~GameStateManager()
{
	delete fState;
	delete fPlayer;
}

void GameStateManager::change_state()
{
	switch (fnextState)
	{
	case States::STATE_MAINMENU:
		fState = new MainMenu();
		break;
	case States::STATE_ABOUT:
		fState = new About();
		break;
	case States::STATE_HELP:
		fState = new Help();
		break;
	case States::STATE_NEWHIGHSCORE:
		fState = new NewHighScore(fPlayer);
		break;
	case States::STATE_VIEWHALLOFFAME:
		fState = new HallofFame();
		break;
	case States::STATE_GAMEPLAY:
		fState = new GamePlay(fPlayer, fDebug);
		break;
	case States::STATE_EXIT:
		fState = new Exit();
		break;
	}
}

void GameStateManager::set_next_state(int aState)
{
	fnextState = aState;
}

int GameStateManager::CurrentState()
{
	return fState->ID();
}

void GameStateManager::Display()
{
	fState->display();
}

void GameStateManager::ExecuteState()
{
	fnextState = fState->handle_event();
}

bool GameStateManager::DebugMode()
{
	return fDebug;
}