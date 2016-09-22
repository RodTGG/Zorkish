#pragma once
#include "GameObject.h"
class Item :
	public GameObject
{
public:
	Item(std::string name, std::string desc, std::string idents[]);
	~Item();

	std::string FullDesc() override;
};

