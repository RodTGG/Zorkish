#include "stdafx.h"
#include "HallofFame.h"

HallofFame::HallofFame() : GameState(4)
{
}

HallofFame::~HallofFame()
{
}

void HallofFame::display()
{
	std::string lScore = "";
	std::fstream lRead("HighScores.txt");

	std::cout << "Zorkish :: Hall of Fame" << std::endl;
	std::cout << "--------------------------------------------------------" << std::endl;
	std::cout << "Top 10 Zorkish Adventure Champions" << std::endl;


	if (lRead.is_open()) {
		for (int i = 0; i < 10; i++)
		{
			if (!lRead.eof()) {
				std::getline(lRead, lScore);
				std::cout << lScore << std::endl;
			}
		}
	}
}

void HallofFame::logic()
{

}

int HallofFame::handle_event()
{
	std::cout << "Press ESC or Enter to return to the Main Menu" << std::endl;
	std::cin.ignore();
	std::cin.get();
	return States::STATE_MAINMENU;
}