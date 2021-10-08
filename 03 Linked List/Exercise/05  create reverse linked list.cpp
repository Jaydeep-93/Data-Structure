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

    // add element at first
    void addFirst(int data)
    {
        Node *temp = new Node(data);
        temp->next = head;
        head = temp;
    }

    // display
    void display()
    {
        Node *trav = head;
        cout << "list : ";
        while (trav)
        {
            cout << trav->info << "  -> ";
            trav = trav->next;
        }
        cout << endl;
    }

    // addlast 
    void addLast(int data) {
        Node * temp = new Node(data) ; 
        if (head==NULL){
            head = temp  ;
        }
        else {
            Node * trav = head ; 
            while (trav->next) 
                trav = trav->next ; 
            trav->next = temp ;
        }
    }

    LinkedList copyReverseLinkedList()
    {
        LinkedList list;
        Node *trav = head;
        while (trav)
        {
            list.addLast(trav->info);
            trav = trav->next;
        }
        return list;
    }
};

int main()
{
    LinkedList list1;
    list1.addFirst(30);
    list1.addFirst(20);
    list1.addFirst(10);

    LinkedList list2 = list1.copyReverseLinkedList();
    list2.display();
}
