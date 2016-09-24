#pragma once
#include "IdeableObject.h"
#include "Item.h"
#include <vector>

class Inventory : std::vector<Item>
{
private:
	std::vector<Item*> items;
public:
	Inventory();
	~Inventory();

	//GameObject* null;

	bool HasItem(std::string aId);
	void Put(Item* aItm);
	Item* Take(std::string aId);
	Item* Fetch(std::string aId);
	std::string ItemList();
};
