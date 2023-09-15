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


class LinkedList
{
public:
    Node* head;
    LinkedList();
    ~LinkedList();
    void Insert(int p, int x);
    void PrintOut();
    void Delete(int p);

private:

};

LinkedList::LinkedList()
{
    this->head = NULL;
}

LinkedList::~LinkedList()
{
}


void LinkedList::Insert(int pos, int value)
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

void LinkedList::Delete(int pos)
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

}



void LinkedList::PrintOut()
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
    LinkedList* linkList = new LinkedList();
    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        linkList->Insert(i, k);
    }




    linkList->Delete(1);

    linkList->PrintOut();

    delete linkList;
	return 0;
}



