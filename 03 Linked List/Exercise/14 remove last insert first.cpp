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

    void removeLastInsertFirst()
    {
        if (head == NULL || head->next == NULL)
            return;

        Node *trav = head;
        while (trav->next->next)
            trav = trav->next;
        Node *temp = trav->next;
        trav->next = NULL;
        temp->next = head;
        head = temp;
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

    l.removeLastInsertFirst();
    l.display();
}