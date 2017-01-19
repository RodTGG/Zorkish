#pragma once
#include "GameObject.h"

/// <summary>
/// Item base class
/// </summary>
/// <seealso cref="GameObject" />
class Item :
	public GameObject
{
public:	
	/// <summary>
	/// Initializes a new instance of the <see cref="Item"/> class.
	/// </summary>
	/// <param name="name">The name.</param>
	/// <param name="desc">The description.</param>
	/// <param name="idents">The identifiers.</param>
	Item(std::string name, std::string desc, std::string idents[2]);
	
	/// <summary>
	/// Initializes a new instance of the <see cref="Item"/> class.
	/// </summary>
	/// <param name="name">The name.</param>
	/// <param name="desc">The description.</param>
	/// <param name="idents">The identifiers.</param>
	/// <param name="aDmg">a DMG.</param>
	Item(std::string name, std::string desc, std::string idents[2], Damage* aDmg);
	
	/// <summary>
	/// Finalizes an instance of the <see cref="Item"/> class.
	/// </summary>
	~Item();
	
	/// <summary>
	/// Determines whether this instance is a container.
	/// </summary>
	/// <returns>
	///   <c>true</c> if this instance is a container; otherwise, <c>false</c>.
	/// </returns>
	bool isContainer() { return bContainer; };
	
	/// <summary>
	/// Gets the full description.
	/// </summary>
	/// <returns>string with full description</returns>
	std::string getFullDesc() override;
protected:	
	/// <summary>
	/// The boolean
	/// </summary>
	bool bContainer = false;
};