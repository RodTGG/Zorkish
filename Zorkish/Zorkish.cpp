// Zorkish.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "GameStateManager.h"
#include "Graph.h"
#include "CharacterContainer.h"
#define DEBUG 1

int main(int argc, char* argv[])
{
	bool lDebug = false;

	if (argc == 2)
	{
		if (*argv[1] == 'd')
		{
			lDebug = true;
		}
	}

#if DEBUG == 1
	GameStateManager* myGSM = new GameStateManager(lDebug);
	do
	{
		myGSM->change_state();
		myGSM->Display();
		myGSM->ExecuteState();
	} while (myGSM->CurrentState() != States::STATE_EXIT);

	return 0;
#endif
#if DEBUG == 2
	Graph* myGraph = new Graph(true);
	myGraph->readFile("Adventure.txt");
	myGraph->printGraph();
#endif
#if DEBUG == 3
	CharacterContainer* myCC = new CharacterContainer();
	myCC->addChars(new Character("Squirell", "da squirell", new std::string[2]{ "squirell","hehexd" }));

	std::cout << myCC->getCharList();
#endif
}