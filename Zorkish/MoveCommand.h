#pragma once
#include "Command.h"

/// <summary>
/// Move Command for the game.
///	moves the player from one node to another
/// </summary>
/// <seealso cref="Command" />
class MoveCommand :
	public Command
{
public:	
	/// <summary>
	/// Initializes a new instance of the <see cref="MoveCommand"/> class.
	/// </summary>
	MoveCommand(std::string aName);

	/// <summary>
	/// Finalizes an instance of the <see cref="MoveCommand"/> class.
	/// </summary>
	~MoveCommand();
	
	/// <summary>
	/// Executes the specified p.
	/// </summary>
	/// <param name="p">The p.</param>
	/// <param name="aText">a text.</param>
	/// <returns>text to display</returns>
	std::string Execute(Player* p, std::vector<std::string> aText) override;
	
	/// <summary>
	/// Changes the location based on user input.
	/// </summary>
	/// <param name="p">The p.</param>
	/// <param name="direction">The direction.</param>
	/// <returns>description of map node</returns>
	std::string ChangeLocation(Player* p, std::string direction);
};
