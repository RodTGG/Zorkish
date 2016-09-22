#pragma once
class IdeableObject
{
private:
	std::string identifiers[2] = {"",""};

public:
	IdeableObject(std::string aIdents[2]);
	~IdeableObject();

	bool AreYou(std::string aId);
	std::string FirstId() { identifiers[0]; };
};

