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
    Node* next;
    Node(int _value);
    ~Node();

private:

};

Node::Node(int _value)
{
    this->value = _value;
    this->next = NULL;
}

Node::~Node()
{
}


void deleteDuplicates(Node* &head)
{
    Node* p1 = head;
    Node* p2 = NULL;
    Node* dup = NULL;

    while (p1 != NULL && p1->next != NULL)
    {
        p2 = p1;

        while (p2->next != NULL)
        {
            if (p1->value == p2->next->value)
            {
                dup = p2->next;
                p2->next = p2->next->next;
                delete dup;
                continue;
            }

            p2 = p2->next;
        }


        p1 = p1->next;
    }
}

void deleteSingle(Node* &head)
{
    Node* p1 = head;
    Node* p2 = NULL;
    Node* lastDup = NULL;
    Node* prevToDel = NULL;

    while (p1 != NULL)
    {
        cout << "find last dup" << endl;
        

        p2 = p1;

        //find last dup.
        while (p2->next != NULL)
        {
            if (p1->value == p2->next->value)
            {
                lastDup = p2->next;
            }
            else
            {
                if (p2 == p1)
                {
                    lastDup = NULL;
                }
                break;
            }

            p2 = p2->next;
        }

        cout << "del if necessary" << endl;

        if (lastDup == NULL || p1->next == NULL)
        {
            //del p1/p2.

            if (prevToDel == NULL) //mean p1 is head.
            {
                Node* temp = head;
                head = head->next;
                p1 = head;
                delete temp;
                
            }
            else
            {
                Node* temp = prevToDel->next;
                prevToDel->next = temp->next;
                p1 = temp->next;
                delete temp;
                    
            }

            continue;
        }


        //tele p1 to lastDup.next.
        prevToDel = lastDup;
        p1 = lastDup->next;




    }

}


void PrintLinkedList(Node* head)
{
    Node* p = head;

    while (p != NULL)
    {
        cout << p->value << " ";
        p = p->next;
    }
    cout << endl;
}



int main() // 10 10 11 11 12 13 13
{
    Node* start = new Node(8);
    start->next = new Node(9);
    start->next->next = new Node(10);
    start->next->next->next = new Node(11);
    start->next->next->next->next = new Node(11);
    start->next->next->next->next->next = new Node(12);
    start->next->next->next->next->next->next = new Node(13);
    start->next->next->next->next->next->next->next = new Node(13);
    start->next->next->next->next->next->next->next->next = new Node(14);

    cout << "Linked list before del single ";
    PrintLinkedList(start);

    deleteSingle(start);

    cout << "Linked list after del single ";
    PrintLinkedList(start);


    return 0;
}


