#pragma once
#include "GameObject.h"
#include "Inventory.h"
#include "Graph.h"

class Player :
	public GameObject
{
private:
	int fhp = 100;
	int fscore = 0;
	int fmoves = 0;
	bool falive = true;

	MapNode* flocation = NULL;
	Graph* fmap = NULL;
public:
	Player();
	Player(std::string name, std::string desc);
	~Player();

	Inventory* inv = new Inventory();
	std::string fullDesc() override;
	GameObject* Locate(std::string aId);

	const int score();
	const int hp();
	const bool alive();
	const int moves();
	MapNode* currentLocation();
	void setLocation(MapNode* aLocation);
};
