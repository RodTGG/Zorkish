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
			p->inv->Put(gun);

			Assert::IsTrue(p->inv->HasItem("gun"));
		}

		TEST_METHOD(TestPlayerRemoveItem)
		{
			Item* gun = new Item("9mm", "a 9mm weapon", new std::string[2]{ "gun", "pistol" });
			Player* p = new Player();
			p->inv->Put(gun);

			Assert::IsTrue(p->inv->HasItem("gun"));
			p->inv->Take("gun");
			Assert::IsFalse(p->inv->HasItem("gun"));
		}
	};
}