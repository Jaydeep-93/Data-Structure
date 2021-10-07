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
        addAtBegin(40);
        addAtBegin(90);
        addAtBegin(10);
        addAtBegin(60);
        addAtBegin(50);
        addAtBegin(30);
        addAtBegin(20);
        addAtBegin(70);
        addAtBegin(80);
    }

    // display
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

    // add at begin
    void addAtBegin(int data)
    {
        Node *temp = new Node(data);
        temp->next = head;
        head = temp;
    }

    // selection sort via swapping data
    void bubble_swap_data()
    {
        Node *end, *p, *q ;
        for (end = NULL; end != head->next; end = q) 
        {
            for (p = head; p->next!=end; p = p->next)
            {
                q = p->next;
                if (p->info > p->next->info)
                {
                    swap(p->info, p->next->info);
                }
            }
        }
    }

    // selection swap via rearranging links
    void bubble_rearrange_links()
    {
    }
};

int main()
{
    LinkedList list;
    list.display();
    list.bubble_swap_data();
    // list.bubble_rearrange_links();
    list.display();
}