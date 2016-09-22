#include "stdafx.h"
#include "Graph.h"

Graph::Graph()
{
}

Graph::~Graph()
{
}

void Graph::addMapNode(MapNode* aMapNode)
{
	fgraphNodes.push_back(aMapNode);
}

void Graph::addVertices(Vertices* aVertice)
{
	fgraphVertices.push_back(aVertice);
}

void Graph::connectNode(MapNode* node1, MapNode* node2, Vertices* aVertice)
{
	if (node1->hasNeighbour(node2))
	{
		aVertice->setSrc(node1);
		aVertice->setDest(node2);
	}
}

MapNode* Graph::graphNode(MapNode* aNode) 
{
	for (unsigned int i = 0; i < fgraphNodes.size(); i++) 
	{
		if (fgraphNodes[i] == aNode) 
		{
			return fgraphNodes[i];
		}
		else 
		{
			return NULL;
		}
	}

	return NULL;
}

MapNode* Graph::Traverse(Vertices* aVert, char d)
{
	return aVert->Dest();
}