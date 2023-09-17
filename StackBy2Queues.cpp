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

class Queue
{
public:
    Node* head;
    Node* tail;
    Queue();
    ~Queue();
    void PrintOut();
    void Enqueue(Node* &element);
    Node* Dequeue();

private:

};

Queue::Queue()
{
    this->head = NULL;
    this->tail = NULL;
}

Queue::~Queue()
{
    //delete all elements in queue
}


void Queue::PrintOut()
{
    Node* p = head;
    cout << "Linked List: ";
    while (p != NULL)
    {
        cout << p->value << " ";
        p = p->next;
    }
    cout << endl;
}

void Queue::Enqueue(Node* &newNode)
{
    if (newNode == NULL) return;
    if (this->tail == NULL)
    {
        this->tail = newNode;
        this->head = newNode;
        return;
    }
    this->tail->next = newNode;
    this->tail = newNode;
}

Node* Queue::Dequeue()
{
    Node* p = this->head;
    if (p == NULL) return NULL;
    this->head = this->head->next;
    if (this->head == NULL) this->tail = NULL;
    return p;
}



class StackBy2Queues
{
public:
    Node* top;
    Queue* queue1;
    Queue* queue2;
    StackBy2Queues();
    ~StackBy2Queues();
    void PrintOut();
    void Push(int value);
    void Pop();
    void SwapQueue(Queue* &queue1, Queue* &queue2);

private:

};

StackBy2Queues::StackBy2Queues()
{
    this->top = NULL;
    this->queue1 = new Queue();
    this->queue2 = new Queue();
}

StackBy2Queues::~StackBy2Queues()
{
    //delete this->top;
    //delete this->queue1;
    //delete this->queue2;
}

void StackBy2Queues::PrintOut()
{
    this->queue1->PrintOut();
    //this->queue2->PrintOut();
}

void StackBy2Queues::Push(int value)
{
    Node* newNode = new Node();
    newNode->value = value;

    //enqueue new element into q2
    this->queue2->Enqueue(newNode);

    //dequeue everything from q1 into q2
    Node* p = NULL;
    do
    {
        p = this->queue1->Dequeue();
        this->queue2->Enqueue(p);
    } while (p != NULL);
    

    //swap q1 and q2
    this->SwapQueue(this->queue1, this->queue2);

}

void StackBy2Queues::Pop()
{
    /*if (this->top == NULL) return;
    Node* p = top;
    this->top = this->top->next;
    delete p;*/
    Node* p = this->queue1->Dequeue();
    delete p;
}

void StackBy2Queues::SwapQueue(Queue* &q1, Queue* &q2)
{
    Queue* queueTemp = q1;
    q1 = q2;
    q2 = queueTemp;
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
    
    StackBy2Queues* stack = new StackBy2Queues();

    /*int nOperation;
    cin >> nOperation;
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
    }*/

    stack->Push(2);
    stack->Push(3);
    stack->Push(4);
    stack->Push(4);
    stack->Push(4);
    stack->Pop();
    stack->Pop();

    stack->PrintOut();

    delete stack;
    return 0;
}



