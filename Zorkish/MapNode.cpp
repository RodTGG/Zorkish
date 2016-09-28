#include "stdafx.h"
#include "MapNode.h"

MapNode::MapNode()
{
	fChest->Put(new Container("Bag", "a kawaii bag", new std::string[2]{"bag","beg"}));
}

MapNode::MapNode(std::string aName, std::string aDesc)
{
	fname = aName;
	fdescription = aDesc;

	for (unsigned int i = 0; i < 4; i++)
	{
		fneighbor.push_back(NULL);
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
		if (fneighbor[i] != NULL) {
			if (fneighbor[i]->fname == aNode->fname)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
	}
	return false;
}