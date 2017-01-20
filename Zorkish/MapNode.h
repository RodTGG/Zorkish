#pragma once
#include "Container.h"
#include "CharacterContainer.h"

/// <summary>
/// MapNode class
/// Used to construct graph and map
/// </summary>
class MapNode
{
public:
	/// <summary>
	/// The name
	/// </summary>
	std::string fName = "";
	/// <summary>
	/// The neighbor
	/// </summary>
	std::vector<MapNode*> fNeighbor;

	/// <summary>
	/// The characters
	/// </summary>
	CharacterContainer* fCharacters;

	/// <summary>
	/// The inventory
	/// </summary>
	Container* fInventory;

	/// <summary>
	/// Updates this instance.
	/// </summary>
	void update();

	/// <summary>
	/// Initializes a new instance of the <see cref="MapNode"/> class.
	/// </summary>
	/// <param name="aName">a name.</param>
	/// <param name="aDesc">a desc.</param>
	MapNode(std::string aName, std::string aDesc);

	/// <summary>
	/// Initializes a new instance of the <see cref="MapNode"/> class.
	/// </summary>
	/// <param name="aName">a name.</param>
	/// <param name="aDesc">a desc.</param>
	/// <param name="aItems">a items.</param>
	MapNode(std::string aName, std::string aDesc, Item aItems[]);

	/// <summary>
	/// Initializes a new instance of the <see cref="MapNode" /> class.
	/// </summary>
	~MapNode();
	
	/// <summary>
	/// Gets the desciption.
	/// </summary>
	/// <returns></returns>
	const std::string& getDesciption();
	
	/// <summary>
	/// Toggles the visited.
	/// </summary>
	void toggleVisited();
	
	/// <summary>
	/// Determines whether the specified a node has neighbor.
	/// </summary>
	/// <param name="aNode">a node.</param>
	/// <returns>
	///   <c>true</c> if the specified a node has neighbor; otherwise, <c>false</c>.
	/// </returns>
	bool hasNeighbor(MapNode* aNode);
private:
	/// <summary>
	/// The f description
	/// </summary>
	std::string fDescription = "";
	/// <summary>
	/// The f visited
	/// </summary>
	bool fVisited = false;
};