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

    // for header Linked List construcotr is gonna be diffrent
    // value at header node will be length of list --> assumed
    LinkedList()
    {
        Node *temp = new Node(0);
        this->head = temp;
    }

    // add at end
    void addAtEnd(int data)
    {
        Node *trav = head;
        while (trav->next != NULL)
            trav = trav->next;
        Node *temp = new Node(data);
        trav->next = temp;
        head->info++; // incrementing value of header node
    }

    // display
    void display()
    {
        Node *trav = head;
        cout << "List is : " << trav->info << " ==> ";
        trav = trav->next;
        while (trav)
        {
            cout << trav->info << " --> ";
            trav = trav->next;
        }
        cout << endl;
    }

    // add before node
    void addBeforeNode(int data, int item)
    {
        // add before node if node found else add at end
        Node *trav = head;
        while (trav->next != NULL)
        {
            if (trav->next->info == item)
                break;
            trav = trav->next;
        }
        Node *temp = new Node(data);
        temp->next = trav->next;
        trav->next = temp;
        head->info++;
    }

    // add at position
    void addAtPosition(int data, int position)
    {
        // if position is available insert else add at last
        Node *trav = head;
        for (int i = 1; i < position && trav->next; i++)
        {
            trav = trav->next;
        }
        Node *temp = new Node(data);
        temp->next = trav->next;
        trav->next = temp;
        head->info++;
    }

    // delete
    void deleteNode(int item)
    {
        // find node and delete it else do nothng
        Node *trav = head;
        while (trav->next != NULL)
        {
            if (trav->next->info == item)
            {
                Node *temp = trav->next;
                trav->next = trav->next->next;
                free(temp);
                head->info--;
                return;
            }
            trav = trav->next;
        }
    }

    // reverse
    void reverse()
    {
        Node *curr = head->next;
        Node *prev = NULL;
        while (curr)
        {
            Node *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head->next = prev;
    }
};

int main()
{
    LinkedList list;
    // list.addAtEnd(30);
    // list.addAtEnd(20);
    // list.addAtEnd(10);
    // list.addBeforeNode(40, 20);
    // list.display();

    // list.addAtPosition(10, 5);
    // list.addAtPosition(20, 2);
    // list.addAtPosition(30, 3);
    // list.addAtPosition(15, 2);
    // list.display();

    list.deleteNode(10);
    list.addAtEnd(50);
    list.addAtEnd(40);
    list.addAtEnd(30);
    list.addAtEnd(20);
    list.addAtEnd(10);
    list.display();
    list.reverse();
    list.display();
}