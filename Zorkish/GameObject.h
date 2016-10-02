#pragma once
#include "IdeableObject.h"
#include "Damage.h"

/// <summary>
/// A gameobject the base class for all objects
/// </summary>
/// <seealso cref="IdeableObject" />

class GameObject :
	public IdeableObject
{
protected:
	std::string fDescription;							// long description of object
	std::string fShortdesc;								// a shorter description
	std::string fName;									// name of object
private:
	IdeableObject* fIdObject;							// object id's
	Damage* fDamage;									// Damage object

	int fResistances[4];								// Resistances 0, fire, 1 ice, 2 lightning, 3 dark.
public:
	GameObject(std::string aName, std::string aDesc, std::string aId[2]);
	GameObject(std::string aName, std::string aDesc, std::string aId[2], Damage* aDmg);
	GameObject(std::string aName, std::string aDesc, std::string aId[2], Damage* aDmg, int aResistance[4]);
	~GameObject();

	// Properties
	std::string getName() { return fName; };				// Returns object name
	std::string getShortDesc() { return fShortdesc; };		// Returns short description
	virtual std::string getFullDesc() = 0;					// Returns fullDesc
	Damage* getDamage();

	// Resistances
	int getFireResistance();
	int getLightningResistance();
	int getDarkResistance();
	int getIceResistance();
};