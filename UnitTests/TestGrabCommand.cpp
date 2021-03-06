#include "stdafx.h"
#include "CppUnitTest.h"
#include "..\Zorkish\Player.h"
#include "..\Zorkish\Graph.h"
#include "..\Zorkish\MoveCommand.h"
#include "..\Zorkish\LookCommand.h"
#include "..\Zorkish\GrabCommand.h"
#include "..\Zorkish\PutCommand.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestGrabCommand
{
	/*	Tests different aspects of the Grab command	*/
	TEST_CLASS(TestGrabCommand)
	{
	public:

		/* Tests if the player can grab items in a container withing the maps inventory
		this would simulate a chest or bags.
		Asserts if player can grab item withing mapnode inventory item container called bag.
		*/
		TEST_METHOD(TestPlayerGrabContainer)
		{
			Player* p = new Player();
			Graph* myGraph = new Graph();
			GrabCommand* put = new GrabCommand("grab");
			Item* gun = new Item("9mm", "a 9mm weapon", new std::string[2]{ "gun", "pistol" });

			myGraph->readFile("Adventure.txt");

			p->getInventory()->Put(gun);
			p->setLocation(myGraph->adjlist[0]);

			Assert::IsTrue(p->getInventory()->HasItem("gun"));
			Assert::IsTrue(p->getLocation()->fInventory->HasItem("bag"));
			put->Execute(p, std::vector<std::string>{"grab", "gun", "from", "bag"});
			Assert::IsFalse(p->getLocation()->fInventory->getContainer("bag")->HasItem("gun"));
		}
	};
}