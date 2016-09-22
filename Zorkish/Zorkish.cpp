// Zorkish.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "GameEngine.h"


int main(int argc, char* argv[]) 
{
	GameEngine* myGe = new GameEngine();
	do
	{
		myGe->Render();
		myGe->HandleInput();
		myGe->UpdateGame();
	} while (!myGe->exiting());

    return 0;
}

