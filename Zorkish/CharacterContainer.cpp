#include "stdafx.h"
#include "CharacterContainer.h"

using namespace Zorkish;

CharacterContainer::CharacterContainer()
{
}


CharacterContainer::~CharacterContainer()
{
}

void CharacterContainer::removeChar(std::string aName)
{

	for (unsigned int i = 0; i < fChars.size(); i++)
	{
		if (fChars[i]->AreYou(aName))
		{
			fChars.erase(fChars.begin() + i);
			break;
		}
	}

	fChars.resize(fChars.size());
}

void CharacterContainer::addChars(GameObject* aChar) 
{
	fChars.push_back(aChar);
}

bool CharacterContainer::hasChar(std::string aName)
{
	bool result = false;

	for (unsigned int i = 0; i < fChars.size(); i++)
	{
		if (fChars[i]->AreYou(aName)) 
		{
			result = true;
		}
	}

	return result;
}