#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

struct Node
{
public:
    int value;
    vector<Node*> childNodes;

    Node(int _value)
    {
        this->value = _value;
    }
};


class Tree
{
public:
    Node* root;
	Tree();
	~Tree();
    int GetHeightOfTree();
    int GetHeightOfTree(Node* root);
    int MaxHeightOfTrees(vector<Node*> nodes);
    bool IsBinaryTree();
    bool IsBinaryTree(Node* root);
    void Insert(int parentValue, int childValue);
    Node* GetNodeWithValue(int value);
    Node* GetNodeWithValue(Node* root, int value);
    void PreorderTraversal();
    void PreorderTraversal(Node* root);
    void PostorderTraversal();
    void PostorderTraversal(Node* root);
    void InorderTraversal();
    void InorderTraversal(Node* root);
    void CheckBinaryTree();

private:

};

Tree::Tree()
{
    this->root = NULL;
}

Tree::~Tree()
{
}

int Tree::GetHeightOfTree()
{
    return this->GetHeightOfTree(this->root);
}

int Tree::GetHeightOfTree(Node* root)
{
    if (root->childNodes.empty()) return 0;
    int height = 0;

    height += 1 + this->MaxHeightOfTrees(root->childNodes);
    
    return height;
}

int Tree::MaxHeightOfTrees(vector<Node*> nodes)
{
    int size = nodes.size();
    if (size == 0) return 0;
    int maxHeight = this->GetHeightOfTree(nodes[0]);
    for (int i = 1; i < size; i++)
    {
        int temp = this->GetHeightOfTree(nodes[i]);
        if (maxHeight < temp)
        {
            maxHeight = temp;
        }
    }
    return maxHeight;
}

bool Tree::IsBinaryTree()
{
    return this->IsBinaryTree(this->root);
}

bool Tree::IsBinaryTree(Node* root)
{
    int size = root->childNodes.size();
    switch (size)
    {
    case 0:
        return true;
        break;
    case 2:
        for (int i = 0; i < 2; i++)
        {
            bool check = this->IsBinaryTree(root->childNodes[i]);
            if (check == false) return false;
        }
        return true;
        break;
    default:
        return false;
        break;
    }
}

void Tree::Insert(int parentValue, int childValue)
{
    Node* parent = this->GetNodeWithValue(parentValue);
    if (parent == NULL) return;
    Node* newChildNode = new Node(childValue);
    parent->childNodes.emplace_back(newChildNode);

}

Node* Tree::GetNodeWithValue(int value)
{
    Node* p = this->GetNodeWithValue(this->root, value);
    if (p == NULL && this->root == NULL)
    {
        p = new Node(value);
        this->root = p;
    }
    return p;
}

Node* Tree::GetNodeWithValue(Node* root, int value)
{
    if (root == NULL) return NULL;
    if (root->value == value) return root;
    Node* p = NULL;
    int size = root->childNodes.size();
    for (int i = 0; i < size; i++)
    {
        p = this->GetNodeWithValue(root->childNodes[i], value);
        if (p != NULL) break;
    }
    return p;
}

void Tree::PreorderTraversal()
{
    this->PreorderTraversal(this->root);
    cout << endl;
}

void Tree::PreorderTraversal(Node* root)
{
    cout << root->value << " ";

    int size = root->childNodes.size();
    for (int i = 0; i < size; i++)
    {
        this->PreorderTraversal(root->childNodes[i]);
    }
}

void Tree::PostorderTraversal()
{
    this->PostorderTraversal(this->root);
    cout << endl;
}

void Tree::PostorderTraversal(Node* root)
{
    int size = root->childNodes.size();
    for (int i = 0; i < size; i++)
    {
        this->PostorderTraversal(root->childNodes[i]);
    }

    cout << root->value << " ";
}

void Tree::InorderTraversal()
{
    this->InorderTraversal(this->root);
    cout << endl;
}

void Tree::InorderTraversal(Node* root)
{
    int size = root->childNodes.size();

    if (size >= 1) this->InorderTraversal(root->childNodes[0]);
    cout << root->value << " ";

    for (int i = 1; i < size; i++)
    {
        this->PostorderTraversal(root->childNodes[i]);
    }
}

void Tree::CheckBinaryTree()
{
    if (!this->IsBinaryTree())
    {
        cout << "NOT BINARY TREE" << endl;
        return;
    }

    this->InorderTraversal();
}




int main()
{
    Tree* tree = new Tree();

    int numOfNodes, numOfEdges;
    cin >> numOfNodes >> numOfEdges;
    for (int i = 0; i < numOfEdges; i++)
    {
        int parentValue, childValue;
        cin >> parentValue >> childValue;
        tree->Insert(parentValue, childValue);
    }

    cout << tree->GetHeightOfTree() << endl;
    tree->PreorderTraversal();
    tree->PostorderTraversal();
    tree->CheckBinaryTree();
    

    delete tree;
    return 0;
}



