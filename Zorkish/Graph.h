#pragma once
#include "stdafx.h"
#include "MapNode.h"

class Graph
{
public:
	Graph();
	~Graph();

	std::vector<MapNode*> adjlist;
	std::vector<std::string> fTokens;


	
	void readFile(std::string aFile);
	void printGraph();
	void addNode(MapNode* aNode);
	void addNeighbor(std::string aNode1, std::string aNode2, std::string aDirection);
	int getDirection(std::string aDirection);
private:
	void Tokenizer(const std::string& str, std::vector<std::string>& fTokens, const std::string& delimiters = ",");
};