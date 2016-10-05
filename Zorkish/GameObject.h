#pragma once
#include "IdeableObject.h"
#include "Damage.h"
#include "Resistance.h"

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
	Damage* fDamage;									// Damage object
	Resistance* fResistance;
private:
	IdeableObject* fIdObject;							// object id's
public:
	GameObject(std::string aName, std::string aDesc, std::string aId[2]);
	GameObject(std::string aName, std::string aDesc, std::string aId[2], Damage* aDmg);
	GameObject(std::string aName, std::string aDesc, std::string aId[2], Damage* aDmg, Resistance* aResistance);
	~GameObject();

	// Properties
	std::string getName() { return fName; };				// Returns object name
	virtual std::string getShortDesc() { return fShortdesc; };		// Returns short description
	virtual std::string getFullDesc() = 0;					// Returns fullDesc
	const Damage* getDamage();
	const Resistance* getResistance();

	// Resistances
	int getFireResistance();
	int getLightningResistance();
	int getDarkResistance();
	int getIceResistance();
};