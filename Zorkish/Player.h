#pragma once
#include "Character.h"

/// <summary>
/// Player Class
/// </summary>
/// <seealso cref="GameObject" />

class Player :
	public Character
{
private:
	int fScore = 0;										// Player score
	int fMoves = 0;										// Amount of player moves

public:
	Player();											// Player default constructor
	Player(std::string aName, std::string aDesc);		// Alternate constructor with name and description
	~Player();

	// Properties
	const int getScore();								// Returns Score
	const int getMoves();								// returns number of moves
};