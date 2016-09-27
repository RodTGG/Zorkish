#pragma once
#include "GameObject.h"
#include "Inventory.h"
#include "Graph.h"

/// <summary>
/// Player Class
/// </summary>
/// <seealso cref="GameObject" />
class Player :
	public GameObject
{
private:
	int fhp = 100;									// Player hp
	int fscore = 0;									// Player score
	int fmoves = 0;									// Amount of player moves
	bool falive = true;								// Player state alive

	MapNode* flocation = NULL;						// Player location
	Graph* fmap = NULL;								// Graph/Map Kept in player for so that there is no need to pass as paremeter
public:
	Player();										// Player default constructor
	Player(std::string name, std::string desc);		// Alternate constructor with name and description
	~Player();

	Inventory* inv = new Inventory();				// Inventory
	std::string fullDesc() override;				// Full description (item list)
	GameObject* Locate(std::string aId);			// Locates object, player or item in inv
	void setLocation(MapNode* aLocation);			// Sets the Location

	// Properties
	const int score();								// Returns Score
	const int hp();									// Returns hp
	const bool alive();								// Returns alive state
	const int moves();								// returns number of moves
	MapNode* currentLocation();						// Returns current mapnode
};
