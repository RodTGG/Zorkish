#pragma once
#include "Item.h"
#include <vector>

class Container :
	public Item
{
private:

public:
	Container();
	Container(std::string aName, std::string aDesc, std::string aId[2]);
	~Container();

	std::vector<Item*> fItems;

	virtual bool HasItem(std::string aId);				// Returns true if item with ID exists
	virtual void Put(Item* aItm);						// Adds new item to front of invetory
	virtual Item* Take(std::string aId);				// Returns item from invetory, also deletes item.
	virtual Item* Fetch(std::string aId);				// Returns copy of item
	virtual std::string ItemList();						// Returns a string with a lits of all items
	virtual Container* getContainer(std::string aName);
	std::string getFullDesc() override;
	std::string getShortDesc() override;
};