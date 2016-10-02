#pragma once
#include "States.h"

class GameState
{
private:
	int id;
public:
	GameState() {};
	GameState(int aId) { id = aId; };
	virtual ~GameState() {};

	virtual void logic() = 0;
	virtual void display() = 0;
	virtual int handle_event() = 0;

	// Properties
	const int ID() { return id; };
};