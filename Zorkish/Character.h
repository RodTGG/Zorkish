#pragma once
#include "Container.h"
#include "GameObject.h"
#include "MapNode.h"

/// <summary>
/// Character base class
///	Character can receive damage which is substracted from their resistance
/// </summary>
/// <seealso cref="GameObject" />
class Character :
	public GameObject
{
public:
	/// <summary>
	/// Default constructor, Initializes a new instance of the <see cref="Character"/> class.
	/// hp 100, damage 0, resistance 0
	/// </summary>
	/// <param name="aName">a name.</param>
	/// <param name="aDesc">a desc.</param>
	/// <param name="aId">a identifier.</param>
	Character(std::string aName, std::string aDesc, std::string aId[2]);

	/// <summary>
	/// Initializes a new instance of the <see cref="Character"/> class.
	/// hp, 100, resistance 0
	/// </summary>
	/// <param name="aName">a name.</param>
	/// <param name="aDesc">a desc.</param>
	/// <param name="aId">a identifier.</param>
	/// <param name="aDmg">a DMG.</param>
	Character(std::string aName, std::string aDesc, std::string aId[2], Damage* aDmg);

	/// <summary>
	/// Initializes a new instance of the <see cref="Character"/> class.
	/// hp 100
	/// </summary>
	/// <param name="aName">a name.</param>
	/// <param name="aDesc">a desc.</param>
	/// <param name="aId">a identifier.</param>
	/// <param name="aDmg">a DMG.</param>
	/// <param name="aResistance">a resistance.</param>
	Character(std::string aName, std::string aDesc, std::string aId[2], Damage* aDmg, Resistance* aResistance);

	/// <summary>
	/// Finalizes an instance of the <see cref="Character"/> class.
	/// </summary>
	~Character();

	/// <summary>
	/// Locates the specified item.
	/// </summary>
	/// <param name="aId">a identifier for object.</param>
	/// <returns>GameObject pointer</returns>
	GameObject* Locate(std::string aId);

	/// <summary>
	/// Sets the location.
	/// </summary>
	/// <param name="aLocation">a location.</param>
	void setLocation(MapNode* aLocation);

	/// <summary>
	/// Gets the hp.
	/// </summary>
	/// <returns>Int, character hp</returns>
	const int getHp();

	/// <summary>
	/// Determines whether this instance is alive.
	/// </summary>
	/// <returns>bool, true if player is alive</returns>
	const bool isAlive();

	/// <summary>
	/// Receives the damage.
	/// </summary>
	/// <param name="aDamage">a damage.</param>
	void receiveDamage(const Damage* aDamage);

	/// <summary>
	/// Updates this instance.
	/// </summary>
	void update() override;

	/// <summary>
	/// Gets the inventory.
	/// </summary>
	/// <returns>Container pointer</returns>
	Container* getInventory();

	/// <summary>
	/// Gets the location.
	/// </summary>
	/// <returns>MapNode pointer</returns>
	MapNode* getLocation();

	/// <summary>
	/// Gets the full desc.
	/// </summary>
	/// <returns>string, description of this</returns>
	virtual std::string getFullDesc() override;
private:
	/// <summary>
	/// The flocation
	/// </summary>
	MapNode* flocation;
protected:
	/// <summary>
	/// The f hp
	/// </summary>
	int fHp = 100;

	/// <summary>
	/// The f alive
	/// </summary>
	bool fAlive = true;

	/// <summary>
	/// The f inventory
	/// </summary>
	Container* fInventory;
};