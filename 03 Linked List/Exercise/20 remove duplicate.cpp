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
    void removeDuplicate()
    {
        Node *trav = head;
        while (trav && trav->next)
        {
            Node *innerTrav = trav;
            while (innerTrav && innerTrav->next)
            {
                if (innerTrav->next->info == trav->info)
                    innerTrav->next = innerTrav->next->next;
                else
                    innerTrav = innerTrav->next;
            }
            trav = trav->next;
        }
    }
};

int main()
{
    LinkedList list;
    list.addAtBegin(10);
    list.addAtBegin(70);
    list.addAtBegin(10);
    list.addAtBegin(50);
    list.addAtBegin(20);
    list.addAtBegin(30);
    list.addAtBegin(70);
    list.addAtBegin(30);
    list.display();
    list.removeDuplicate();
    list.display();
}