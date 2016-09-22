#include "stdafx.h"
#include "Graph.h"

Graph::Graph()
{
}

Graph::~Graph()
{
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
void Graph::addNeighbor(std::string aNode1, std::string aNode2)
{
	MapNode* a = NULL;
	MapNode* b = NULL;

	// Copy nodes to temp nodes
	for (unsigned int i = 0; i < adjlist.size(); i++)
	{
		if (adjlist[i]->fname == aNode1)
		{
			a = adjlist[i];
		}
		if (adjlist[i]->fname == aNode2)
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
		if (adjlist[i]->fname == aNode1)
		{
			adjlist[i] = a;
		}
		if (adjlist[i]->fname == aNode2)
		{
			adjlist[i] = b;
		}
	}
}


/// <summary>
/// Prints the graph.
/// </summary>
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

void Graph::readFile(std::string aFile)
{
	std::string line = "";
	std::ifstream istream(aFile);

	if (istream.is_open())
	{
		std::cout << "MapOpened" << std::endl;

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
						std::cout << "Reading nodes" << std::endl;
						fTokens.clear();
						while (true)
						{
							std::getline(istream, line);
							Tokenizer(line, fTokens);

							if (line != "")
							{
								addNode(new MapNode(fTokens[0], fTokens[1]));
								std::cout << "Added node" << std::endl;
								fTokens.clear();
							}
							else
							{
								break;
							}
						}
					}
					if (line != "" && fTokens[0] == "[Connections]")
					{
						while (true)
						{
							fTokens.clear();
							std::getline(istream, line);
							Tokenizer(line, fTokens);
							if (line != "" && !istream.eof())
							{
								addNeighbor(fTokens[0], fTokens[1]);
								std::cout << "Added neighbor" << std::endl;
								fTokens.clear();
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
}