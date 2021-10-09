// swap nodes of linked list
// by arranging data and by arranging links
#include <iostream>
using namespace std;

class Node
{
public:
    int info;
    Node *next;
    Node *prev;
    Node(int data)
    {
        info = data;
        next = NULL;
        prev = NULL;
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
        if (head) //----> This is important check do not forget
            head->prev = temp;
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
        while (trav && trav->next)
        {
            if (trav == head)
                head = trav->next;

            Node *temp = trav->next;

            trav->next = temp->next;
            if (temp->next)
                temp->next->prev = trav;

            if (trav->prev)
                trav->prev->next = temp;
            temp->prev = trav->prev;

            temp->next = trav ; 
            trav->prev = temp ; 

            trav = trav->next ; 
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