#include "stdafx.h"
#include "MainMenu.h"


MainMenu::MainMenu() : GameState(0)
{
}


MainMenu::~MainMenu()
{
}

void MainMenu::display()
{
	std::cout << "Zorkish :: Main Menu" << std::endl;
	std::cout << "----------------------------------" << std::endl;
	std::cout << "Welcome to Zorkish Adventures\n1. Select Adventure and play\n2. Hall of Fame\n3. Help\n4. About\n5. Quit" << std::endl;
}

void MainMenu::logic()
{

}

int MainMenu::handle_event()
{
	int usrInput = NULL;
	std::cout << "Select 1-5:>";

	do
	{
		std::cin >> usrInput;
		switch (usrInput)
		{
		case 1:
			return States::STATE_SELECTADVENTURE;
			break;
		case 2:
			return States::STATE_VIEWHALLOFFAME;
			break;
		case 3:
			return States::STATE_HELP;
			break;
		case 4:
			return States::STATE_ABOUT;
			break;
		case 5:
			return States::STATE_EXIT;
			break;
		}

	} while (usrInput > 6 || usrInput < 1);
}