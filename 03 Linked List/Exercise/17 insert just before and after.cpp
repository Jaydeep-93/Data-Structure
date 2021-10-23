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

    void addAtBegin(int data)
    {
        Node *temp = new Node(data);
        temp->next = head;
        head = temp;
    }

    Node *getNode(int data)
    {
        Node *trav = head;
        while (trav)
        {
            if (trav->info == data)
                return trav;

            trav = trav->next;
        }
        return NULL;
    }
    void deleteNode(Node *trav)
    {
        if (trav->next == NULL)
        {
            cout << " cannot delete last node ... " << endl;
            return;
        }
        trav->info = trav->next->info;
        trav->next = trav->next->next;
    }

    void insertAfter(int data, Node *node)
    {
        Node *temp = new Node(data);
        temp->next = node->next;
        node->next = temp;
    }
    void insertBefore(int data, Node *node)
    {
        Node *temp = new Node(node->info);
        temp->next = node->next;
        node->next = temp;
        node->info = data;
    }
};

int main()
{
    LinkedList l;
    l.addAtBegin(100);
    l.addAtBegin(90);
    l.addAtBegin(80);
    l.addAtBegin(70);
    l.addAtBegin(60);
    l.addAtBegin(50);
    l.addAtBegin(40);
    l.addAtBegin(30);
    l.addAtBegin(20);
    l.addAtBegin(10);
    l.display();

    // get 50 node
    Node *node = l.getNode(100);

    // insert data after
    // if (node)
    //     l.insertAfter(101, node);

    if (node)
        l.insertBefore(101, node);

    l.display();
}