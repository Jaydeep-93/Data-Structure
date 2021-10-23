#include <iostream>
using namespace std;

class Node
{
public:
    int info;
    Node *next;

    Node(int data)
    {
        this->info = data;
        this->next = NULL;
    }
};

class LinkedList
{
public:
    Node *head;
    LinkedList()
    {
        head = NULL;
        addFirst(50);
        addFirst(10);
        addFirst(40);
        addFirst(30);
        addFirst(20);
        addFirst(60);
    }

    void addFirst(int data)
    {
        Node *temp = new Node(data);
        temp->next = head;
        head = temp;
    }

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

    void moveSmallAtFront()
    {
        Node *trav = head;
        Node *smallest = head;
        while (trav)
        {
            if (smallest->info > trav->info)
                smallest = trav;
            trav = trav->next;
        }
        swap(head->info, smallest->info);
    }

    void moveSmallAtFrontLinks()
    {
        Node *trav = head;
        Node *prev = NULL, *prevSmall = NULL;
        Node *smallest = head;
        while (trav)
        {
            if (smallest->info > trav->info)
            {
                smallest = trav;
                prevSmall = prev;
            }
            prev = trav;
            trav = trav->next;
        }
        Node *temp = head->next;
        head->next = smallest->next;
        prevSmall->next = head;
        smallest->next = temp;
        head = smallest;
    }
};

int main()
{
    LinkedList list;
    list.display();
    // list.moveSmallAtFront();
    list.moveSmallAtFrontLinks();
    list.display();
}