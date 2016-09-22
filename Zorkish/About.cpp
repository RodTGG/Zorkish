#include "stdafx.h"
#include "About.h"


About::About() : GameState(1)
{
}


About::~About()
{
}

void About::display()
{
	std::cout << "Zorkish :: About" << std::endl;
	std::cout << "--------------------------------------------------------" << std::endl;
	std::cout << "Written by : Rodrigo Sanchez\nPress ESC or Enter to return to the Main Menu" << std::endl;
}

void About::logic()
{

}

int About::handle_event()
{
	std::cin.ignore();
	std::cin.get();

	return States::STATE_MAINMENU;
}