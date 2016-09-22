// Zorkish.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "Graph.h"
#include "GameStateManager.h"
#define DEBUG 1

int main(int argc, char* argv[]) 
{
#if DEBUG == 1
	GameStateManager* myGSM = new GameStateManager();
	do
	{
		myGSM->change_state();
		myGSM->Display();
		myGSM->ExecuteState();
	} while (myGSM->CurrentState() != States::STATE_EXIT);

	return 0;
#endif
#if DEBUG == 2
	Graph* myGraph = new Graph();
	myGraph->readFile("Adventure.txt");
	myGraph->printGraph();
#endif

}

