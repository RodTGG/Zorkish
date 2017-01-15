#pragma once
class Character;

/// <summary>
/// Character Container class
/// Provides functions for containing charcters in vector
/// </summary>
class CharacterContainer
{
public:	
	/// <summary>
	/// Initializes a new instance of the <see cref="CharacterContainer"/> class.
	/// </summary>
	CharacterContainer();
	
	/// <summary>
	/// Finalizes an instance of the <see cref="CharacterContainer"/> class.
	/// </summary>
	~CharacterContainer();
	
	/// <summary>
	/// Gets the character based on name.
	/// </summary>
	/// <param name="aName">a name of character.</param>
	/// <returns>A pointer to a character</returns>
	Character* getChar(std::string aName);
	
	/// <summary>
	/// Determines whether the specified character exists.
	/// </summary>
	/// <param name="aName">a name.</param>
	/// <returns>
	///   <c>true</c> if the specified a name has character; otherwise, <c>false</c>.
	/// </returns>
	bool hasChar(std::string aName);
	
	/// <summary>
	/// Adds the chars.
	/// </summary>
	/// <param name="aChar">a character pointer.</param>
	void addChars(Character* aChar);
	
	/// <summary>
	/// Removes the character.
	/// </summary>
	/// <param name="aName">a name of character.</param>
	void removeChar(std::string aName);
	
	/// <summary>
	/// Gets the character list.
	/// </summary>
	/// <returns>string containing characters and their description</returns>
	std::string getCharList();
	
	/// <summary>
	/// Character Vector
	/// </summary>
	std::vector<Character*> fChars;
};