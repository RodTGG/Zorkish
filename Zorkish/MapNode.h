#pragma once
#include "Container.h"

class MapNode
{
private:
	// backward pointer to previous element

	std::string fdescription = "";												// description of current map node
	bool visited = false;														// has node already been visited
public:
	std::string fname = "";
	std::vector<MapNode*> fneighbor;
	Container* fChest = new Container("Chest", "a very pretty chest", new std::string[2]{"chest","Chest"});										// mapnodes inventory and items

	MapNode();																	// default constructor
	MapNode(std::string aName, std::string aDesc);								// constructor with just description
	const std::string& getDesciption();											// return constant reference to description
	void toggleVisited();
	bool hasNeighbor(MapNode* aNode);
};