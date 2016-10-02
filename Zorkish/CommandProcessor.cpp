#include "stdafx.h"
#include "CommandProcessor.h"
#include "MoveCommand.h"
#include "LookCommand.h"
#include "GrabCommand.h"
#include "PutCommand.h"

using namespace Zorkish;

CommandProcessor::CommandProcessor()
{
	addCommand(new LookCommand("look"));
	addCommand(new LookCommand("l"));
	addCommand(new MoveCommand("move"));
	addCommand(new MoveCommand("go"));
	addCommand(new GrabCommand("grab"));
	addCommand(new GrabCommand("take"));
	addCommand(new PutCommand("put"));
	addCommand(new PutCommand("drop"));
}

CommandProcessor::~CommandProcessor()
{
}

void CommandProcessor::Tokenizer(const std::string& str, std::vector<std::string>& fTokens, const std::string& delimiters)
{
	// Skip delimiters at beginning.
	std::string::size_type lastPos = str.find_first_not_of(delimiters, 0);
	// Find first "non-delimiter".
	std::string::size_type pos = str.find_first_of(delimiters, lastPos);

	while (std::string::npos != pos || std::string::npos != lastPos)
	{
		// Found a token, add it to the vector.
		fTokens.push_back(str.substr(lastPos, pos - lastPos));
		// Skip delimiters.  Note the "not_of"
		lastPos = str.find_first_not_of(delimiters, pos);
		// Find next "non-delimiter"
		pos = str.find_first_of(delimiters, lastPos);
	}
}

void CommandProcessor::addCommand(Command* aCommand)
{
	std::string name = aCommand->name();
	std::transform(name.begin(), name.end(), name.begin(), ::tolower);

	fcommands[name] = aCommand;
}

std::string CommandProcessor::executeCommand(Player* p, std::string aText)
{
	std::string result = "";
	Command* command = NULL;

	// Split user input by spaces
	Tokenizer(aText, ftokens);

	// Transform all tokens to lowercase for comparison
	for (unsigned int i = 0; i < ftokens.size(); i++)
	{
		std::transform(ftokens[i].begin(), ftokens[i].end(), ftokens[i].begin(), ::tolower);
	}

	if (hasCommand(ftokens[0])) {
		command = getCommand(ftokens[0]);
		result = command->Execute(p, ftokens);
	}
	else
	{
		result = "Not a command ";
	}

	ftokens.clear();

	return result;
}

bool CommandProcessor::hasCommand(std::string aCommand)
{
	bool result = false;

	if (fcommands.find(aCommand) != fcommands.end())
	{
		result = true;
	}
	else
	{
		result = false;
	}

	return result;
}

Command* CommandProcessor::getCommand(std::string aCommand)
{
	Command* result = NULL;

	if (hasCommand(aCommand))
	{
		result = fcommands[aCommand];
	}
	else
	{
		result = NULL;
	}

	return result;
}