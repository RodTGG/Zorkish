#pragma once
#include "IdeableObject.h"
#include "Item.h"
#include <vector>

class Inventory : std::vector<Item>
{
private:
	std::vector<GameObject*> items;
public:
	Inventory();
	~Inventory();

	//GameObject* null;

	bool HasItem(std::string aId);
	void Put(GameObject* aItm);
	GameObject* Take(std::string aId);
	GameObject* Fetch(std::string aId);
	std::string ItemList();
};
