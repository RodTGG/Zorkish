#pragma once
#include "GameState.h"
#include "GameMode.h"
#include "Player.h"

/// <summary>
/// GameStateManager
///	Manages the states of the program.
/// </summary>
namespace Zorkish {
	class GameStateManager
	{
	public:
		GameStateManager(bool aDebug);
		GameStateManager();
		~GameStateManager();

		void set_next_state(int aState);			// Sets the next state id
		void change_state();						// Changes to the next state
		int CurrentState();							// Returns id of current state

		void Display();								// Displays the states display function
		void ExecuteState();						// Executes the states logic
	private:
		bool fDebug = false;
		int fnextState = NULL;						// Id of next state

		GameState* fState = NULL;					// GameState object pointer
		Player* fPlayer = NULL;				// Player object pointer
		GameMode* fGameMode = NULL;					// GameMode object pointer
	protected:
		bool DebugMode();
	};
}