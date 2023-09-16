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
    void Enqueue(int value);
    void Dequeue();

private:

};

Queue::Queue()
{
    this->head = NULL;
    this->tail = NULL;
}

Queue::~Queue()
{
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

void Queue::Enqueue(int value)
{
    Node* newNode = new Node();
    newNode->value = value;
    if (this->tail == NULL && this->head == NULL)
    {
        this->tail = newNode;
        this->head = newNode;
    }
    this->tail->next = newNode;
    this->tail = newNode;
}

void Queue::Dequeue()
{
    Node* p = this->head;
    if (p == NULL) return;
    this->head = head->next;
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
    /*int n;
    cin >> n;
    vector<int> list = GetInputArray(n);*/

    //vector<int> list;
    //list = { 5, 2, 4, 2, 2, 5, 2 };

    //PrintOutArray(list);

    int nOperation;
    cin >> nOperation;
    Queue* queue = new Queue();
    
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



