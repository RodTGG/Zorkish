#include "stdafx.h"
#include "Command.h"


Command::Command() : GameObject("A command", "my command", new std::string{"Temp","temp"})
{
}


Command::~Command()
{
}
