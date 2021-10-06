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

    // insert at proper position
    void insert(int data)
    {
        Node *temp = new Node(data);

        if (head == NULL || head->info > data)
        {
            temp->next = head;
            head = temp;
        }
        else
        {
            Node *trav = head;
            while (trav->next != NULL && trav->next->info < data)
                trav = trav->next;
            temp->next = trav->next;
            trav->next = temp;
        }
    }

    // insert at last
    void addAtLast(int data)
    {
        Node *temp = new Node(data);
        Node *trav = head;
        if (trav == NULL)
            head = temp;
        else
        {
            while (trav->next)
                trav = trav->next;
            trav->next = temp;
        }
    }
};

Node *merge(Node *head1, Node *head2)
{
    LinkedList result;
    while (head1 != NULL && head2 != NULL)
    {
        if (head1->info < head2->info)
        {
            result.addAtLast(head1->info);
            head1 = head1->next;
        }
        else if (head1->info > head2->info)
        {
            result.addAtLast(head2->info);
            head2 = head2->next;
        }
        else
        {
            result.addAtLast(head2->info);
            head1 = head1->next;
            head2 = head2->next;
        }
    }
    while (head1 != NULL)
    {
        result.addAtLast(head1->info);
        head1 = head1->next;
    }
    while (head2 != NULL)
    {
        result.addAtLast(head2->info);
        head2 = head2->next;
    }
    return result.head;
}

int main()
{
    LinkedList list1, list2;
    list1.insert(20);
    list1.insert(50);
    list1.insert(80);
    list1.insert(90);

    list2.insert(30);
    list2.insert(70);
    list2.insert(50);
    list2.insert(10);

    list1.display();
    list2.display();

    LinkedList result;
    result.head = merge(list1.head, list2.head);
    result.display();
}