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

    void move(int data, int pos)
    {
        Node *prev, *curr = head;
        while (curr)
        {
            if (curr->info == data)
                break;
            prev = curr;
            curr = curr->next;
        }
        if (curr == NULL)
        {
            cout << "data not found in list ..." << endl;
            return;
        }

        if (curr == head)
        {
            head = head->next;
            prev = head;
        }
        else
            prev->next = curr->next;

        Node *trav = prev;
        for (int i = 0; i < pos; i++)
        {
            trav = trav->next;
            if (trav == NULL)
            {
                cout << "can not move to this location ...";
                return;
            }
        }
        curr->next = trav->next;
        trav->next = curr;
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

    l.move(10, 2);
    l.display();
}