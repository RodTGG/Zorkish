#pragma once
#include "GameObject.h"

namespace Zorkish {
	class CharacterContainer
	{
	public:
		CharacterContainer();
		~CharacterContainer();

		bool hasChar(std::string aName);
		void addChars(GameObject* aChar);
		void removeChar(std::string aName);
		std::string getCharList();

		std::vector<GameObject*> fChars;
	};
}