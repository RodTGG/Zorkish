#pragma once
#include "Command.h"

/// <summary>
/// Opens a locked container
/// Checks container status first.
/// </summary>
/// <seealso cref="Command" />
class OpenCommand :
	public Command
{
public:
	OpenCommand(std::string aName);
	~OpenCommand();

	std::string Execute(Player* p, std::vector<std::string> aText) override;
	
	/// <summary>
	/// Attempts to open the first container it finds.
	/// </summary>
	/// <param name="aPlayer">a player.</param>
	/// <param name="aObject">a object.</param>
	/// <returns>message based on outcome</returns>
	std::string Open(Player* aPlayer, std::string aObject);
	
	/// <summary>
	/// Opens the specified container with an object.
	/// </summary>
	/// <param name="aPlayer">a player.</param>
	/// <param name="aObject">a object.</param>
	/// <param name="aItem">a item.</param>
	/// <returns>message based on outcome</returns>
	std::string OpenWith(Player* aPlayer, std::string aObject, std::string aItem);
};
