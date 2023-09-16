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
    Node* next;
};


class Stack
{
public:
    Node* top;
    Stack();
    ~Stack();
    void PrintOut();
    void Push(int value);
    void Pop();

private:

};

Stack::Stack()
{
    this->top = NULL;
}

Stack::~Stack()
{
}



void Stack::PrintOut()
{
    Node* p = top;
    cout << "Linked List: ";
    while (p != NULL)
    {
        cout << p->value << " ";
        p = p->next;
    }
    cout << endl;
}

void Stack::Push(int value)
{
    Node* newNode = new Node();
    newNode->value = value;
    newNode->next = top;
    this->top = newNode;
}

void Stack::Pop()
{
    if (this->top == NULL) return;
    Node* p = top;
    this->top = this->top->next;
    delete p;
}


void Swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}




vector<int> GetInputArray(int length)
{
    vector<int> temp;
    for (int i = 0; i < length; i++)
    {
        int k;
        cin >> k;
        temp.push_back(k);
    }
    return temp;
}


void PrintOutArray(vector<int> arr)
{
    int length = arr.size();
    cout << "array after sorting: " << endl;
    for (int i = 0; i < length; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}


int main()
{
    

    int nOperation;
    cin >> nOperation;
    Stack* stack = new Stack();
    for (int i = 0; i < nOperation; i++)
    {
        string description;
        cin >> description;

        if (description == "push")
        {
            int value;
            cin >> value;
            stack->Push(value);
        }
        else if (description == "pop")
        {
            stack->Pop();
        }
    }


    stack->PrintOut();

    delete stack;
    return 0;
}



