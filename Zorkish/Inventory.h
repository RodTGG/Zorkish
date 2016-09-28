#pragma once
#include "Container.h"
#include "Item.h"
#include <vector>

/// <summary>
/// Invetory class.
/// Contais gameObject
/// </summary>
/// <seealso cref="std::vector{Item}" />
class Inventory : public Container
{
private:
public:
	Inventory(std::string aName, std::string aDesc, std::string aId[]);
	~Inventory();
};
