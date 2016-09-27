#pragma once
#include "GameState.h"
#include "GameMode.h"
#include "Player.h"

/// <summary>
/// GameStateManager
///	Manages the states of the program.
/// </summary>
class GameStateManager
{
public:
	GameStateManager();
	~GameStateManager();

	void set_next_state(int aState);			// Sets the next state id
	void change_state();						// Changes to the next state
	int CurrentState();							// Returns id of current state

	void Display();								// Displays the states display function
	void ExecuteState();						// Executes the states logic
private: 
	int nextState = NULL;						// Id of next state

	GameState* fState = NULL;					// GameState object pointer
	Player* fPlayer = new Player();				// Player object pointer
	GameMode* fGameMode = NULL;					// GameMode object pointer
};
