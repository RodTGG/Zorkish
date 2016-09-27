#pragma once
#include "IdeableObject.h"
#include "Item.h"
#include <vector>

/// <summary>
/// Invetory class.
/// Contais gameObject
/// </summary>
/// <seealso cref="std::vector{Item}" />
class Inventory
{
private:
	std::vector<Item*> items;				// Vector of items
public:
	Inventory();
	~Inventory();

	bool HasItem(std::string aId);			// Returns true if item with ID exists
	void Put(Item* aItm);					// Adds new item to front of invetory
	Item* Take(std::string aId);			// Returns item from invetory, also deletes item.
	Item* Fetch(std::string aId);			// Returns copy of item
	std::string ItemList();					// Returns a string with a lits of all items
};
