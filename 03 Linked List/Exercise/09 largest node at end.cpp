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

    void moveLargeAtEnd()
    {
        Node *trav = head;
        while (trav && trav->next)
        {
            if (trav->info > trav->next->info)
                swap(trav->info, trav->next->info);
            trav = trav->next;
        }
    }

    void moveLargeAtEndLinks()
    {
        Node *p, *q, *r;
        p = head;
        q = head->next;
        r = NULL;
        while (q)
        {
            p->next = q->next;
            if (r == NULL)
                head = q;
            else
                r->next = q;
            q->next = p;

            r = q;
            q = p->next;
        }
    }
};

int main()
{
    LinkedList list;
    list.display();
    // list.moveLargeAtEnd();
    list.moveLargeAtEndLinks();
    list.display();
}