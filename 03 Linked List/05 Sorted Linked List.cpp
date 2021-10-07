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

class SortedLinkedList
{
public:
    Node *head;

    SortedLinkedList()
    {
        this->head = NULL;
    }

    // display
    void display()
    {
        Node *trav = head;
        cout << "List is : ";
        while (trav)
        {
            cout << trav->info << " --> ";
            trav = trav->next;
        }
        cout << endl;
    }

    // insert
    void insert_s(int data)
    {
        // insert data in sorted order ;
        Node *temp = new Node(data);
        Node *trav = head;
        if (head == NULL || data < head->info)
        {
            head = temp;
        }
        else
        {
            while (trav->next && trav->next->info < data)
            {
                trav = trav->next;
            }
            temp->next = trav->next;
            trav->next = temp;
        }
    }
};

int main()
{
    SortedLinkedList list;
    list.insert_s(10);
    list.insert_s(50);
    list.insert_s(30);
    list.insert_s(60);

    list.display();
}