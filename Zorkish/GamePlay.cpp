#include "stdafx.h"
#include "GamePlay.h"

using namespace Zorkish;

GamePlay::GamePlay(Player* aPlayer, GameMode* aGameMode, bool aDebugging) : GameState(5)
{
	fGameMode = aGameMode;
	fDebugging = aDebugging;
	fPlayer = aPlayer;
	fGraph = new Graph(aDebugging);
	fCommandProcessor = new CommandProcessor();
}

GamePlay::GamePlay(Player* aPlayer, GameMode* aGameMode) : GameState(5)
{
	fGameMode = aGameMode;
	fPlayer = aPlayer;
	fGraph = new Graph();
	fCommandProcessor = new CommandProcessor();
}

GamePlay::~GamePlay()
{
}

void GamePlay::setupGame()
{
	fGraph->readFile("Adventure.txt");
	fPlayer->setLocation(fGraph->adjlist[0]);
}

void GamePlay::display()
{
	std::cout << "Welcome to Zorkish: Void World" << std::endl;
	std::cout << "This world is simple and pointless.\nUsed it to test Zorkish phase 1 spec." << std::endl;
}

void GamePlay::logic()
{
	setupGame();
	fPlayer->getInventory()->Put(new Item("Sword", "A mighty Sword", new std::string[2]{ "sword","heartseeker" }));
}

int GamePlay::handle_event()
{
	int returnState = States::STATE_MAINMENU;
	std::string usrInput = "";
	logic();

	do {
		std::cout << ":>";
		while (std::getline(std::cin, usrInput))
		{
			if (usrInput.empty())
			{
				continue;
			}
			else
			{
				break;
			}
		}

		if (usrInput == "quit")
		{
			std::cout << "Your adventure has ended without fame or fortune." << std::endl;
			return States::STATE_MAINMENU;
		}

		if (usrInput == "hiscore")
		{
			std::cout << "You have entered the magic word and will now see the �New High Score� screen.";
			return States::STATE_VIEWHALLOFFAME;
		}
		if (usrInput == "i")
		{
			std::cout << fPlayer->getFullDesc();
		}
		else
		{
			std::cout << fCommandProcessor->executeCommand(fPlayer, usrInput) << std::endl;
		}
	} while (usrInput != "quit");

	return returnState;
}