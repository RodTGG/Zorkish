#pragma once
#include <string>

class GameMode
{
private:
	std::string name = "";
public:
	GameMode() {};
	GameMode(std::string aName) { name = aName; };
	virtual ~GameMode() {};
	virtual std::string NAME() { return name; };
};
