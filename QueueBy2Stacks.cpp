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
    void Push(Node* &element);
    Node* Pop();

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

void Stack::Push(Node* &newNode)
{
    if (newNode == NULL) return;
    newNode->next = this->top;
    this->top = newNode;
}



Node* Stack::Pop()
{
    if (this->top == NULL) return NULL;
    Node* p = top;
    this->top = this->top->next;
    return p;
}


class QueueBy2Stacks
{
public:
    Stack* s1;
    Stack* s2;
    QueueBy2Stacks();
    ~QueueBy2Stacks();
    void Enqueue(int value);
    void Dequeue();
    void PopFromPushTo(Stack* sFrom, Stack* sTo);
    void PrintOut();

private:

};

QueueBy2Stacks::QueueBy2Stacks()
{
    this->s1 = new Stack();
    this->s2 = new Stack();
}

QueueBy2Stacks::~QueueBy2Stacks()
{
    delete s1;
    delete s2;
}

void QueueBy2Stacks::Enqueue(int value)
{
    Node* newNode = new Node();
    newNode->value = value;
    //push every newNode into s2
    this->s2->Push(newNode);
}

void QueueBy2Stacks::Dequeue()
{
    //pop everything in s2 and push them into s1
    this->PopFromPushTo(this->s2, this->s1);

    //pop s1
    Node* p = this->s1->Pop();
    delete p;

    //pop everything in s1 and push them into s2
    this->PopFromPushTo(this->s1, this->s2);
}

void QueueBy2Stacks::PopFromPushTo(Stack* sFrom, Stack* sTo)
{
    Node* p = NULL;
    do
    {
        p = sFrom->Pop();
        sTo->Push(p);
    } while (p != NULL);
}

void QueueBy2Stacks::PrintOut()
{
    string output = "";
    Node* p = this->s2->top;
    while (p != NULL)
    {
        output = to_string(p->value) + " " + output;
        p = p->next;
    }

    cout << "QueueBy2Stacks: " << endl;
    cout << output;


}


int main()
{
    QueueBy2Stacks* queue = new QueueBy2Stacks();


    int nOperation;
    cin >> nOperation;

    for (int i = 0; i < nOperation; i++)
    {
        string description;
        cin >> description;
        if (description == "enqueue")
        {
            int x;
            cin >> x;
            queue->Enqueue(x);
        }
        else if (description == "dequeue")
        {
            queue->Dequeue();
        }
    }


    queue->PrintOut();

    delete queue;

    return 0;
}



