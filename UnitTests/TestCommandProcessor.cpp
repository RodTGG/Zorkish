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
	/*	Tests different aspects of the command processor	*/
	TEST_CLASS(TestCommandProcessor)
	{
	public:

		/* Test the move command.
		Asserts if the current location is equal to the graphs location of then node.
		*/
		TEST_METHOD(TestMoveCommand)
		{
			Player* p = new Player();
			Graph* myGraph = new Graph();
			MoveCommand* move = new MoveCommand("go");

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

			move->ChangeLocation(p, "n");

			if ((p->getLocation(), myGraph->adjlist[1]))
			{
				Assert::IsTrue(true);
			}
			else
			{
				Assert::IsFalse(false);
			}
		}

		/* Asserts if the look command works.
		Asserts if the invetory description is equal to the look commands execution.
		*/
		TEST_METHOD(TestLookCommand)
		{
			Player* p = new Player();
			Graph* myGraph = new Graph();
			LookCommand* look = new LookCommand("look");

			myGraph->readFile("Adventure.txt");

			p->setLocation(myGraph->adjlist[0]);

			Assert::AreEqual(p->getFullDesc(), look->Execute(p, std::vector<std::string>{"look", "at", "me"}));
		}

		/* Tests the grab command.
		Asserts if player can grab items that are laying on the floor/inventory of the mapnode.
		*/
		TEST_METHOD(TestGrabCommand)
		{
			Player* p = new Player();
			Graph* myGraph = new Graph();
			GrabCommand* grab = new GrabCommand("grab");
			Item* gun = new Item("9mm", "a 9mm weapon", new std::string[2]{ "gun", "pistol" });

			myGraph->readFile("Adventure.txt");

			p->setLocation(myGraph->adjlist[0]);
			p->getLocation()->fInventory->Put(gun);

			Assert::IsTrue(!p->getInventory()->HasItem("gun"));
			grab->Execute(p, std::vector<std::string>{"take", "gun"});
			Assert::IsTrue(p->getInventory()->HasItem("gun"));
			Assert::IsTrue(!p->getLocation()->fInventory->HasItem("gun"));
		}

		/* Tests the put command
		Asserts if player can drop/put items in the mapnodes inventory.
		*/
		TEST_METHOD(TestPutCommand)
		{
			Player* p = new Player();
			Graph* myGraph = new Graph();
			PutCommand* put = new PutCommand("put");
			Item* gun = new Item("9mm", "a 9mm weapon", new std::string[2]{ "gun", "pistol" });

			myGraph->readFile("Adventure.txt");

			p->getInventory()->Put(gun);
			p->setLocation(myGraph->adjlist[0]);

			Assert::IsTrue(p->getInventory()->HasItem("gun"));
			put->Execute(p, std::vector<std::string>{"put", "gun"});
			Assert::IsTrue(!p->getInventory()->HasItem("gun"));
			Assert::IsTrue(p->getLocation()->fInventory->HasItem("gun"));
		}
	};
}