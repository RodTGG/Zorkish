#pragma once
#include "Item.h"
#include <vector>

/// <summary>
/// Container Class
/// Handles inventory and items
/// </summary>
/// <seealso cref="Item" />
class Container :
	public Item
{
private:	
	/// <summary>
	/// If container is locked
	/// </summary>
	bool fLocked = false;
public:	
	/// <summary>
	/// Initializes a new instance of the <see cref="Container"/> class.
	/// No name, no description, no Id, Unlocked
	/// </summary>
	Container();
	
	/// <summary>
	/// Initializes a new instance of the <see cref="Container"/> class.
	/// </summary>
	/// <param name="aName">a name.</param>
	/// <param name="aDesc">a desc.</param>
	/// <param name="aId">a identifier.</param>
	Container(std::string aName, std::string aDesc, std::string aId[2]);
	
	/// <summary>
	/// Initializes a new instance of the <see cref="Container"/> class.
	/// </summary>
	/// <param name="aName">a name.</param>
	/// <param name="aDesc">a desc.</param>
	/// <param name="aLocked">if set to <c>true</c> [a locked].</param>
	/// <param name="aKey">a key.</param>
	/// <param name="aId">a identifier.</param>
	Container(std::string aName, std::string aDesc, bool aLocked, std::string aKey, std::string aId[2]);
	
	/// <summary>
	/// Finalizes an instance of the <see cref="Container"/> class.
	/// </summary>
	~Container();
	
	/// <summary>
	/// Vector of items
	/// </summary>
	std::vector<Item*> fItems;
	
	/// <summary>
	/// Opens the container with key.
	/// </summary>
	/// <param name="myKey">My key.</param>
	void open(Item* myKey);
	
	/// <summary>
	/// Determines whether the container has specified item.
	/// </summary>
	/// <param name="aId">a identifier.</param>
	/// <returns>
	///   <c>true</c> if the specified item exists; otherwise, <c>false</c>.
	/// </returns>
	bool HasItem(std::string aId);
	
	/// <summary>
	/// Puts the specified item in vector.
	/// </summary>
	/// <param name="aItm">a itm.</param>
	void Put(Item* aItm);
	
	/// <summary>
	/// Takes the specified a identifier.
	/// </summary>
	/// <param name="aId">a identifier.</param>
	/// <returns>Item pointer to item</returns>
	Item* Take(std::string aId);
	
	/// <summary>
	/// Fetches the specified a identifier.
	/// </summary>
	/// <param name="aId">a identifier.</param>
	/// <returns>Item pointer to item</returns>
	Item* Fetch(std::string aId);
	
	/// <summary>
	/// Gets list of items
	/// </summary>
	/// <returns>string with items descriptions</returns>
	std::string ItemList();
	
	/// <summary>
	/// Gets the container.
	/// </summary>
	/// <param name="aName">a name.</param>
	/// <returns>Container with name</returns>
	Container* getContainer(std::string aName);
	
	/// <summary>
	/// Gets the full description.
	/// </summary>
	/// <returns>string long description</returns>
	std::string getFullDesc() override;
		
	/// <summary>
	/// Gets the short desc.
	/// </summary>
	/// <returns>string with short description</returns>
	std::string getShortDesc() override;
	
	/// <summary>
	/// The name of key that opens chest
	/// </summary>
	std::string fKey = "";
	
	/// <summary>
	/// Determines whether this instance is locked.
	/// </summary>
	/// <returns>
	///   <c>true</c> if this instance is locked; otherwise, <c>false</c>.
	/// </returns>
	bool isLocked();
};