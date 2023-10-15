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
	int GetConnectedComponents();
	void DFS(Node* node, vector<Node*> &visitedNodes);

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

int Network::GetConnectedComponents()
{
	vector<Node*> visitedNodes;
	
	int count = 0;

	int length = this->nodes.size();
	for (int i = 0; i < length; i++)
	{
		//check travelsal status, if traveled -> do nothing, if not count++ and travel.
		int numOfVisitedNode = visitedNodes.size();
		bool traveled = false;
		for (int j = 0; j < numOfVisitedNode; j++)
		{
			if (visitedNodes[i] == this->nodes[j]) traveled = true;
		}

		if (traveled) continue;

		count++;
		this->DFS(this->nodes[i], visitedNodes);
		
	}

	return count;
}

void Network::DFS(Node* node, vector<Node*>& visitedNodes)
{
	
	//check if node lay in visitedNodes.
	int length = visitedNodes.size();
	for (int i = 0; i < length; i++)
	{
		if (visitedNodes[i] == node) return;
	}


	//visit node.
	visitedNodes.emplace_back(node);


	//visit neighborNodes.
	int numOfNeighborNodes = node->neighborNodes.size();
	for (int i = 0; i < numOfNeighborNodes; i++)
	{
		this->DFS(node->neighborNodes[i], visitedNodes);
	}


	return;
}



int main()
{
	int numberOfNodes, numberOfEdges;
	cin >> numberOfNodes >> numberOfEdges;

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

	cout << net->GetConnectedComponents();



	delete net;
    return 0;
}



