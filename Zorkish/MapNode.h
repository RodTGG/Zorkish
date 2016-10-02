#pragma once
#include "Container.h"
#include "CharacterContainer.h"

namespace Zorkish {
	class MapNode
	{
	private:
		std::string fDescription = "";												// description of current map node
		bool fVisited = false;														// has node already been visited
	public:
		std::string fName = "";
		std::vector<MapNode*> fNeighbor;

		CharacterContainer* fCharacters;
		Container* fInventory;														// mapnodes inventory and items

		MapNode();																	// default constructor
		MapNode(std::string aName, std::string aDesc);								// constructor with just description
		MapNode(std::string aName, std::string aDesc, Item aItems[]);				// constructor with items
		~MapNode();


		const std::string& getDesciption();											// return constant reference to description
		void toggleVisited();
		bool hasNeighbor(MapNode* aNode);
		void addCharacter(GameObject* aChar);
	};
}