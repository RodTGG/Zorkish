#pragma once
#include "Edge.h"
#include "Inventory.h"

class MapNode
{
private:
	std::vector<Edge*> fEdges;													// backward pointer to previous element

	std::string fdescription = "";												// description of current map node
	bool visited = false;														// has node already been visited
public:


	Inventory* mapItems = new Inventory();										// mapnodes inventory and items

	MapNode();																	// default constructor
	MapNode(std::string aDesc);													// constructor with just description
	MapNode(std::string aDesc, Item* aItems[]);									// constructor with description and items

	const std::string& getDesciption();											// return constant reference to description
	void toggleVisited();
};