#pragma once
#include "GameObject.h"

/// <summary>
/// Item base class
/// 
/// </summary>
/// <seealso cref="GameObject" />
class Item :
	public GameObject
{
public:
	Item(std::string name, std::string idents[]);							// Default constructor
	Item(std::string name, std::string desc, std::string idents[]);			// Alternate constructor with description
	~Item();

	std::string fullDesc() override;										// Returns full description of object
};
