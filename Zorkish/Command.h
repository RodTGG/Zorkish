#pragma once
#include "Player.h"
#include "BlackBoard.h"

/// <summary>
/// Parent class for commands
/// abstract
/// </summary>
class Command
{
public:	
	/// <summary>
	/// Initializes a new instance of the <see cref="Command"/> class with the specified name.
	/// </summary>
	/// <param name="aName">a name.</param>
	Command(std::string aName) { fname = aName; };
	
	/// <summary>
	/// Executes the specified command.
	/// Checks for text patterns and calls functions according to result.
	/// </summary>
	/// <param name="p">The player.</param>
	/// <param name="aText">text entered.</param>
	/// <returns>message based on outcome</returns>
	virtual std::string Execute(Player* p, std::vector<std::string> aText) = 0;
	
	/// <summary>
	/// Name of this instance.
	/// </summary>
	/// <returns>String name of instance</returns>
	virtual std::string name() { return fname; };
private:	
	/// <summary>
	/// The name
	/// </summary>
	std::string fname;
protected:	
	/// <summary>
	/// The blackboard
	/// </summary>
	BlackBoard* fBlackboard = new BlackBoard();
};