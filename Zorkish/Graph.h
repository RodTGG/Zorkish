#pragma once
#include "stdafx.h"
#include "MapNode.h"

/// <summary>
/// Graph base class
/// Manages map nodes to create a graph as a map
/// Uses replaces
/// </summary>
/// <seealso cref="Graph" />
class Graph
{
public:
	/// <summary>
	/// Initializes a new instance of the <see cref="Graph"/> class.
	/// </summary>
	Graph();

	/// <summary>
	/// Initializes a new instance of the <see cref="Graph"/> class.
	/// </summary>
	/// <param name="aDebugging">if set to <c>true</c> [debugging].</param>
	Graph(bool aDebugging);

	/// <summary>
	/// Finalizes an instance of the <see cref="Graph"/> class.
	/// </summary>
	~Graph();

	/// <summary>
	/// The adjacency list
	/// </summary>
	std::vector<MapNode*> adjlist;

	/// <summary>
	/// File string tokens
	/// </summary>
	std::vector<std::string> fTokens;

	/// <summary>
	/// Reads the specified file.
	/// </summary>
	/// <param name="aFile">file to read from.</param>
	void readFile(std::string aFile);


	/// <summary>
	/// Prints adjacency list with child nodes
	/// </summary>
	void printGraph();

	/// <summary>
	/// Adds the node to adjency list.
	/// </summary>
	/// <param name="aNode">A MapNode.</param>
	void addNode(MapNode* aNode);

	/// <summary>
	/// Adds a neighbor to adjacency list node
	/// </summary>
	/// <param name="aNode1">name of node1.</param>
	/// <param name="aNode2">name of node2.</param>
	/// <param name="aDirection">a direction in relation to node1.</param>
	void addNeighbor(std::string aNode1, std::string aNode2, std::string aDirection);

	/// <summary>
	/// Determines whether the adjacency list contains a node.
	/// </summary>
	/// <param name="aName">a name.</param>
	/// <returns>
	///   <c>true</c> if the specified node exists; otherwise, <c>false</c>.
	/// </returns>
	bool hasNode(std::string aName);
	
	/// <summary>
	/// Gets pointer to specific node.
	/// </summary>
	/// <param name="aName">a name.</param>
	/// <returns>Pointer to node if exists</returns>
	MapNode* getNode(std::string aName);
	
	/// <summary>
	/// Updates adjacency list.
	/// </summary>
	/// <param name="aNode">a node.</param>
	void setNode(MapNode* aNode);
	
	/// <summary>
	/// Gets and sets direction for map node based on text file entry.
	/// </summary>
	/// <param name="aDirection">a direction.</param>
	/// <returns>Int based on direction</returns>
	int getDirection(std::string aDirection);
	
	/// <summary>
	/// Gets and sets the damage for map node based on text file entry.
	/// </summary>
	/// <param name="aDamage">a damage.</param>
	/// <returns>Damage pointer based on string</returns>
	Damage* getDamage(std::string aDamage);
	
	/// <summary>
	/// Gets and sets the resistance.
	/// </summary>
	/// <param name="aResistance">a resistance.</param>
	/// <returns>Resistance pointer based on string</returns>
	Resistance* getResistance(std::string aResistance);
	
private:	
	/// <summary>
	/// Debugging boolean
	/// </summary>
	bool fDebugging = false;
	
	/// <summary>
	/// Tokenizers the specified string.
	/// </summary>
	/// <param name="str">The string.</param>
	/// <param name="fTokens">The tokens vector.</param>
	/// <param name="delimiters">The delimiters.</param>
	void Tokenizer(const std::string& str, std::vector<std::string>& fTokens, const std::string& delimiters = ",");
};