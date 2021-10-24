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
    Node * findMiddle()
    {
        if (head == NULL)
            return NULL;
        if (head->next == NULL)
            return head;

        Node *slow = head;
        Node *fast = head;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow ;
    }
};

int main()
{
    LinkedList list;
    // list.addAtBegin(100);
    list.addAtBegin(90);
    list.addAtBegin(80);
    list.addAtBegin(70);
    list.addAtBegin(60);
    list.addAtBegin(50);
    list.addAtBegin(40);
    list.addAtBegin(30);
    list.addAtBegin(20);
    list.addAtBegin(10);
    list.display();

    // find middle of linked list
    cout << list.findMiddle()->info << endl;
}