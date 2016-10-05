#pragma once
#include "stdafx.h"
#include "MapNode.h"

class Graph
{
public:
	Graph();
	Graph(bool aDebugging);
	~Graph();

	std::vector<MapNode*> adjlist;
	std::vector<std::string> fTokens;

	void readFile(std::string aFile);
	void printGraph();
	void addNode(MapNode* aNode);
	void addNeighbor(std::string aNode1, std::string aNode2, std::string aDirection);
	MapNode* getNode(std::string aName);
	void setNode(MapNode* aNode);
	int getDirection(std::string aDirection);

	Damage* getDamage(std::string aDamage);
	Resistance* getResistance(std::string aResistance);
	std::string fileName();
private:
	std::string fName = "";
	bool fDebugging = false;
	void Tokenizer(const std::string& str, std::vector<std::string>& fTokens, const std::string& delimiters = ",");
};