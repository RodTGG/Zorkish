#include "stdafx.h"
#include "Exit.h"

Exit::Exit()
{
}

Exit::~Exit()
{
}

void Exit::display()
{
	std::cout << "\nZorkish :: Exit" << std::endl;
	std::cout << "--------------------------------------------------------" << std::endl;
	std::cout << "Exiting........ bye!" << std::endl;
}

void Exit::logic()
{
}

int Exit::handle_event()
{
	exit(0);
}