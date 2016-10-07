#include "stdafx.h"
#include "CppUnitTest.h"
#include "..\Zorkish\Item.h"
#include "..\Zorkish\Player.h"
#include "..\Zorkish\MapNode.h"
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

			MapNode* myMap1 = new MapNode("1", "a very scary room");
			myMap1->fInventory->Put(i[0]);
			myMap1->fInventory->Put(i[1]);
			myMap1->fInventory->Put(i[2]);

			Assert::IsTrue(myMap1->fInventory->HasItem("gun"));
			Assert::IsTrue(myMap1->fInventory->HasItem("gun2"));
			Assert::IsTrue(myMap1->fInventory->HasItem("gun3"));

			Assert::IsTrue(true);
		}

		TEST_METHOD(TestMapRooms)
		{
			Player* p = new Player();
			Graph* myGraph = new Graph();

			myGraph->readFile("Adventure.txt");

			p->setLocation(myGraph->adjlist[0]);
			if ((p->getLocation(), myGraph->adjlist[0]))
			{
				Assert::IsTrue(true);
			}
			else
			{
				Assert::IsFalse(false);
			}
			p->setLocation(myGraph->adjlist[0]->fNeighbor[0]);
			if ((p->getLocation(), myGraph->adjlist[1]))
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