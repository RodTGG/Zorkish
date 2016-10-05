#include "stdafx.h"
#include "Graph.h"

Graph::Graph(bool aDebugging)
{
	fDebugging = aDebugging;
}

Graph::Graph()
{
}

Graph::~Graph()
{
}

void Graph::Tokenizer(const std::string& str, std::vector<std::string>& fTokens, const std::string& delimiters)
{
	// Skip delimiters at beginning.
	std::string::size_type lastPos = str.find_first_not_of(delimiters, 0);
	// Find first "non-delimiter".
	std::string::size_type pos = str.find_first_of(delimiters, lastPos);

	while (std::string::npos != pos || std::string::npos != lastPos)
	{
		// Found a token, add it to the vector.
		fTokens.push_back(str.substr(lastPos, pos - lastPos));
		// Skip delimiters.  Note the "not_of"
		lastPos = str.find_first_not_of(delimiters, pos);
		// Find next "non-delimiter"
		pos = str.find_first_of(delimiters, lastPos);
	}
}

/// <summary>
/// Adds the node to adjency list.
/// </summary>
/// <param name="aNode">A MapNode.</param>
void Graph::addNode(MapNode* aNode)
{
	adjlist.push_back(aNode);
}

/// <summary>
/// Adds the neighbor.
/// </summary>
/// <param name="aNode1">name of node1.</param>
/// <param name="aNode2">name of node2.</param>
void Graph::addNeighbor(std::string aNode1, std::string aNode2, std::string aDirection)
{
	MapNode* a = NULL;
	MapNode* b = NULL;

	int direction = getDirection(aDirection);

	// Copy nodes to temp nodes
	a = getNode(aNode1);
	b = getNode(aNode2);

	// Check if nodes arent neighbors
	if (!a->hasNeighbor(b) && !b->hasNeighbor(a))
	{
		a->fNeighbor.at(direction) = b;

		// Place node in opposite direction of node a
		switch (direction)
		{
		case 0:
			b->fNeighbor.at(2) = a;
			break;
		case 1:
			b->fNeighbor.at(3) = a;
			break;
		case 2:
			b->fNeighbor.at(0) = a;
			break;
		case 3:
			b->fNeighbor.at(1) = a;
		default:
			b->fNeighbor.at(1) = a;
			break;
		}
	}

	// Override node data
	setNode(a);
	setNode(b);
}

int Graph::getDirection(std::string aDirection)
{
	int result = -1;
	char* direction[4]{ "N", "E","S","W" };

	for (unsigned int i = 0; i < 4; i++)
	{
		if (direction[i] == aDirection)
		{
			result = i;
		}
	}

	if (result == -1)
	{
		Error::Display("Error in Graph, getDirection unable to convert direction: " + aDirection);
	}

	return result;
}

Damage* Graph::getDamage(std::string aDamage)
{
	Damage* result = new Damage();
	std::vector<std::string> temp;
	Tokenizer(aDamage, temp, " ");

	if (temp.size() < 4)
	{
		Error::Display("Error in file, damage didnt match arguments");
	}
	else
	{
		int lValues[4] = { std::stoi(temp[0]), std::stoi(temp[1]), std::stoi(temp[2]), std::stoi(temp[3]) };
		result = new Damage(lValues);
	}

	return result;
}

Resistance* Graph::getResistance(std::string aResistance)
{
	Resistance* result = new Resistance();
	std::vector<std::string> temp;
	Tokenizer(aResistance, temp, " ");

	if (temp.size() < 4)
	{
		Error::Display("Error in file, damage didnt match arguments");
	}
	else
	{
		int lValues[4] = { std::stoi(temp[0]), std::stoi(temp[1]), std::stoi(temp[2]), std::stoi(temp[3]) };
		result = new Resistance(lValues);
	}

	return result;
}

/// <summary>
/// Prints the graph.
///	Prints nodes neighbours.
/// </summary>
void Graph::printGraph()
{
	for (unsigned int i = 0; i < adjlist.size(); i++)
	{
		std::cout << adjlist[i]->fName + "--->";

		for (unsigned int j = 0; j < adjlist[i]->fNeighbor.size(); j++)
		{
			if (adjlist[i]->fNeighbor[j] != NULL) std::cout << adjlist[i]->fNeighbor[j]->fName;
		}

		std::cout << "\n";
	}
}

/// <summary>
/// Reads the file from specified file.
/// </summary>
/// <param name="aFile">file to read from.</param>
void Graph::readFile(std::string aFile)
{
	std::string line = "";
	std::ifstream istream(aFile);

	if (istream.is_open())
	{
		if (fDebugging) {
			std::cout << "MapOpened" << std::endl;
		}
		while (!istream.eof())
		{
			char preview;
			preview = istream.peek();
			std::getline(istream, line);

			if (preview == '#' || preview == '\n')
			{
				continue;
			}
			else
			{
				if (preview == '[')
				{
					Tokenizer(line, fTokens);
					if (fTokens[0] == "[Nodes]")
					{
						if (fDebugging) {
							std::cout << "Reading nodes" << std::endl;
						}
						fTokens.clear();
						while (!istream.eof())
						{
							std::getline(istream, line);
							Tokenizer(line, fTokens);

							if (line != "")
							{
								addNode(new MapNode(fTokens[0], fTokens[1]));
								if (fDebugging) {
									std::cout << "Added node" << std::endl;
								}
								fTokens.clear();
							}
							else
							{
								break;
							}
						}
					}
					else if (line != "" && fTokens[0] == "[Connections]")
					{
						while (!istream.eof()) {
							fTokens.clear();
							std::getline(istream, line);
							Tokenizer(line, fTokens);

							if (line != "")
							{
								addNeighbor(fTokens[0], fTokens[1], fTokens[2]);
								if (fDebugging) {
									std::cout << "Added neighbor" << std::endl;
								}
							}
							else
							{
								break;
							}
						}
					}
					else if (line != "" && fTokens[0] == "[Items]")
					{
						while (!istream.eof()) {
							fTokens.clear();
							std::getline(istream, line);
							Tokenizer(line, fTokens);

							if (line != "" && fTokens.size() == 7)
							{
								if (fTokens[1] == "i") 
								{
									//Item* myItem = new Item();
								}
								else if (fTokens[1] == "c")
								{
								
								}
								else 
								{
									Error::Display("Error reading from adventure filre, prefix wasnt i or c");
								}
							}
							else if (line != "" && fTokens.size() == 8)
							{
								true;
							}
							else
							{
								break;
							}
						}
					}
				}
			}
		}

	}
	else
	{
		Error::Display("Unable to open file: " + aFile + "\nMake sure the file exists.");
	}
}

MapNode* Graph::getNode(std::string aName)
{
	MapNode* result = NULL;

	for (unsigned int i = 0; i < adjlist.size(); i++)
	{
		if (adjlist[i]->fName == aName) 
		{
			result = adjlist[i];
			break;
		}
	}

	return result;
}

void Graph::setNode(MapNode* aNode)
{
	for (unsigned int i = 0; i < adjlist.size(); i++)
	{
		if (adjlist[i]->fName == aNode->fName)
		{
			adjlist[i] = aNode;
			break;
		}
	}
}

std::string Graph::fileName()
{
	return fName;
}