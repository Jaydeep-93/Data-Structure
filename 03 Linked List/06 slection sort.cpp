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
    void selection_swap_data()
    {
        Node *p, *q;
        for (p = head; p->next != NULL; p = p->next)
        {
            for (q = p->next; q != NULL; q = q->next)
            {
                if (p->info > q->info)
                    swap(p->info, q->info);
            }
        }
    }

    // selection swap via rearranging links
    void selection_rearrange_links()
    {
        Node *p, *q, *r, *s, *temp;
        for (p = r = head; p->next != NULL; r = p, p = p->next)
        {
            for (q = s = p->next; q != NULL; s = q, q = q->next)
            {

                if (p->info > q->info)
                {
                    temp = p->next;
                    p->next = q->next;
                    q->next = temp;

                    if (p != head)
                        r->next = q;
                    s->next = p;
                    if (p == head)
                        head = q;

                    temp = p;
                    p = q;
                    q = temp;
                }
            }
        }
    }
};

int main()
{
    LinkedList list;
    // list.selection_swap_data();
    list.selection_rearrange_links();
    list.display();
}