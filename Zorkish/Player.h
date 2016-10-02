#pragma once
#include "Character.h"

/// <summary>
/// Player Class
/// </summary>
/// <seealso cref="GameObject" />
namespace Zorkish {
	class Player :
		public Character
	{
	private:
		int fScore = 0;									// Player score
		int fMoves = 0;									// Amount of player moves

		//Graph* fMap = NULL;								// Graph/Map Kept in player for so that there is no need to pass as paremeter
	public:
		Player();										// Player default constructor
		Player(std::string aName, std::string aDesc);		// Alternate constructor with name and description
		~Player();



		// Properties
		const int getScore();								// Returns Score
		const int getMoves();								// returns number of moves
	};
}