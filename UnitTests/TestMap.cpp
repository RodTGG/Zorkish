#include "stdafx.h"
#include "CppUnitTest.h"
#include "..\Zorkish\Player.h"
#include "..\Zorkish\Item.h"
#include "..\Zorkish\MapNode.h"
#include "..\Zorkish\Graph.h"
#include "..\Zorkish\Vertices.cpp"

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

			MapNode* myMap1 = new MapNode("A very scary node", i);

			Assert::IsTrue(myMap1->mapItems->HasItem("gun"));
			Assert::IsTrue(myMap1->mapItems->HasItem("gun2"));
			Assert::IsTrue(myMap1->mapItems->HasItem("gun3"));
		}

		TEST_METHOD(TestMapRooms)
		{

			Player* p = new Player();
			Graph* mgraph = new Graph();

			MapNode* myMap1 = new MapNode("A very scary node");
			MapNode* myMap2 = new MapNode("A very happy node");
			MapNode* myMap3 = new MapNode("A very kawaii node");
			Vertices* myvert = new Vertices();
			
			mgraph->addMapNode(myMap1);
			mgraph->addMapNode(myMap2);
			mgraph->addMapNode(myMap3);
			mgraph->addVertices(myvert);
			mgraph->connectNode(myMap1, myMap2, myvert);
			
			p->setLocation(mgraph->graphNode(myMap1));

			if (p->currentLocation() == myMap1) 
			{
				Assert::IsTrue(true);
			}
			else
			{
				Assert::IsTrue(false);
			}

			p->setLocation(mgraph->Traverse(mgraph->));

			if (p->currentLocation() == myMap2)
			{
				Assert::IsTrue(true);
			}
			else
			{
				Assert::IsTrue(false);
			}
		}
	};
}