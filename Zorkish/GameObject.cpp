#include "stdafx.h"
#include "GameObject.h"


GameObject::GameObject(std::string aName, std::string aId[2]) : IdeableObject(aId)
{
	name = aName;
	shortdesc = name + "(" + aId[0] + ")";
	idobject = new IdeableObject(aId);
}

GameObject::GameObject(std::string aName, std::string aDesc, std::string aId[2]) : IdeableObject(aId)
{
	name = aName;
	description = aDesc;
	shortdesc = name + "(" + aId[0] + ")";
	idobject = new IdeableObject(aId);
}


GameObject::~GameObject()
{
}
