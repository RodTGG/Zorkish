#include "stdafx.h"
#include "GamePlay.h"


GamePlay::GamePlay(Player* p) : GameState(5)
{
	myPlayer = p;
	myGraph->readFile("Adventure.txt");
	myPlayer->setLocation(myGraph->adjlist[0]);
}


GamePlay::~GamePlay()
{
}

void GamePlay::display()
{
	std::cout << "Welcome to Zorkish: Void World" << std::endl;
	std::cout << "This world is simple and pointless.\nUsed it to test Zorkish phase 1 spec." << std::endl;
}

void GamePlay::logic()
{

}

int GamePlay::handle_event()
{
	std::string usrInput = "";
	std::cout << ":>";
	std::cin >> usrInput;

	do {
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
			std::cout << myPlayer->FullDesc();
		}
		if (usrInput == "go") 
		{
			myPlayer->go("n");
		}
	} while (usrInput != "quit");
}