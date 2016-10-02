#include "stdafx.h"
#include "Help.h"

Help::Help() : GameState(2)
{
}

Help::~Help()
{
}

void Help::display()
{
	std::cout << "Zorkish :: Help" << std::endl;
	std::cout << "--------------------------------------------------------" << std::endl;
	std::cout << "The following commands are supported:" << std::endl;
	std::cout << "quit\nhiscore(for testing)" << std::endl;
	std::cout << "Press ESC or Enter to return to the Main Menu" << std::endl;
}

void Help::logic()
{
}

int Help::handle_event()
{
	std::cin.ignore();
	std::cin.get();

	return States::STATE_MAINMENU;
}