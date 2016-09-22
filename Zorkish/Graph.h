#pragma once
#include "stdafx.h"
#include "MapNode.h"
#include "Player.h"

class Graph
{
public:
	Graph();
	~Graph();

	std::vector<MapNode*> adjlist;

	void printGraph();
	void addNode(MapNode* aNode);
	void addNeighbor(MapNode& aNode1, MapNode& aNode2);
private:
	
};