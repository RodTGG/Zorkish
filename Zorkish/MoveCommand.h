#pragma once
#include "Command.h"

/// <summary>
/// Move command class
/// moves player around the map
/// </summary>
/// <seealso cref="Command" />
class MoveCommand :
	public Command
{
public:
	MoveCommand(std::string aName);
	~MoveCommand();
	std::string Execute(Player* p, std::vector<std::string> aText) override;

	/// <summary>
	/// Changes the location based on user input.
	/// </summary>
	/// <param name="p">The player.</param>
	/// <param name="direction">The direction.</param>
	/// <returns>description of map node</returns>
	std::string ChangeLocation(Player* p, std::string direction);
};