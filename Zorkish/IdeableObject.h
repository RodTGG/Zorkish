#pragma once

/// <summary>
/// IdeableObject Class
/// An ideable object contains two id's which it can be identified with.
/// </summary>

class IdeableObject
{
private:
	std::string fIdentifiers[2] = { "","" };							// Identifiers, are the id's of the object

public:
	IdeableObject(std::string aIdents[2]);
	~IdeableObject();

	bool AreYou(std::string aId);									// Checks if string matches any of the Id's
	std::string FirstId() { return fIdentifiers[0]; };				// Returns the first id
};