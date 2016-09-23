#pragma once
#include "Command.h"
class GoCommand : 
	public Command
{
public:
	GoCommand();
	~GoCommand();

	void Run() override;
};

