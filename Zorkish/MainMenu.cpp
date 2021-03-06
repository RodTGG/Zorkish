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
	std::cout << "Welcome to Zorkish Adventures\n1. Play\n2. Hall of Fame\n3. Help\n4. About\n5. Quit" << std::endl;
}

void MainMenu::logic()
{
}

int MainMenu::handle_event()
{
	bool valid = false;
	int resultState = States::STATE_MAINMENU;
	int usrInput = 0;

	do {
		std::cout << "Select 1-5:>";
		std::cin >> usrInput;
		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');

		switch (usrInput)
		{
		case 1:
			resultState = States::STATE_GAMEPLAY;
			valid = true;
			break;
		case 2:
			resultState = States::STATE_VIEWHALLOFFAME;
			valid = true;
			break;
		case 3:
			resultState = States::STATE_HELP;
			valid = true;
			break;
		case 4:
			resultState = States::STATE_ABOUT;
			valid = true;
			break;
		case 5:
			resultState = States::STATE_EXIT;
			valid = true;
			break;
		default:
			std::cout << "Please enter one of the options." << std::endl;
			valid = false;
			break;
		}
	} while (!valid);

	return resultState;
}