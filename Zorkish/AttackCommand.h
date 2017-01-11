#pragma once
#include "Command.h"

/// <summary>
/// Attack command class
/// Calculates and modifies objects health according to object statistics
/// </summary>
/// <seealso cref="Command" />
class AttackCommand :
	public Command
{
public:
	/// <summary>
	/// Initializes a new instance of the <see cref="AttackCommand"/> class.
	/// </summary>
	/// <param name="aName">a name for command.</param>
	AttackCommand(std::string aName);

	/// <summary>
	/// Finalizes an instance of the <see cref="AttackCommand"/> class.
	/// </summary>
	~AttackCommand();

	std::string Execute(Player* p, std::vector<std::string> aText) override;

	/// <summary>
	/// Attacks the specified a player.
	/// </summary>
	/// <param name="aPlayer">a player.</param>
	/// <param name="aObject">a object.</param>
	/// <returns>message based on outcome</returns>
	std::string Attack(Player* aPlayer, std::string aObject);

	/// <summary>
	/// Attacks object with item.
	/// </summary>
	/// <param name="aPlayer">a player.</param>
	/// <param name="aObject">a object.</param>
	/// <param name="aItem">a item.</param>
	/// <returns>message based on outcome</returns>
	std::string AttackWith(Player* aPlayer, std::string aObject, std::string aItem);
};
