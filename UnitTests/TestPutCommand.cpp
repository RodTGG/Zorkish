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

			p->getInventory()->Put(gun);
			p->setLocation(myGraph->adjlist[0]);

			Assert::IsTrue(p->getInventory()->HasItem("gun"));
			Assert::IsTrue(p->getLocation()->fInventory->HasItem("bag"));
			put->Execute(p, std::vector<std::string>{"put", "gun", "in", "bag"});
			Assert::IsTrue(p->getLocation()->fInventory->getContainer("bag")->HasItem("gun"));
		}

		/*	Tests if player can add items to containers in their inventory.
		Adds gun to player, Checks if player has item.
		Takes bag from mapnode, Checks if player has bag.
		Puts gun in bag, Checks if player dosnt have item and bag does.
		*/
		TEST_METHOD(TestPutinInvContainer)
		{
			Player* p = new Player();
			Graph* myGraph = new Graph();
			PutCommand* put = new PutCommand("put");
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

			p->getInventory()->Put(gun);
			p->setLocation(myGraph->adjlist[0]);

			Assert::IsTrue(p->getInventory()->HasItem("gun"));
			Assert::IsTrue(p->getLocation()->fInventory->HasItem("bag"));
			grab->Execute(p, std::vector<std::string>{ "grab", "bag" });
			Assert::IsFalse(p->getLocation()->fInventory->HasItem("bag"));
			Assert::IsTrue(p->getInventory()->HasItem("bag"));

			put->Execute(p, std::vector<std::string>{ "put", "gun", "in", "bag" });
			Assert::IsTrue(p->getInventory()->getContainer("bag")->HasItem("gun"));
			Assert::IsFalse(p->getInventory()->HasItem("gun"));
		}

		/* Tests that player cant put items in items that arent containers.
		Adds gun to player, asserts if player has gun.
		Checks if mapnode has bag item.
		Player grabs bag, checks if player has bag and mapnode dosnt.
		Executes put bag in gun, checks container dosnt contain gun and that player still has gun.
		*/
		TEST_METHOD(TestPutinNonContainer)
		{
			Player* p = new Player();
			Graph* myGraph = new Graph();
			PutCommand* put = new PutCommand("put");
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

			p->getInventory()->Put(gun);
			p->setLocation(myGraph->adjlist[0]);

			Assert::IsTrue(p->getInventory()->HasItem("gun"));
			Assert::IsTrue(p->getLocation()->fInventory->HasItem("bag"));
			grab->Execute(p, std::vector<std::string>{ "grab", "bag" });
			Assert::IsFalse(p->getLocation()->fInventory->HasItem("bag"));
			Assert::IsTrue(p->getInventory()->HasItem("bag"));

			put->Execute(p, std::vector<std::string>{ "put", "bag", "in", "gun" });
			Assert::IsFalse(p->getInventory()->getContainer("bag")->HasItem("gun"));
			Assert::IsTrue(p->getInventory()->HasItem("gun"));
		}
	};
}