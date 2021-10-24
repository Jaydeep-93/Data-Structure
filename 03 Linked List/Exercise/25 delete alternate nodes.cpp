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
    void addAtbegin(int data)
    {
        Node *temp = new Node(data);
        temp->next = head;
        head = temp;
    }
    void deleteNode(int data)
    {
        if (!head)
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
                break;
            }
            trav = trav->next;
        }
    }
    void deleteAlternate()
    {
        Node *trav = head;
        while (trav && trav->next)
        {
            deleteNode(trav->next->info);
            trav = trav->next;
        }
    }
};

int main()
{
    LinkedList list;
    list.addAtbegin(100);
    list.addAtbegin(90);
    list.addAtbegin(80);
    list.addAtbegin(70);
    list.addAtbegin(60);
    list.addAtbegin(50);
    list.addAtbegin(40);
    list.addAtbegin(30);
    list.addAtbegin(20);
    list.addAtbegin(10);
    list.display();
    list.deleteAlternate();
    list.display();
}