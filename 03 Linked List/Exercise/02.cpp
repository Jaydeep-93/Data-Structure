// 02 find largest and smallest no in linked list

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
        addFirst(10);
        addFirst(70);
        addFirst(80);
        addFirst(60);
        addFirst(10);
        addFirst(10);
        addFirst(20);
        addFirst(40);
        addFirst(90);
        addFirst(100);
    }

    // add at first
    void addFirst(int data)
    {
        Node *temp = new Node(data);
        temp->next = head;
        head = temp;
    }

    // find largest and samllest no in linked list
    void findLargeSmall()
    {
        int large = head->info;
        int small = head->info;
        Node *trav = head;
        while (trav)
        {
            if (trav->info > large)
                large = trav->info;
            if (trav->info < small)
                small = trav->info;
            trav = trav->next;
        }
        cout << "Large : " << large << "  Small : " << small << endl;
    }
};

int main()
{
    LinkedList list;
    list.findLargeSmall();
}