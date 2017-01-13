#include "stdafx.h"
#include "NewHighScore.h"

NewHighScore::NewHighScore(Player* aPlayer) : GameState(6)
{
	fPlayer = aPlayer;
}

NewHighScore::~NewHighScore()
{
}

void NewHighScore::display()
{
	std::cout << "Zorkish :: New High Score" << std::endl;
	std::cout << "--------------------------------------------------------" << std::endl;
	std::cout << "Congratulations!" << std::endl;
	std::cout << "You have made it to the Zorkish Hall Of Fame" << std::endl;
	std::cout << "Score: " + fPlayer->getScore() << std::endl;
	std::cout << "Moves: " + fPlayer->getMoves() << std::endl;
}

void NewHighScore::logic()
{
}

int NewHighScore::handle_event()
{
	std::string usrInput = "";

	std::cout << "Please type your name and press enter: " << std::endl;
	std::cout << ":>";
	std::cin >> usrInput;

	return States::STATE_MAINMENU;
}