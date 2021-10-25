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
    Node *head = NULL;
    void display()
    {
        Node *trav = head;
        cout << " ---------------------" << endl;
        cout << "stack is : " << endl;
        while (trav)
        {
            cout << trav->info << " --> ";
            trav = trav->next;
        }
        cout << " ---------------------" << endl;
        cout << endl;
    }
    void addAbegin(int data)
    {
        Node *temp = new Node(data);
        temp->next = head;
        head = temp;
    }
    void deleteFirst()
    {
        if (head)
            head = head->next;
    }
};

class stack
{
public:
    LinkedList list;

    void push(int data)
    {
        list.addAbegin(data);
    }
    void pop()
    {
        if (!isEmpty())
            list.deleteFirst();
    }
    int peek()
    {
        if (!isEmpty())
            return list.head->info;
    }

    bool isEmpty() { return list.head == NULL; }
};

int enterChoice()
{
    cout << "Enter choice of operation : " << endl;
    cout << "0. EXIT" << endl;
    cout << "1. PUSH" << endl;
    cout << "2. POP" << endl;
    cout << "3.PEEK" << endl;
    cout << "4. DISPLAY" << endl;

    int choice;
    cout << "Enter choice : ";
    cin >> choice;
    return choice;
};

int main()
{
    stack s;
    int choice;

    while ((choice = ::enterChoice()) != 0)
    {
        switch (choice)
        {
        case 1:
            cout << "Enter number to push : ";
            cin >> choice;
            s.push(choice);
            s.list.display();
            break;

        case 2:
            s.pop();
            s.list.display();
            break;

        case 3:
            cout << "peek element is  : " << s.peek() << endl;
            break;

        case 4:
            s.list.display();
            break;

        default:
            cout << "Enter valid choice ..." << endl ; 
            break;
         }
    }
}