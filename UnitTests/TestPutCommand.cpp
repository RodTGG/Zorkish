#include "stdafx.h"
#include "CppUnitTest.h"
#include "..\Zorkish\Player.h"
#include "..\Zorkish\Graph.h"
#include "..\Zorkish\MoveCommand.h"
#include "..\Zorkish\LookCommand.h"
#include "..\Zorkish\GrabCommand.h"
#include "..\Zorkish\PutCommand.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestPutCommand
{
	/*	Tests different aspects of the put command	*/
	TEST_CLASS(TestPutCommand)
	{
	public:

		/* Tests if the player can put items in a container withing the maps inventory
		this would simulate a chest or bags.
		Asserts if player can put item withing mapnode inventory item container called bag.
		*/
		TEST_METHOD(TestPlayerPutContainer)
		{
			Player* p = new Player();
			Graph* myGraph = new Graph();
			PutCommand* put = new PutCommand("put");
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


			p->inv->Put(gun);
			p->setLocation(myGraph->adjlist[0]);

			Assert::IsTrue(p->inv->HasItem("gun"));
			Assert::IsTrue(p->currentLocation()->fInventory->HasItem("bag"));
			put->Execute(p, std::vector<std::string>{"put", "gun", "in", "bag"});
			Assert::IsTrue(p->currentLocation()->fInventory->getContainer("bag")->HasItem("gun"));
		}
	}
}