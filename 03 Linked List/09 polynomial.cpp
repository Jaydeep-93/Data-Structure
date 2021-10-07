#include <iostream>
using namespace std;

class Node
{
public:
    int coeff;
    int expo;
    Node *next;

    Node(int coeff, int expo)
    {
        this->coeff = coeff;
        this->expo = expo;
        this->next = NULL;
    }
};

class Polynomial
{
public:
    Node *head;

    Polynomial()
    {
        this->head = NULL;
    }

    // display function
    void display()
    {
        Node *trav = head;
        cout << "polynomial : ";
        while (trav)
        {
            cout << trav->coeff << " x^" << trav->expo << " + ";
            trav = trav->next;
        }
        cout << endl;
    }

    // create polynomial
    void createPolynomial()
    {
        int num;
        cout << "Enter number of terms for polynomial : ";
        cin >> num;
        for (int i = 0; i < num; i++)
        {
            int coeff, expo;
            cout << "Enter coefficient and exponenet : ";
            cin >> coeff >> expo;
            insertNode(coeff, expo);
        }
    }

    // create node element and insert at proper position on polynomial
    void insertNode(int coeff, int expo)
    {
        Node *temp = new Node(coeff, expo);
        if (head == NULL || head->expo <= temp->expo)
        {
            if (head && head->expo == temp->expo)
            {
                head->coeff += temp->coeff;
            }
            else
            {
                temp->next = head;
                head = temp;
            }
        }
        else
        {
            Node *trav = head;
            while (trav->next != NULL && trav->next->expo > temp->expo)
            {
                trav = trav->next;
            }
            if (trav->next && trav->next->expo == temp->expo)
            {
                trav->next->coeff += temp->coeff;
            }
            else
            {
                temp->next = trav->next;
                trav->next = temp;
            }
        }
    }

    // addition of polynomial
    void addPolyNomials(Node *p1, Node *p2)
    {
        while (p1 != NULL && p2 != NULL)
        {
            if (p1->expo > p2->expo)
            {
                this->insertNode(p1->coeff, p1->expo);
                p1 = p1->next;
            }
            else if (p2->expo > p1->expo)
            {
                this->insertNode(p2->coeff, p2->expo);
                p2 = p2->next;
            }
            else
            {
                this->insertNode(p1->coeff + p2->coeff, p1->expo);
                p1 = p1->next;
                p2 = p2->next;
            }
        }
        while (p1 != NULL)
        {
            this->insertNode(p1->coeff, p1->expo);
            p1 = p1->next;
        }
        while (p2 != NULL)
        {
            this->insertNode(p2->coeff, p2->expo);
            p2 = p2->next;
        }
    }

    // multiplication of polyniomial
    void multiPolynomials(Node *p1, Node *p2)
    {
        Node *trav = p2;
        while (p1)
        {
            p2 = trav;
            while (p2)
            {
                int coeff = p1->coeff * p2->coeff;
                int expo = p1->expo + p2->expo;
                insertNode(coeff, expo);

                p2 = p2->next;
            }
            p1 = p1->next;
        }
    }
};

int main()
{
    Polynomial poly1;
    poly1.createPolynomial();
    poly1.display();

    Polynomial poly2;
    poly2.createPolynomial();
    poly2.display();

    Polynomial result;
    //     result.addPolyNomials(poly1.head,poly2.head);
    //     cout << "List ";
    //     result.display();
    result.multiPolynomials(poly1.head, poly2.head);
    result.display();

    // Polynomial p;
    // p.insertNode(10, 2);
    // p.insertNode(10, 2);
    // p.insertNode(30, 1);
    // p.insertNode(30, 1);
    // p.insertNode(30, 1);
    // p.insertNode(30, 5);
    // p.insertNode(30, 5);

    // p.display();
}