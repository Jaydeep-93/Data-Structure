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
        this->head = NULL;
    }

    // add at first
    void addFirst(int data)
    {
        Node *temp = new Node(data);
        temp->next = head;
        head = temp;
    }

    // display
    void display()
    {
        Node *trav = head;
        cout << "list : ";
        while (trav)
        {
            cout << trav->info << " -> ";
        }
        cout << endl;
    }

    // actual function
    bool areIdentical(LinkedList list)
    {
        Node *trav1 = head;
        Node *trav2 = list.head;

        while (trav1 != NULL || trav2 != NULL)
        {
            if (trav1->info != trav2->info)
                break;
            trav1 = trav1->next;
            trav2 = trav2->next;
        }

        if (trav1 == NULL && trav2 == NULL)
            return true;
        else
            return false;
    }
};

int main()
{
    LinkedList l1;
    l1.addFirst(10);
    l1.addFirst(20);
    l1.addFirst(30);
    l1.addFirst(40);

    LinkedList l2;
    l2.addFirst(10);
    l2.addFirst(20);
    l2.addFirst(30);
    l2.addFirst(40);

    cout << l1.areIdentical(l2) << endl;
}