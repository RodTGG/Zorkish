#pragma once
#include "MoveCommand.h"

/// <summary>
/// The command processor
/// Tokenizes text entered and executes commands based on alias.
/// </summary>
class CommandProcessor
{
public:	
	/// <summary>
	/// Initializes a new instance of the <see cref="CommandProcessor"/> class.
	/// </summary>
	CommandProcessor();
		
	/// <summary>
	/// Finalizes an instance of the <see cref="CommandProcessor"/> class.
	/// </summary>
	~CommandProcessor();
	
	/// <summary>
	/// Adds a command to the map list
	/// </summary>
	/// <param name="aCommand">a command pointer.</param>
	void addCommand(Command* aCommand);
	
	/// <summary>
	/// Executes the command.
	/// </summary>
	/// <param name="p">The player.</param>
	/// <param name="aText">text entered.</param>
	/// <returns></returns>
	std::string executeCommand(Player* p, std::string aText);
	
	/// <summary>
	/// Determines whether the specified a command exists based on name.
	/// </summary>
	/// <param name="aCommand">a command name.</param>
	/// <returns>
	///   <c>true</c> if the specified a command exists; otherwise, <c>false</c>.
	/// </returns>
	bool hasCommand(std::string aCommand);
	
	/// <summary>
	/// Gets a command.
	/// </summary>
	/// <param name="aCommand">a command pointer.</param>
	/// <returns>
	///		<c>Command pointer</c> if command is found, else <c>NULL</c>
	///</returns>
	Command* getCommand(std::string aCommand);
private:	
	/// <summary>
	/// The vector of tokenizer tokens
	/// </summary>
	std::vector<std::string> ftokens;	
	/// <summary>
	/// The map list of commands
	/// </summary>
	std::map<std::string, Command*> fcommands;
	
	/// <summary>
	/// Tokenizes the specified string.
	/// </summary>
	/// <param name="str">The string.</param>
	/// <param name="fTokens">The vector to store tokens.</param>
	/// <param name="delimiters">The delimiters.</param>
	void Tokenizer(const std::string& str, std::vector<std::string>& fTokens, const std::string& delimiters = " ");
};