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


	void Tokenizer(const std::string& str, std::vector<std::string>& tokens, const std::string& delimiters = ",");
	void readFile(std::string aFile);
	void printGraph();
	void addNode(MapNode* aNode);
	void addNeighbor(std::string aNode1, std::string aNode2);
private:
	
};