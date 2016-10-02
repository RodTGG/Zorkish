#include "stdafx.h"
#include "CharacterContainer.h"
#include "Character.h"

CharacterContainer::CharacterContainer()
{
}

CharacterContainer::~CharacterContainer()
{
}

Character* CharacterContainer::getChar(std::string aName)
{
	Character* result = NULL;

	for (unsigned int i = 0; i < fChars.size(); i++)
	{
		if (fChars[i]->AreYou(aName))
		{
			result = fChars[i];
			break;
		}
	}
	return result;
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

void CharacterContainer::addChars(Character* aChar)
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

std::string CharacterContainer::getCharList()
{
	std::string result = "";

	for (unsigned int i = 0; i < fChars.size(); i++)
	{
		result += fChars[i]->getName() + "\t" + fChars[i]->getShortDesc() + "\n";
	}
	return result;
}