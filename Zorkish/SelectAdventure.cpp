#include "stdafx.h"
#include "SelectAdventure.h"


SelectAdventure::SelectAdventure() : GameState(3)
{
}


SelectAdventure::~SelectAdventure()
{
}

void SelectAdventure::display()
{
	std::cout << "Zorkish :: Select Adventure" << std::endl;
	std::cout << "--------------------------------------------------------" << std::endl;
	std::cout << "Choose your adventure:" << std::endl;
	std::cout << "1. Mountain World\n2. Water World\n3. Box World" << std::endl;
}

void SelectAdventure::logic()
{

}

int SelectAdventure::handle_event()
{
	int usrInput = NULL;
	std::cout << "Select 1-3:>";
	std::cin >> usrInput;

	switch (usrInput)
	{
	case 1:
		return States::GAME_MOUNTAINWORLD;
		break;
	case 2:
		return States::GAME_WATERWORLD;
		break;
	case 3:
		return States::GAME_BOXWORLD;
		break;
	}
}