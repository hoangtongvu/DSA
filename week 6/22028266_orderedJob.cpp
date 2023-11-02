#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

struct Node
{
    int value;
    vector<Node*> fromNodes;
    vector<Node*> toNodes;
};


class Graph
{
public:
    vector<Node*> nodes;
	Graph();
	~Graph();
    Node* GetNodeWithValue(int i);
    void PrintOrderedJob();

private:

};

Graph::Graph()
{
}

Graph::~Graph()
{
}

Node* Graph::GetNodeWithValue(int i)
{
    return this->nodes[i - 1];
}

void Graph::PrintOrderedJob()
{
    
    //find node with no fromNode.
    while (!this->nodes.empty())
    {
        for (int i = 0; i < this->nodes.size(); i++)
        {
            if (!this->nodes[i]->fromNodes.empty()) continue;
            
            vector<Node*> toNodes = this->nodes[i]->toNodes;
            for (int j = 0; j < toNodes.size(); j++)
            {
                vector<Node*> fromNodes = toNodes[j]->fromNodes;


                //cut connection between nodes[i] and its toNode.
                
                for (int k = 0; k < fromNodes.size(); k++)
                {
                    if (this->nodes[i]->value == fromNodes[k]->value)
                    {
                        toNodes[j]->fromNodes.erase(toNodes[j]->fromNodes.begin() + k);
                        break;
                    }
                }
                


            }


            cout << this->nodes[i]->value << " ";
            //remove from nodes.
            this->nodes.erase(this->nodes.begin() + i);
            i--;

            /*for (int j = 0; j < this->nodes.size(); j++)
                cout << this->nodes[j]->value << " ";
            cout << endl;*/
            

        }



    }


}

int main()
{
    int n, m;
    cin >> n >> m;

    Graph* graph = new Graph();
    for (int i = 0; i < n; i++)
    {
        Node* newNode = new Node();
        newNode->value = i + 1;
        graph->nodes.emplace_back(newNode);
    }



    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        Node* p = graph->GetNodeWithValue(u);
        Node* q = graph->GetNodeWithValue(v);
        p->toNodes.emplace_back(q);
        q->fromNodes.emplace_back(p);
    }

    /*Node* p = graph->GetNodeWithValue(3);
    for (int i = 0; i < p->toNodes.size(); i++)
    {
        cout << p->toNodes[i]->value << " ";
    }*/

    graph->PrintOrderedJob();

    delete graph;

    return 0;
}


