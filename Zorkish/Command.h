#pragma once
#include "GameObject.h"
class Command :
	public GameObject
{
public:
	Command();
	~Command();

	virtual void Run() = 0;
private:
};

