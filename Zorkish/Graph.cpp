#include "stdafx.h"
#include "Graph.h"

Graph::Graph()
{
}

Graph::~Graph()
{
}

void Graph::addNode(MapNode* aNode)
{
	adjlist.push_back(aNode);
}

void Graph::addNeighbor(MapNode& aNode1, MapNode& aNode2)
{
	MapNode* a = NULL;
	MapNode* b = NULL;

	// Copy nodes to temp nodes
	for (unsigned int i = 0; i < adjlist.size(); i++)
	{
		if (adjlist[i]->fname == aNode1.fname)
		{
			a = adjlist[i];
		}
		if (adjlist[i]->fname == aNode2.fname)
		{
			b = adjlist[i];
		}
	}

	// Check if nodes arent neighbors
	if (!a->hasNeighbor(b) && !b->hasNeighbor(a)) 
	{
		a->fneighbor.push_back(b);
		b->fneighbor.push_back(a);
	}

	// Override node data
	for (unsigned int i = 0; i < adjlist.size(); i++)
	{
		if (adjlist[i]->fname == aNode1.fname)
		{
			adjlist[i] = a;
		}
		if (adjlist[i]->fname == aNode2.fname)
		{
			adjlist[i] = b;
		}
	}
}

void Graph::printGraph() 
{
	for (unsigned int i = 0; i < adjlist.size(); i++) 
	{
		std::cout << adjlist[i]->fname + "--->";

		for (unsigned int j = 0; j < adjlist[i]->fneighbor.size(); j++) 
		{
			std::cout << adjlist[i]->fneighbor[j]->fname;
		}

		std::cout << "\n";
	}
}