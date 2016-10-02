#pragma once
#include "Container.h"
#include "GameObject.h"
#include "MapNode.h"

/// <summary>
/// Character base class
///	Character can receive damage
/// </summary>
/// <seealso cref="GameObject" />

class Character :
	public GameObject
{
public:
	Character(std::string aName, std::string aDesc, std::string aId[2]);									// Default contructor, damage 0, resitance 0
	Character(std::string aName, std::string aDesc, std::string aId[2], Damage* aDmg);						// Specified damage
	Character(std::string aName, std::string aDesc, std::string aId[2], Damage* aDmg, int aResistance[4]);	// Specified damage and resistance
	~Character();

	GameObject* Locate(std::string aId);			// Locates object, character or item in inv
	void setLocation(MapNode* aLocation);			// Sets the Location

	const int getHp();								// Returns hp
	const bool isAlive();							// Returns alive state

	void receiveDamage(Damage* aDamage);			// Takes damage
	void updateCharacter();							// Updates Character

	Container* getInventory();						// Returns invetory
	MapNode* getLocation();							// Returns current mapnode
	virtual std::string getFullDesc() override;		// Full description (item list)

private:
	MapNode* flocation = NULL;						// Character location
protected:
	int fHp = 100;									// Default hp, this allows new entities to have a default hp and not need pass as param
	bool fAlive = true;								// Player alive state

	Container* fInventory;							// Inventory
};