#pragma once
#include "MoveCommand.h"

/// <summary>
/// Manages and processes the commands
/// </summary>

class CommandProcessor
{
public:
	CommandProcessor();
	~CommandProcessor();
	void addCommand(Command* aCommand);

	std::string executeCommand(Player* p, std::string aText);
	bool hasCommand(std::string aCommand);
	Command* getCommand(std::string aCommand);
private:
	std::vector<std::string> ftokens;
	std::map<std::string, Command*> fcommands;

	void Tokenizer(const std::string& str, std::vector<std::string>& fTokens, const std::string& delimiters = " ");
};