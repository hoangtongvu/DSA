#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;


class Vertex
{
public:
	int value;
	Vertex();
	~Vertex();

private:

};

Vertex::Vertex()
{
}

Vertex::~Vertex()
{
}


class Edge
{
public:
	vector<Vertex*> vertexes;
	Edge(Vertex* v1, Vertex* v2);
	~Edge();
	bool Equals(Edge* other);

private:

};

Edge::Edge(Vertex* v1, Vertex* v2)
{
	this->vertexes.emplace_back(v1);
	this->vertexes.emplace_back(v2);
}

Edge::~Edge()
{
}

bool Edge::Equals(Edge* other)
{
	if (this->vertexes[0]->value == other->vertexes[0]->value)
	{
		if (this->vertexes[1]->value == other->vertexes[1]->value)
		{
			return true;
		}
	}
	
	if (this->vertexes[0]->value == other->vertexes[1]->value)
	{
		if (this->vertexes[1]->value == other->vertexes[0]->value)
		{
			return true;
		}
	}

	return false;
}

class Graph
{
public:
	vector<Vertex*> vertexes;
	vector<Edge*> edges;
	Graph();
	~Graph();

private:

};

Graph::Graph()
{
}

Graph::~Graph()
{
}


int main()
{
	Graph* graph = new Graph();
	for (int i = 0; i < 5; i++)
	{
		Vertex* vertex = new Vertex();
		vertex->value = i;
		graph->vertexes.emplace_back(vertex);
	}

	Edge* edge1 = new Edge(graph->vertexes[0], graph->vertexes[1]);
	Edge* edge2 = new Edge(graph->vertexes[1], graph->vertexes[0]);
	Edge* edge3 = new Edge(graph->vertexes[1], graph->vertexes[3]);
	Edge* edge4 = new Edge(graph->vertexes[1], graph->vertexes[2]);
	Edge* edge5 = new Edge(graph->vertexes[2], graph->vertexes[1]);

	graph->edges.emplace_back(edge1);
	graph->edges.emplace_back(edge2);
	graph->edges.emplace_back(edge3);
	graph->edges.emplace_back(edge4);
	graph->edges.emplace_back(edge5);

	int count = 0;
	int size = graph->edges.size();
	for (int i = 0; i < size; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (graph->edges[i]->Equals(graph->edges[j]))
			{
				cout << graph->edges[i]->vertexes[0]->value << " ";
				cout << graph->edges[i]->vertexes[1]->value << endl;
				count++;
				break;
			}
		}
	}

	cout << "number of parallel edges = " << count;

	delete graph;
    return 0;
}
