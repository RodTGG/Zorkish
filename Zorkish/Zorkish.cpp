// Zorkish.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "GameEngine.h"
#include "Graph.h"
#define DEBUG 2

int main(int argc, char* argv[]) 
{
#if DEBUG == 1
	GameEngine* myGe = new GameEngine();
	do
	{
		myGe->Render();
		myGe->HandleInput();
		myGe->UpdateGame();
	} while (!myGe->exiting());

	return 0;
#endif
#if DEBUG == 2
	Graph* myGraph = new Graph();
	myGraph->readFile("Adventure.txt");
	myGraph->printGraph();
#endif

}

