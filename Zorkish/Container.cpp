#include "stdafx.h"
#include "Container.h"

using namespace Zorkish;

Container::Container() : Item("Container", "a container", new std::string[2]{ "container","Container" })
{
	bContainer = true;
}

Container::Container(std::string aName, std::string aDesc, std::string aId[2]) : Item(aName, aDesc, aId)
{
	bContainer = true;
}

Container::~Container()
{
}

bool Container::HasItem(std::string aId)
{
	bool result = false;

	for (unsigned int i = 0; i < fItems.size(); i++)
	{
		if (fItems[i]->AreYou(aId))
		{
			result = true;
			break;
		}
		else
		{
			result = false;
		}
	}

	return result;
}

void Container::Put(Item* aItm)
{
	fItems.push_back(aItm);

	fItems.resize(fItems.size());
}

Item* Container::Take(std::string aId)
{
	Item* result = NULL;

	for (unsigned int i = 0; i < fItems.size(); i++)
	{
		if (fItems[i]->AreYou(aId))
		{
			result = fItems[i];
			fItems.erase(fItems.begin() + i);
			break;
		}
	}

	fItems.resize(fItems.size());

	return result;
}

Item* Container::Fetch(std::string aId)
{
	Item* result = NULL;

	for (unsigned int i = 0; i < fItems.size(); i++)
	{
		if (fItems[i]->AreYou(aId))
		{
			result = fItems[i];
			break;
		}
	}
	return result;
}

Container* Container::getContainer(std::string aId)
{
	Container* result = NULL;

	for (unsigned int i = 0; i < fItems.size(); i++)
	{
		if (fItems[i]->isContainer() && fItems[i]->AreYou(aId))
		{
			result = (Container*)fItems[i];
			break;
		}
	}

	return result;
}

std::string Container::ItemList()
{
	std::string result = "";

	for (unsigned int i = 0; i < fItems.size(); i++)
	{
		result += fItems[i]->getName() + "\t" + fItems[i]->getFullDesc() + "\n";
	}
	return result;
}

std::string Container::getFullDesc()
{
	return  fName + " contains:\n" + ItemList();
}