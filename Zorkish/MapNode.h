#pragma once
#include "Inventory.h"

class MapNode
{
private:
	// backward pointer to previous element

	std::string fdescription = "";												// description of current map node
	bool visited = false;														// has node already been visited
public:
	std::string fname = "";
	std::vector<MapNode*> fneighbor;
	Inventory* mapItems = new Inventory();										// mapnodes inventory and items

	MapNode();																	// default constructor
	MapNode(std::string aName, std::string aDesc);								// constructor with just description
	const std::string& getDesciption();											// return constant reference to description
	void toggleVisited();
	bool hasNeighbor(MapNode* aNode);
};