#include "stdafx.h"
#include "MapNode.h"
#include "CharacterContainer.h"
#include "Character.h"

MapNode::MapNode(std::string aName, std::string aDesc)
{
	fCharacters = new CharacterContainer();
	fInventory = new Container("mapInv", "items on the floor", new std::string[2]{ "map","floor" });
	fInventory->Put(new Container("chest", "theer", true, "key", new std::string[2]{ "chest","chust" }));

	fName = aName;
	fDescription = aDesc;

	for (unsigned int i = 0; i < 4; i++)
	{
		fNeighbor.push_back(NULL);
	}
}

MapNode::MapNode(std::string aName, std::string aDesc, Item aItems[])
{
	fCharacters = new CharacterContainer();
	fInventory = new Container("mapInv", "items on the floor", new std::string[2]{ "map","floor" });

	fName = aName;
	fDescription = aDesc;

	for (unsigned int i = 0; i < 4; i++)
	{
		fNeighbor.push_back(NULL);
	}
}

MapNode::~MapNode()
{
	delete fCharacters;
	delete fInventory;
}

const std::string& MapNode::getDesciption()
{
	return fDescription;
}

void MapNode::toggleVisited()
{
	if (fVisited)
	{
		fVisited = false;
	}
	else
	{
		fVisited = true;
	}
}

bool MapNode::hasNeighbor(MapNode* aNode)
{
	for (unsigned int i = 0; i < fNeighbor.size(); i++)
	{
		if (fNeighbor[i] != NULL) {
			if (fNeighbor[i]->fName == aNode->fName)
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

void MapNode::update()
{
	for (unsigned int i = 0; i < fCharacters->fChars.size(); i++)
	{
		fCharacters->fChars[i]->updateCharacter();
	}
}