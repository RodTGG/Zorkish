#include "stdafx.h"
#include "GameStateManager.h"
#include "States.h"
#include "MainMenu.h"
#include "About.h"
#include "Help.h"
#include "SelectAdventure.h"
#include "HallofFame.h"
#include "NewHighScore.h"
#include "MountainWorld.h"
#include "WaterWorld.h"
#include "BoxWorld.h"
#include "GamePlay.h"

GameStateManager::GameStateManager()
{
	fState = new MainMenu();
	fPreviousState = fState;
}


GameStateManager::~GameStateManager()
{
	delete fState;
	delete fPlayer;
}

void GameStateManager::change_state()
{
	//stateID = fState->ID();

	if (nextState != States::STATE_NULL) {
		if (nextState != States::STATE_EXIT)
		{
			switch (nextState)
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
				fState = new NewHighScore(fPlayer, fGameMode);
				break;
			case States::STATE_SELECTADVENTURE:
				fState = new SelectAdventure();
				break;
			case States::STATE_VIEWHALLOFFAME:
				fState = new HallofFame();
				break;
			case States::STATE_GAMEPLAY:
				fState = new GamePlay(fPlayer);
				fPreviousState = fState;
				break;
			case States::STATE_EXIT:
				break;
			case States::GAME_MOUNTAINWORLD:
				fGameMode = new MountainWorld();
				set_next_state(States::STATE_GAMEPLAY);
				change_state();
				break;
			case States::GAME_WATERWORLD:
				fGameMode = new WaterWorld();
				set_next_state(States::STATE_GAMEPLAY);
				change_state();
				break;
			case States::GAME_BOXWORLD:
				fGameMode = new BoxWorld();
				set_next_state(States::STATE_GAMEPLAY);
				change_state();
				break;
			}
		}
	}
	else
	{
		fState = fPreviousState;
		nextState = fState->ID();
	}
}

void GameStateManager::set_next_state(int aState)
{
	fPreviousState = fState;
	nextState = aState;
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
	nextState = fState->handle_event();
}