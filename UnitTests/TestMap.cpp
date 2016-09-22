#include "stdafx.h"
#include "CppUnitTest.h"
#include "..\Zorkish\Player.h"
#include "..\Zorkish\Graph.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestMap
{
	TEST_CLASS(TestMap)
	{
	public:

		TEST_METHOD(TestMapNodeInventory)
		{
			Item* gun = new Item("9mm", "a 9mm weapon", new std::string[2]{ "gun", "pistol" });
			Item* gun2 = new Item("9mm", "a 9mm weapon", new std::string[2]{ "gun2", "pistol" });
			Item* gun3 = new Item("9mm", "a 9mm weapon", new std::string[2]{ "gun3", "pistol" });
			Item* i[] = { gun,gun2,gun3 };

			MapNode* myMap1 = new MapNode("1","A very scary node", i);

			Assert::IsTrue(myMap1->mapItems->HasItem("gun"));
			Assert::IsTrue(myMap1->mapItems->HasItem("gun2"));
			Assert::IsTrue(myMap1->mapItems->HasItem("gun3"));
		}

		TEST_METHOD(TestMapRooms)
		{

			Player* p = new Player();
			Graph* myGraph = new Graph();

			myGraph->addNode(new MapNode("1", "a cool map"));
			myGraph->addNode(new MapNode("2", "a warm map"));
			myGraph->addNode(new MapNode("3", "a cold map"));
			myGraph->addNode(new MapNode("4", "a hot map"));

			myGraph->addNeighbor("1", "2");
			myGraph->addNeighbor("1", "3");
			myGraph->addNeighbor("1", "4");
			myGraph->addNeighbor("2", "4");
			myGraph->addNeighbor("3", "4");

			p->setLocation(myGraph->adjlist[0]);
			if ((p->currentLocation(), myGraph->adjlist[0]))
			{
				Assert::IsTrue(true);
			}
			else 
			{
				Assert::IsFalse(false);
			}
			p->go("2");
			if ((p->currentLocation(), myGraph->adjlist[1]))
			{
				Assert::IsTrue(true);
			}
			else
			{
				Assert::IsFalse(false);
			}

		}
	};
}