#pragma once
#include "Command.h"

/// <summary>
/// Look command class
/// Displays contents of object or room
/// Displays descriptions of objects
/// </summary>
/// <seealso cref="Command" />
class LookCommand :
	public Command
{
public:
	LookCommand(std::string aName);
	~LookCommand();

	std::string Execute(Player* p, std::vector<std::string> aText) override;	

	/// <summary>
	/// Looks at object in map or player.
	/// </summary>
	/// <param name="p">The player.</param>
	/// <param name="aItem">a item.</param>
	/// <returns></returns>
	std::string lookAtIn(Player* p, std::string aItem);
	
	/// <summary>
	/// Looks at in object in container.
	/// </summary>
	/// <param name="p">The player.</param>
	/// <param name="aItem">a item.</param>
	/// <param name="aContainer">a container.</param>
	/// <returns></returns>
	std::string lookAtIn(Player* p, std::string aItem, std::string aContainer);

	void blackbMessage(Player* aP);
private:
};