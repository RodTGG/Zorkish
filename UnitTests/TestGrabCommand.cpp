#include "stdafx.h"
#include "CppUnitTest.h"
#include "..\Zorkish\Player.h"
#include "..\Zorkish\Graph.h"
#include "..\Zorkish\MoveCommand.h"
#include "..\Zorkish\LookCommand.h"
#include "..\Zorkish\GrabCommand.h"
#include "..\Zorkish\PutCommand.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace Zorkish;

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

			myGraph->addNode(new MapNode("1", "a cool map"));
			myGraph->addNode(new MapNode("2", "a warm map"));
			myGraph->addNode(new MapNode("3", "a cold map"));
			myGraph->addNode(new MapNode("4", "a hot map"));

			myGraph->addNeighbor("1", "2", "N");
			myGraph->addNeighbor("1", "3", "E");
			myGraph->addNeighbor("1", "4", "W");
			myGraph->addNeighbor("2", "4", "S");
			myGraph->addNeighbor("3", "4", "W");


			p->getInventory()->Put(gun);
			p->setLocation(myGraph->adjlist[0]);

			Assert::IsTrue(p->getInventory()->HasItem("gun"));
			Assert::IsTrue(p->getLocation()->fInventory->HasItem("bag"));
			put->Execute(p, std::vector<std::string>{"grab", "gun", "from", "bag"});
			Assert::IsFalse(p->getLocation()->fInventory->getContainer("bag")->HasItem("gun"));
		}
	};
}