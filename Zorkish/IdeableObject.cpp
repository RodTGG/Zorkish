#include "stdafx.h"
#include "IdeableObject.h"
#include <algorithm>

IdeableObject::IdeableObject(std::string aIdents[2])
{
	identifiers[0] = aIdents[0];
	identifiers[1] = aIdents[1];
}

IdeableObject::~IdeableObject()
{
}

bool IdeableObject::AreYou(std::string aId)
{
	bool result = false;
	std::string* temp = identifiers;

	for (int i = 0; i < 2; i++)
	{
		std::transform(temp[i].begin(), temp[i].end(), temp[i].begin(), tolower);
	}
	std::transform(aId.begin(), aId.end(), aId.begin(), tolower);

	for (int i = 0; i < 2; i++)
	{
		if (aId == temp[i])
		{
			result = true;
			break;
		}
	}

	return result;
}