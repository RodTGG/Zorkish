#pragma once
#include "stdafx.h"
#include "Vertices.h"
#include "MapNode.h"
#include "Player.h"

class Graph
{
public:
	Graph();
	~Graph();

	void addMapNode(MapNode* aMapNode);
	void addVertices(Vertices* aVertice);
	void connectNode(MapNode* node1, MapNode* node2, Vertices* aVertice);

	MapNode* currentNode = NULL;

	MapNode* graphNode(MapNode* aNode);
	MapNode* Traverse(Vertices* aVert, char d);
private:
	std::vector<MapNode*> fgraphNodes;				// vector of mapnodes
	std::vector<Vertices*> fgraphVertices;			// vector of vertices
};