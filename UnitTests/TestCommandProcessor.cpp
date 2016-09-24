#include "stdafx.h"
#include "CppUnitTest.h"
#include "..\Zorkish\Player.h"
#include "..\Zorkish\MoveCommand.h"

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
			MoveCommand* move = new MoveCommand();

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
	};
}