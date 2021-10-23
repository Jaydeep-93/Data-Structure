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
};
void displayWRT(Node *head1, Node *head2)
{
    Node *trav = head1;
    while (trav)
    {

        int index = trav->info;

        Node *innerTrav = head2;
        for (int i = 1; i < index; i++)
        {
            innerTrav = innerTrav->next;
        }
        cout << innerTrav->info << "   ";

        trav = trav->next;
    }
    cout << endl;
}

int main()
{

    LinkedList list1;
    list1.addAtBegin(8);
    list1.addAtBegin(7);
    list1.addAtBegin(5);
    list1.addAtBegin(2);
    list1.addAtBegin(1);

    list1.display();

    LinkedList list2;
    list2.addAtBegin(100);
    list2.addAtBegin(90);
    list2.addAtBegin(80);
    list2.addAtBegin(70);
    list2.addAtBegin(60);
    list2.addAtBegin(50);
    list2.addAtBegin(40);
    list2.addAtBegin(30);
    list2.addAtBegin(20);
    list2.addAtBegin(10);

    ::displayWRT(list1.head, list2.head);
}
