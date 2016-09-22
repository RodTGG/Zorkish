#include "stdafx.h"
#include "MapNode.h"

MapNode::MapNode()
{
}

MapNode::MapNode(std::string aName, std::string aDesc)
{
	fname = aName;
	fdescription = aDesc;
}

MapNode::MapNode(std::string aName, std::string aDesc, Item* aItems[])
{
	fname = aName;
	fdescription = aDesc;

	for (int i = 0; i < (sizeof(aItems) / sizeof(*aItems)); i++)
	{
		mapItems->Put(aItems[i]);
	}
}

const std::string& MapNode::getDesciption()
{
	return fdescription;
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

bool MapNode::hasNeighbor(MapNode* aNode) 
{
	for (unsigned int i = 0; i < fneighbor.size(); i++)
	{
		if (fneighbor[i]->fname == aNode->fname)
		{
			return true;
		}
		else 
		{
			return false;
		}
	}
	return false;
}