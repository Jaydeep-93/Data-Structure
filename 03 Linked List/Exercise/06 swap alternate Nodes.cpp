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

    // swap node data
    void swapNodeData()
    {
        Node *trav = head;
        while (trav && trav->next)
        {
            swap(trav->info, trav->next->info);
            trav = trav->next->next;
        }
    }

    // swap links
    void swapNodeLinks()
    {
        Node *trav = head;
        Node *prev = NULL;
        while (trav && trav->next)
        {
            if (trav == head)
                head = trav->next;
            Node *temp = trav->next;
            trav->next = temp->next;
            temp->next = trav;
            if (prev != NULL)
                prev->next = temp;

            prev = trav;
            trav = trav->next;
        }
    }
};

int main()
{
    LinkedList list;
    list.display();
    // list.swapNodeData();
    list.swapNodeLinks();
    list.display();
}