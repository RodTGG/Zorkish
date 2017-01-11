#pragma once
#include "Character.h"

/// <summary>
/// Player Class
/// Base class for player
/// Kepps track of score and moves
/// </summary>
/// <seealso cref="GameObject" />
class Player :
	public Character
{
public:	
	/// <summary>
	/// Initializes a new instance of the <see cref="Player"/> class.
	/// </summary>
	Player();	

	/// <summary>
	/// Initializes a new instance of the <see cref="Player"/> class with the specified name and description.
	/// </summary>
	/// <param name="aName">a name.</param>
	/// <param name="aDesc">a description.</param>
	Player(std::string aName, std::string aDesc);
	
	/// <summary>
	/// Finalizes an instance of the <see cref="Player"/> class.
	/// </summary>
	~Player();
	
	/// <summary>
	/// Gets the score.
	/// </summary>
	/// <returns>Int player score</returns>
	const int getScore();
		
	/// <summary>
	/// Gets the moves.
	/// </summary>
	/// <returns>Int player moves</returns>
	const int getMoves();
private:
	/// <summary>
	/// The Players score
	/// </summary>
	int fScore = 0;

	/// <summary>
	/// The number of moves
	/// </summary>
	int fMoves = 0;
};