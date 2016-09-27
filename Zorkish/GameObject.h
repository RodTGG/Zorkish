#pragma once
#include "IdeableObject.h"

/// <summary>
/// A gameobject the base class for all objects
/// </summary>
/// <seealso cref="IdeableObject" />
class GameObject :
	public IdeableObject
{
protected:
	std::string fdescription;							// long description of object
	std::string fshortdesc;								// a shorter description
	std::string fname;									// name of object
private:
	IdeableObject* idobject;							// object id's
public:
	GameObject(std::string aName, std::string aId[2]);
	GameObject(std::string aName, std::string aDesc, std::string aId[2]);
	~GameObject();

	std::string name() { return fname; };				// Returns object name
	std::string shortDesc() { return fshortdesc; };		// Returns short description
	virtual std::string fullDesc() = 0;					// Returns fullDesc
};
