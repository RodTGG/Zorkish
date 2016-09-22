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
	std::cout << "Zorkish :: Hall of Fame" << std::endl;
	std::cout << "--------------------------------------------------------" << std::endl;
	std::cout << "Top 10 Zorkish Adventure Champions" << std::endl;
	std::cout << "1. Fred, Mountain World, 5000\n2. Mary, Mountain World, 4000\n3. Joe, Water World, 3000\n4. Henry, Mountain World, 2000\n5. Susan, Mountain World, 1000";
	std::cout << "6. Alfred, Water World, 900\n7. Clark, Mountain World, 800\n8. Harold, Mountain World, 500\n9. Julie, Water World, 300\n10. Bill, Box World, -5" << std::endl;
}

void HallofFame::logic()
{

}

int HallofFame::handle_event()
{
	std::cout << "Press ESC or Enter to return to the Main Menu" << std::endl;
	std::cin.ignore();
	std::cin.get();

	return States::STATE_NULL;
}