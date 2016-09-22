#pragma once
#include "IdeableObject.h"
class GameObject :
	public IdeableObject
{
protected:
	std::string description;
	std::string shortdesc;
	std::string name;
private:
	IdeableObject* idobject;
public:
	GameObject(std::string aName, std::string aId[2]);
	GameObject(std::string aName, std::string aDesc, std::string aId[2]);
	~GameObject();

	std::string Name() { return name; };
	std::string ShortDesc() { return shortdesc; };
	virtual std::string FullDesc() = 0;
};

