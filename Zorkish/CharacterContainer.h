#pragma once
class Character;

class CharacterContainer
{
public:
	CharacterContainer();
	~CharacterContainer();

	Character* getChar(std::string aName);
	bool hasChar(std::string aName);
	void addChars(Character* aChar);
	void removeChar(std::string aName);
	std::string getCharList();

	std::vector<Character*> fChars;
};