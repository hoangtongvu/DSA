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
    Node* previous;
    Node* next;
};



class DoubleLinkedList
{
public:
    Node* head;
    Node* tail;
    DoubleLinkedList();
    ~DoubleLinkedList();
    void Insert(int p, int x);
    void InsertTail(int value);
    void PrintOut();
    void Count_triplets();
    void Delete(int p);

private:

};

DoubleLinkedList::DoubleLinkedList()
{
    this->head = new Node();
    this->tail = new Node();
    this->head->next = this->tail;
    this->tail->previous = this->head;
}

DoubleLinkedList::~DoubleLinkedList()
{
}


void DoubleLinkedList::InsertTail(int value)
{
    Node* newNode = new Node();
    newNode->value = value;
    Node* p = this->tail->previous;
    p->next = newNode;
    newNode->previous = p;
    newNode->next = this->tail;
    this->tail->previous = newNode;
}


void DoubleLinkedList::Insert(int pos, int value)//Need fix
{
    Node* newNode = new Node();
    newNode->value = value;

    if (this->head == NULL)
    {
        head = newNode;
        return;
    }

    Node* p = head;

    if (pos == 0)
    {
        newNode->next = head;
        head = newNode;
        return;
    }


    for (int i = 0; i < pos - 1; i++)
    {
        p = p->next;
    }


    newNode->next = p->next;
    p->next = newNode;

}

void DoubleLinkedList::Delete(int pos)//Need fix
{
    Node* p = head;
    for (int i = 0; i < pos - 1; i++)
    {
        p = p->next;
    }

    Node* q = p->next;
    if (q == NULL)
    {
        delete q;
        return;
    }

    p->next = q->next;
    delete q;

}//



void DoubleLinkedList::PrintOut()
{
    Node* p = this->head->next;
    cout << "Double Linked List: ";
    while (p != this->tail)
    {
        cout << p->value << " ";
        p = p->next;
    }
    cout << endl;
}


void DoubleLinkedList::Count_triplets()
{
    Node* p = this->head->next;

    int count = 0;
    int* arr = new int[3];
    arr[0] = 3;
    while (p != this->tail)
    {
        if (p->previous == this->head) arr[0] = 0;
        else arr[0] = p->previous->value;

        if (p->next == this->tail) arr[2] = 0;
        else arr[2] = p->next->value;

        arr[0] = p->previous->value;
        arr[2] = p->next->value;


        arr[1] = p->value;

        int sum = 0;
        for (int i = 0; i < 3; i++)
        {
            sum += arr[i];
        }

        if (sum == 0) count++;

        p = p->next;
    }

    delete []arr;
    cout << "Count triplets = " << count << endl;

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

    int n;
    cin >> n;
    DoubleLinkedList* list = new DoubleLinkedList();
    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        list->InsertTail(k);
    }





    list->PrintOut();

    list->Count_triplets();

    delete list;
	return 0;
}



