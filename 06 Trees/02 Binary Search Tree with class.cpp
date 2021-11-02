#include <iostream>
using namespace std;

class Node
{
public:
    int info;
    Node *lChild;
    Node *rChild;
    Node(int data)
    {
        info = data;
        rChild = nullptr;
        lChild = nullptr;
    }
};

class BTree
{
public:
    Node *root;
    BTree()
    {
        this->root = nullptr;
        int arr[] = {67, 34, 80, 12, 45, 78, 95, 38, 60, 79};
        for (int i = 0; i < 10; i++)
            this->root = this->insert_itr(this->root, arr[i]);
        this->inOrder(this->root);
        cout << endl;
    }
    void inOrder(Node *ptr)
    {
        if (ptr == NULL)
            return;
        this->inOrder(ptr->lChild);
        cout << ptr->info << "  ";
        this->inOrder(ptr->rChild);
    }
    Node *insert_itr(Node *ptr, int data)
    {
        if (ptr == nullptr)
        {
            return new Node(data);
        }
        else
        {
            if (data < ptr->info)
            {
                ptr->lChild = this->insert_itr(ptr->lChild, data);
            }
            else
            {
                ptr->rChild = this->insert_itr(ptr->rChild, data);
            }
            return ptr;
        }
    }
    void insert(int data)
    {
        if (this->root == nullptr)
        {
            this->root = new Node(data);
        }
        else
        {
            Node *trav = root;
            while (trav)
            {
                if (data < trav->info)
                {
                    if (trav->lChild == nullptr)
                    {
                        trav->lChild = new Node(data);
                        break;
                    }
                    trav = trav->lChild;
                }
                else
                {
                    if (trav->rChild == nullptr)
                    {
                        trav->rChild = new Node(data);
                        break;
                    }
                    trav = trav->rChild;
                }
            }
        }
    }
};

int main()
{
    BTree *tree = new BTree();
}