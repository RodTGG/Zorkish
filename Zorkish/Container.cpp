#include "stdafx.h"
#include "Container.h"


Container::Container(std::string aName, std::string aDesc, std::string aId[]) : Item(aName,aDesc,aId)
{
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
		if (fItems[i]->AreYou(aId))
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
		result += fItems[i]->name() + "\t" + fItems[i]->shortDesc() + "\n";
	}
	return result;
}

std::string Container::fullDesc()
{
	return  fname + " contains: " + ItemList();
}