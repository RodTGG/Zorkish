#include "stdafx.h"
#include "MapNode.h"

MapNode::MapNode()
{
	fEdges.clear();
}

MapNode::MapNode(std::string aDesc)
{
	fdescription = aDesc;
	fEdges.clear();
}

MapNode::MapNode(std::string aDesc, Item* aItems[])
{
	fdescription = aDesc;
	fEdges.clear();

	for (int i = 0; i < (sizeof(aItems) / sizeof(*aItems)); i++)
	{
		mapItems->Put(aItems[i]);
	}
}

void MapNode::addEdge(MapNode& aNode)
{
	fconnectedRooms.push_back(&aNode);
}

void MapNode::remove(MapNode& aNode)
{
	for (unsigned int i = 0; i < fconnectedRooms.size(); i++)
	{
		if (fconnectedRooms[i] == &aNode)
		{
			fconnectedRooms.erase(fconnectedRooms.begin() + i);
		}
		else
		{
			std::cout << "Error, unable to remove room node" << std::endl;
		}
	}
}

const std::string& MapNode::getDesciption()
{
	return fdescription;
}

bool MapNode::hasNeighbour(MapNode* aNode)
{
	for (unsigned int i = 0; i < fconnectedRooms.size(); i++)
	{
		if (fconnectedRooms[i] == aNode)
		{
			return true;
		}
		else { false; }
	}
	return false;
}

void MapNode::toggleVisited()
{
	if (visited)
	{
		visited = false;
	}
	else
	{
		visited = true;
	}
}