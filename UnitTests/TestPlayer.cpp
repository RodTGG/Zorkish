#include "stdafx.h"
#include "CppUnitTest.h"
#include "..\Zorkish\Item.h"
#include "..\Zorkish\Player.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestPlayer
{
	TEST_CLASS(TestPlayer)
	{
	public:

		TEST_METHOD(TestPlayerAddItem)
		{
			Item* gun = new Item("9mm", "a 9mm weapon", new std::string[2]{ "gun", "pistol" });
			Player* p = new Player();
			p->getInventory()->Put(gun);

			Assert::IsTrue(p->getInventory()->HasItem("gun"));
		}

		TEST_METHOD(TestPlayerRemoveItem)
		{
			Item* gun = new Item("9mm", "a 9mm weapon", new std::string[2]{ "gun", "pistol" });
			Player* p = new Player();
			p->getInventory()->Put(gun);

			Assert::IsTrue(p->getInventory()->HasItem("gun"));
			p->getInventory()->Take("gun");
			Assert::IsFalse(p->getInventory()->HasItem("gun"));
		}
	};
}