#pragma once
#include "GameObject.h"

/// <summary>
/// Item base class
///
/// </summary>
/// <seealso cref="GameObject" />
namespace Zorkish {
	class Item :
		public GameObject
	{
	public:
		Item(std::string name, std::string desc, std::string idents[2]);											// Default constructor
		Item(std::string name, std::string desc, std::string idents[2], Damage* aDmg);			// Alternate constructor with description
		~Item();

		bool isContainer() { return bContainer; };
		std::string getFullDesc() override;										// Returns full description of object
	protected:
		bool bContainer = false;
	};
}