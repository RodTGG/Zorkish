#pragma once
#include "Command.h"

/// <summary>
/// Grab command class
/// checks whether something can be grabbed from object and stores it in player inventory
/// </summary>
/// <seealso cref="Command" />
class GrabCommand :
	public Command
{
public:
	GrabCommand(std::string aName);
	~GrabCommand();

	std::string Execute(Player* p, std::vector<std::string> aText) override;
	
	/// <summary>
	/// Grabs the item.
	/// </summary>
	/// <param name="p">The player.</param>
	/// <param name="aObject">a object.</param>
	/// <returns>message based on outcome</returns>
	std::string grabItem(Player* p, std::string aObject);	

	/// <summary>
	/// Grabs the item from container
	/// </summary>
	/// <param name="p">The player.</param>
	/// <param name="aObject">a object.</param>
	/// <param name="aContainer">a container.</param>
	/// <returns>message based on outcome</returns>
	std::string grabItem(Player* p, std::string aObject, std::string aContainer);
};