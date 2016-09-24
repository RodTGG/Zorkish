#include "stdafx.h"
#include "CppUnitTest.h"
#include "..\Zorkish\Player.h"
#include "..\Zorkish\Graph.h"
#include "..\Zorkish\MoveCommand.h"
#include "..\Zorkish\LookCommand.h"
#include "..\Zorkish\GrabCommand.h"
#include "..\Zorkish\PutCommand.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestCommandProcessor
{
	TEST_CLASS(TestCommandProcessor)
	{
	public:

		TEST_METHOD(TestMoveCommand)
		{
			Player* p = new Player();
			Graph* myGraph = new Graph();
			MoveCommand* move = new MoveCommand("go");

			myGraph->addNode(new MapNode("1", "a cool map"));
			myGraph->addNode(new MapNode("2", "a warm map"));
			myGraph->addNode(new MapNode("3", "a cold map"));
			myGraph->addNode(new MapNode("4", "a hot map"));

			myGraph->addNeighbor("1", "2","N");
			myGraph->addNeighbor("1", "3","E");
			myGraph->addNeighbor("1", "4","W");
			myGraph->addNeighbor("2", "4","S");
			myGraph->addNeighbor("3", "4","W");

			p->setLocation(myGraph->adjlist[0]);
			if ((p->currentLocation(), myGraph->adjlist[0]))
			{
				Assert::IsTrue(true);
			}
			else
			{
				Assert::IsFalse(false);
			}

			move->ChangeLocation(p, "n");

			if ((p->currentLocation(), myGraph->adjlist[1]))
			{
				Assert::IsTrue(true);
			}
			else
			{
				Assert::IsFalse(false);
			}
		}

		TEST_METHOD(TestLookCommand)
		{
			Player* p = new Player();
			Graph* myGraph = new Graph();
			LookCommand* look = new LookCommand("look");

			myGraph->addNode(new MapNode("1", "a cool map"));
			myGraph->addNode(new MapNode("2", "a warm map"));
			myGraph->addNode(new MapNode("3", "a cold map"));
			myGraph->addNode(new MapNode("4", "a hot map"));

			myGraph->addNeighbor("1", "2", "N");
			myGraph->addNeighbor("1", "3", "E");
			myGraph->addNeighbor("1", "4", "W");
			myGraph->addNeighbor("2", "4", "S");
			myGraph->addNeighbor("3", "4", "W");

			p->setLocation(myGraph->adjlist[0]);

			Assert::AreEqual(p->FullDesc(), look->Execute(p, std::vector<std::string>{"look", "at", "me"}));
		}

		TEST_METHOD(TestGrabCommand)
		{
			Player* p = new Player();
			Graph* myGraph = new Graph();
			GrabCommand* grab = new GrabCommand("grab");
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

			p->setLocation(myGraph->adjlist[0]);
			p->currentLocation()->mapItems->Put(gun);

			Assert::IsTrue(!p->inv->HasItem("gun"));
			grab->Execute(p, std::vector<std::string>{"take", "gun"});
			Assert::IsTrue(p->inv->HasItem("gun"));
			Assert::IsTrue(!p->currentLocation()->mapItems->HasItem("gun"));
		}

		TEST_METHOD(TestPutCommand)
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
			put->Execute(p, std::vector<std::string>{"put", "gun"});
			Assert::IsTrue(!p->inv->HasItem("gun"));
			Assert::IsTrue(p->currentLocation()->mapItems->HasItem("gun"));
		}
	};
}