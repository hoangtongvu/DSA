#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;


class Node
{
public:
	int value;
	int label;
	vector<Node*> neighborNodes;
	Node();
	~Node();
	Node(int value);

private:

};

Node::Node()
{
}
Node::~Node()
{
}

Node::Node(int _value)
{
	value = _value;
}



class Network
{
public:
	vector<Node*> nodes;
	Network(int numOfNodes);
	~Network();

	Node* GetNodeWithValue(int value);

	int GetShortestPath(int start, int destination);
	void Dijkstra(int source);
	bool VisitedNodesContainNode(vector<Node*> &visitedNodes, int value);
	bool VisitedNodesContainAllNodes(vector<Node*> &visitedNodes);
	Node* NodeWithMinLabelAndNotVisited(vector<Node*> &visitedNodes);

private:

};

Network::Network(int numOfNodes)
{
	for (int i = 0; i < numOfNodes; i++)
	{
		Node* newNode = new Node();
		newNode->value = i + 1;
		this->nodes.emplace_back(newNode);
	}
}

Network::~Network()
{
}

Node* Network::GetNodeWithValue(int value)
{
	return this->nodes[value - 1];
}

int Network::GetShortestPath(int start, int destination)
{
	this->Dijkstra(start);
	return this->GetNodeWithValue(destination)->label;
}

void Network::Dijkstra(int source)
{

	vector<Node*> visitedNodes;
	Node* startNode = this->GetNodeWithValue(source);

	//set start node's label = 0
	startNode->label = 0;
	visitedNodes.emplace_back(startNode);


	//Set all other nodes' labels = -1 (infinity).
	int numOfNodes = this->nodes.size();
	for (int i = 0; i < numOfNodes; i++)
	{
		if (this->nodes[i] == startNode) continue;
		this->nodes[i]->label = -1;
	}


	//update label for startNode's NeighborNodes.
	int numOfNeighbors = startNode->neighborNodes.size();
	for (int i = 0; i < numOfNeighbors; i++)
	{
		startNode->neighborNodes[i]->label = 1;
	}


	while (!this->VisitedNodesContainAllNodes(visitedNodes))
	{
		//assign currentNode = minLabelNode.
		Node* currentNode = this->NodeWithMinLabelAndNotVisited(visitedNodes);
		
		//mark currentNode visited.
		visitedNodes.emplace_back(currentNode);

		//update label for neighborNodes which haven't visited.
		int num = currentNode->neighborNodes.size();
		for (int i = 0; i < num; i++)
		{
			Node* tempNode = currentNode->neighborNodes[i];
			if (this->VisitedNodesContainNode(visitedNodes, tempNode->value)) continue;

			tempNode->label = currentNode->label + 1;
		}

	}
	//end until all nodes lay inside visitedNodes.
}

bool Network::VisitedNodesContainNode(vector<Node*> &visitedNodes, int value)
{
	int numOfVisitedNodes = visitedNodes.size();

	for (int j = 0; j < numOfVisitedNodes; j++)
	{
		if (visitedNodes[j]->value == value)
		{
			return true;
		}
	}

	return false;
}

bool Network::VisitedNodesContainAllNodes(vector<Node*> &visitedNodes)
{
	int numOfNodes = this->nodes.size();
	int numOfVisitedNodes = visitedNodes.size();

	if (numOfVisitedNodes < numOfNodes) return false;//faster way :V.


	/*bool check = false;
	for (int i = 0; i < numOfNodes; i++)
	{
		for (int j = 0; j < numOfVisitedNodes; j++)
		{
			if (this->nodes[i] == visitedNodes[j])
			{
				check = true;
			}
		}
	}*/


	return true;
}

Node* Network::NodeWithMinLabelAndNotVisited(vector<Node*> &visitedNodes)
{
	int numOfNodes = this->nodes.size();
	int numOfVisitedNodes = visitedNodes.size();

	int minLabel = 99999;
	Node* nodeWithMinLabel = NULL;

	for (int i = 0; i < numOfNodes; i++)
	{
		Node* node = this->nodes[i];

		if (this->VisitedNodesContainNode(visitedNodes, node->value)) continue;
		if (node->label == -1) continue;

		if (minLabel >= node->label) 
		{
			minLabel = node->label;
			nodeWithMinLabel = node;
		}
	}

	

	return nodeWithMinLabel;
}




int main()
{
	int numberOfNodes, numberOfEdges, startValue, destinatedValue;
	cin >> numberOfNodes >> numberOfEdges >> startValue >> destinatedValue;

	Network* net = new Network(numberOfNodes);

	for (int i = 0; i < numberOfEdges; i++)
	{
		int value1, value2;
		cin >> value1 >> value2;
		Node* node1 = net->GetNodeWithValue(value1);
		Node* node2 = net->GetNodeWithValue(value2);

		node1->neighborNodes.emplace_back(node2);
		node2->neighborNodes.emplace_back(node1);
	}

	cout << net->GetShortestPath(startValue, destinatedValue);


	delete net;
    return 0;
}


/*
5 5 1 5
1 2
2 3
3 4
4 5
2 5
*/

/*
5 5 1 1
1 2
2 3
3 4
4 5
2 5
*/
