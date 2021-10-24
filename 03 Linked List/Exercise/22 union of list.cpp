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
bool isPresent(Node *resultHead, int data)
{
    Node *trav = resultHead;
    while (trav)
    {
        if (trav->info == data)
            return true;
        trav = trav->next;
    }
    return false;
}
LinkedList unionList(Node *head1, Node *head2)
{
    LinkedList result;
    Node *trav = head1;
    while (trav->next)
    {
        result.addAtBegin(trav->info);
        trav = trav->next;
    }

    Node *innterTrav = head2;
    while (innterTrav)
    {
        if (!isPresent(result.head, innterTrav->info))
        {
            result.addAtBegin(innterTrav->info);
        }
        innterTrav = innterTrav->next;
    }
    return result;
};

int main()
{
    LinkedList list1;
    list1.addAtBegin(70);
    list1.addAtBegin(20);
    list1.addAtBegin(10);
    list1.addAtBegin(40);
    list1.addAtBegin(30);
    list1.addAtBegin(80);

    LinkedList list2;
    list2.addAtBegin(10);
    list2.addAtBegin(20);
    list2.addAtBegin(30);
    list2.addAtBegin(40);
    list2.addAtBegin(50);
    list2.addAtBegin(60);
    list2.addAtBegin(70);

    list1.display();
    list2.display();

    LinkedList list3 = ::unionList(list1.head, list2.head);
    list3.display();
}