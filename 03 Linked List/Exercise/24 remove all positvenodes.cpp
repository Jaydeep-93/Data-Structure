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
    void deleteNode(int data)
    {
        if (!head)
            return;
        if (head->info == data)
        {
            head = head->next;
        }
        Node *trav = head;
        while (trav && trav->next)
        {
            if (trav->next->info == data)
            {
                trav->next = trav->next->next;
            }
            else
                trav = trav->next;
        }
    }
    LinkedList removeNegatives()
    {
        LinkedList result;
        Node *trav = head;
        while (trav)
        {
            if (trav->info > 0)
            {
                result.addAtBegin(trav->info);
                this->deleteNode(trav->info);
            }
            trav = trav->next;
        }
        return result;
    }
};

int main()
{
    LinkedList list;
    list.addAtBegin(-6);
    list.addAtBegin(10);
    list.addAtBegin(-5);
    list.addAtBegin(20);
    list.addAtBegin(30);
    list.addAtBegin(-3);
    list.addAtBegin(40);
    list.addAtBegin(-4);
    list.addAtBegin(50);
    list.addAtBegin(-2);
    list.addAtBegin(60);
    list.addAtBegin(70);
    list.addAtBegin(-1);
    list.display();
    LinkedList result = list.removeNegatives();
    result.display();
    list.display();
}