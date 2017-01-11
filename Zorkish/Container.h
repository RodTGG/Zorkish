#pragma once
#include "Item.h"
#include <vector>

class Container :
	public Item
{
private:
	bool fLocked = false;
public:
	Container();
	Container(std::string aName, std::string aDesc, std::string aId[2]);
	Container(std::string aName, std::string aDesc, bool aLocked, std::string aKey, std::string aId[2]);
	~Container();

	std::vector<Item*> fItems;

	void open(Item* myKey);
	bool HasItem(std::string aId);				// Returns true if item with ID exists
	void Put(Item* aItm);						// Adds new item to front of invetory
	Item* Take(std::string aId);				// Returns item from invetory, also deletes item.
	Item* Fetch(std::string aId);				// Returns copy of item
	std::string ItemList();						// Returns a string with a lits of all items
	Container* getContainer(std::string aName);
	std::string getFullDesc() override;
	std::string getShortDesc() override;

	std::string fKey = "";
	bool isLocked();
};