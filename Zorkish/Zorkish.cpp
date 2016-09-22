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
	myGraph->addNode(new MapNode("1", "cool node"));
	myGraph->addNode(new MapNode("2", "warm node"));
	myGraph->addNode(new MapNode("3", "hot node"));
	myGraph->addNode(new MapNode("4", "cold node"));

	myGraph->addNeighbor(*myGraph->adjlist[0], *myGraph->adjlist[1]);
	myGraph->addNeighbor(*myGraph->adjlist[0], *myGraph->adjlist[2]);
	myGraph->addNeighbor(*myGraph->adjlist[0], *myGraph->adjlist[3]);
	myGraph->addNeighbor(*myGraph->adjlist[1], *myGraph->adjlist[3]);

	myGraph->printGraph();
#endif

}

