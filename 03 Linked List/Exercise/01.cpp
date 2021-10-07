// 01 write functiotn to count occurances of number in linked list

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
        addFirst(10);
        addFirst(70);
        addFirst(80);
        addFirst(60);
        addFirst(10);
        addFirst(10);
        addFirst(20);
        addFirst(40);
        addFirst(90);
        addFirst(100);
    }

    // add at first
    void addFirst(int data)
    {
        Node *temp = new Node(data);
        temp->next = head;
        head = temp;
    }

    // count occurances
    int occurances(int data)
    {
        int counter = 0;
        Node *trav = head;
        while (trav)
        {
            if (trav->info == data)
                counter++;
            trav = trav->next;
        }
        return counter;
    }
};

int main()
{
    LinkedList list;
    cout << "occurance of no 10 is : " << list.occurances(10) << " times " << endl;
}