// Non Circular Singly Linked list
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

    // Initialize Linked list
    LinkedList()
    {
        head = NULL;
        this->addAtLast(10);
        this->addAtLast(20);
        this->addAtLast(30);
        this->addAtLast(40);
        this->addAtLast(50);
    }

    // display list
    void display()
    {
        Node *trav = head;
        cout << "list is : ";
        while (trav != NULL)
        {
            cout << trav->info << " --> ";
            trav = trav->next;
        }
        cout << endl;
    }

    // display recursively
    void displayR(Node *trav)
    {
        if (trav == NULL)
            return;
        else
        {
            cout << trav->info << " --> ";
            displayR(trav->next);
        }
    }

    // count no of nodes
    int count()
    {
        Node *trav = head;
        int counter = 0;
        while (trav != NULL)
        {
            counter++;
            trav = trav->next;
        }
        return counter;
    }

    // search for element
    bool search(int data)
    {
        Node *trav = head;
        while (trav != NULL)
        {
            if (trav->info == data)
                return true;
            trav = trav->next;
        }
        return false;
    }

    //add at begining
    void addAtBegin(int data)
    {
        Node *temp = new Node(data);
        temp->next = head;
        head = temp;
    }

    // add at last
    void addAtLast(int data)
    {
        if (head == NULL)
        {
            head = new Node(data);
        }
        else
        {
            Node *trav = head;
            while (trav->next != NULL)
                trav = trav->next;
            Node *temp = new Node(data);
            trav->next = temp;
        }
    }

    // add after node
    void addAfterNode(int data, int item)
    {
        // if item is present add after node else add at end
        Node *trav = head;
        while (trav != NULL)
        {
            if (trav->info == item)
                break;
            trav = trav->next;
        }
        // if list is null modify value head after adding
        if (trav != NULL)
        {
            Node *temp = new Node(data);
            temp->next = trav->next;
            trav->next = temp;
        }
        else
        {
            this->addAtLast(data);
        }
    }

    // add before node
    void addBeforeNode(int data, int item)
    {
        // if item present add at position else add at end
        Node *trav = head;
        if (trav == NULL)
        {
            addAtBegin(data);
        }
        else if (trav->info == item)
        {
            addAtBegin(data);
        }
        else
        {
            while (trav->next != NULL)
            {
                if (trav->next->info == item)
                    break;
                trav = trav->next;
            }
            Node *temp = new Node(data);
            temp->next = trav->next;
            trav->next = temp;
        }
    }

    // add at poisition
    void addAtPososition(int data, int position)
    {
        int counter = 0;
        Node *trav = head;
        if (position == 0 || trav == NULL)
            addAtBegin(data);
        else
        {
            while (trav != NULL)
            {
                if (counter == position)
                    break;
                trav = trav->next;
                counter++;
            }
            if (trav != NULL)
            {
                Node *temp = new Node(data);
                temp->next = trav->next;
                trav->next = temp;
            }
            else
                addAtLast(data);
        }
    }

    // delete node from list
    void deleteNode(int data)
    {
        Node *trav = head;
        if (trav == NULL)
        {
            return;
        }
        else if (trav->info == data)
        {
            Node *temp = trav;
            head = trav->next;
            free(temp);
        }
        else
        {
            Node *prev = NULL;
            Node *curr = head;
            while (curr)
            {
                if (curr->info == data)
                    break;
                prev = curr;
                curr = curr->next;
            }
            if (!curr)
                return;
            Node *temp = prev->next;
            prev->next = prev->next->next;
            free(temp);
        }
    }

    // delete first element
    void deleteFirstNode()
    {
        Node *trav = head;
        Node *temp = trav;
        head = trav->next;
        free(temp);
    }

    // delete entire linked list
    void deleteList()
    {
        while (head)
        {
            deleteFirstNode();
        }
    }

    // reverse list
    void reverse()
    {
        Node *prev = NULL;
        Node *curr = head;
        Node *next = head;

        while (curr)
        {
            next = next->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
    }
};

int main()
{
    LinkedList list;
    // list.addAtLast(30);
    // list.addAtLast(230);
    // list.display();
    // cout << "No of items in list are : " << list.count() << endl;
    // cout << "Is 35 present in list : " << list.search(35) << endl;
    // cout << "Is 30 present in list : " << list.search(30) << endl;

    // list.addAfterNode(10, 5);
    // list.addAfterNode(20, 10);
    // list.addAfterNode(15, 10);
    // list.addAfterNode(10, 5);

    // list.addBeforeNode(10, 30);
    // list.addBeforeNode(20, 10);
    // list.addBeforeNode(30, 10);
    // list.addBeforeNode(40, 10);
    // list.addBeforeNode(25, 30);
    // list.display();

    // list.addAtPososition(10, 0);
    // list.addAtPososition(30, 2);
    // list.addAtPososition(20, 10);
    // list.display();

    // list.addAtBegin(60);
    // list.deleteNode(50);
    // list.display();

    // list.display();
    // list.addAtBegin(50);
    // list.addAtBegin(40);
    // list.addAtBegin(30);
    // list.addAtBegin(20);
    // list.addAtBegin(10);
    // list.display();
    // list.deleteList();
    // list.display();

    // list.displayR(list.head);
    list.display();
    list.reverse();
    list.display();
}