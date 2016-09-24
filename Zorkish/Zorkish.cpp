// Zorkish.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "Graph.h"
#include "GameStateManager.h"
#define DEBUG 1

void add(int a, int b, int* c)
{
	*c = a + b;
}

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
#if DEBUG == 3
	int a = 3;
	int b = 4;
	int c = 0;

	add(a,b, &c);
	std::cout << c;
#endif
}

