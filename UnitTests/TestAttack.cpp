#include "stdafx.h"
#include "CppUnitTest.h"
#include "..\Zorkish\Player.h"
#include "..\Zorkish\Graph.h"
#include "..\Zorkish\AttackCommand.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestAttack
{
	/*	Tests different aspects of the Grab command	*/
	TEST_CLASS(TestAttack)
	{
	public:

		/* Tests if the player can grab items in a container withing the maps inventory
		this would simulate a chest or bags.
		Asserts if player can grab item withing mapnode inventory item container called bag.
		*/
		TEST_METHOD(AttackObject)
		{
			Player* p = new Player();
			Graph* myGraph = new Graph();
			AttackCommand* attack = new AttackCommand("grab");
			Item* gun = new Item("9mm", "a 9mm weapon", new std::string[2]{ "gun", "pistol" });

			myGraph->readFile("Adventure.txt");

			p->getInventory()->Put(gun);
			p->setLocation(myGraph->adjlist[0]);

			Assert::IsTrue(p->getInventory()->HasItem("gun"));
			attack->Attack(p,"Squirell");
			Assert::IsTrue(p->getLocation()->fCharacters->getChar("squirell")->getHp() < 100);
		}
	};
}