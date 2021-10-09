// swap nodes of linked list
// by arranging data and by arranging links
#include <iostream>
using namespace std;

class Node
{
public:
    int info;
    Node *next;
    Node(int data)
    {
        info = data;
        next = NULL;
    }
};

class LinkedList
{
public:
    Node *head;

    LinkedList()
    {
        head = NULL;
        addAtBegin(100);
        addAtBegin(90);
        addAtBegin(80);
        addAtBegin(70);
        addAtBegin(60);
        addAtBegin(50);
        addAtBegin(40);
        addAtBegin(30);
        addAtBegin(20);
        addAtBegin(10);
    }

    // display
    void display()
    {
        Node *trav = head;
        cout << "list : ";
        while (trav)
        {
            cout << trav->info << " --> ";
            trav = trav->next;
        }
        cout << endl;
    }

    // add at begining
    void addAtBegin(int data)
    {
        Node *temp = new Node(data);
        temp->next = head;
        head = temp;
    }

    // swap first and last node
    void swapFirstAndLastNodeData()
    {
        if (!head)
            return;
        Node *trav = head;
        while (trav->next)
            trav = trav->next;

        swap(head->info, trav->info);
    }

    // swap first and last node by rearranging links
    void swapFirstAndLastNodeLinks()
    {
        if (!head)
            return;
        Node *prev = NULL;
        Node *trav = head;
        while (trav->next)
        {
            prev = trav;
            trav = trav->next;
        }

        trav->next = head->next;
        if (prev)
            prev->next = head;
        head->next = NULL;
        head = trav;
    }
};

int main()
{
    LinkedList list;
    list.display();
    // list.swapFirstAndLastNodeData();
    list.swapFirstAndLastNodeLinks();
    list.display();
}