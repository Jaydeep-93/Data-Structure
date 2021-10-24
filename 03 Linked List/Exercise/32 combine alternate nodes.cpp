// E32 - Program to combine alternate nodes of two single linked lists
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
class Linkedlist
{
public:
    Node *head = NULL;
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
    void deleteNode(int data)
    {
        if (head == NULL)
            return;
        if (head->info == data)
        {
            head = head->next;
            return;
        }
        Node *trav = head;
        while (trav && trav->next)
        {
            if (trav->next->info == data)
            {
                trav->next = trav->next->next;
                return;
            }
            else
                trav = trav->next;
        }
    }
    void combineAlternate(Linkedlist &list)
    {
        Node *trav = head;
        Node *otherTrav = list.head;
        while (trav && otherTrav)
        {
            Node *temp = new Node(otherTrav->info);
            temp->next = trav->next;
            trav->next = temp;
            list.deleteNode(temp->info);
            trav = trav->next->next;
            otherTrav = otherTrav->next;
        }

    }
};

int main()
{
    Linkedlist l1;
    l1.addAtBegin(100);
    l1.addAtBegin(90);
    l1.addAtBegin(80);
    l1.addAtBegin(70);
    l1.addAtBegin(60);
    l1.addAtBegin(50);
    l1.addAtBegin(40);
    l1.addAtBegin(30);
    l1.addAtBegin(20);
    l1.addAtBegin(10);

    Linkedlist l2;
    l2.addAtBegin(101);
    l2.addAtBegin(91);
    l2.addAtBegin(81);
    l2.addAtBegin(71);
    l2.addAtBegin(61);
    l2.addAtBegin(51);
    l2.addAtBegin(41);
    l2.addAtBegin(31);
    l2.addAtBegin(21);
    l2.addAtBegin(11);

    cout << "l1 : ";
    l1.display();
    cout << "l2 : ";
    l2.display();

    l1.combineAlternate(l2);

    cout << "l1 : ";
    l1.display();
    cout << "l2 : ";
    l2.display();
}