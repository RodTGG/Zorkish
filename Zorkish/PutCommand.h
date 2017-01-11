#pragma once
#include "Command.h"

/// <summary>
/// Puts command class
/// Attemts to put items in containers
/// </summary>
/// <seealso cref="Command" />
class PutCommand :
	public Command
{
public:
	PutCommand(std::string aName);
	~PutCommand();

	std::string Execute(Player* p, std::vector<std::string> aText) override;
	
	/// <summary>
	/// Puts the item in the first container in finds.
	/// </summary>
	/// <param name="p">The player.</param>
	/// <param name="aObject">a object.</param>
	/// <returns></returns>
	std::string putItem(Player* p, std::string aObject);
	
	/// <summary>
	/// Puts the item in specified container.
	/// </summary>
	/// <param name="p">The player.</param>
	/// <param name="aObject">a object.</param>
	/// <param name="aContainer">a container.</param>
	/// <returns></returns>
	std::string putItem(Player* p, std::string aObject, std::string aContainer);
};