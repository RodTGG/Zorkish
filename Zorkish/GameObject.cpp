#include "stdafx.h"
#include "GameObject.h"

GameObject::GameObject(std::string aName, std::string aId[2]) : IdeableObject(aId)
{
	fname = aName;
	fshortdesc = fname + "(" + aId[0] + ")";
	idobject = new IdeableObject(aId);
}

GameObject::GameObject(std::string aName, std::string aDesc, std::string aId[2]) : IdeableObject(aId)
{
	fname = aName;
	fdescription = aDesc;
	fshortdesc = fname + "(" + aId[0] + ")";
	idobject = new IdeableObject(aId);
}

GameObject::~GameObject()
{
	delete idobject;
}