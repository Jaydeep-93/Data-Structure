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
        rChild = NULL;
        lChild = NULL;
    }
};

// recursive inOrder traversal
void inOrder(Node *ptr)
{
    if (ptr == NULL)
        return;
    else
    {
        ::inOrder(ptr->lChild);
        cout << ptr->info << "  ";
        ::inOrder(ptr->rChild);
    }
}

// recursive insert
Node *insert(Node *ptr, int key)
{
    if (ptr == nullptr)
        return new Node(key);
    else
    {
        if (key < ptr->info)
            ptr->lChild = ::insert(ptr->lChild, key);
        else
            ptr->rChild = ::insert(ptr->rChild, key);
        return ptr;
    }
}

// Non-recursive insert
Node *insert_itr(Node *root, int key)
{
    if (root == nullptr)
        return new Node(key);

    Node *trav = root;
    while (trav)
    {
        if (key < trav->info)
        {
            if (trav->lChild == nullptr)
            {
                trav->lChild = new Node(key);
                break;
            }
            trav = trav->lChild;
        }
        else
        {
            if (trav->rChild == nullptr)
            {
                trav->rChild = new Node(key);
                break;
            }
            trav = trav->rChild;
        }
    }
    return root;
}

// Recursive search
bool search(Node *ptr, int key)
{
    if (ptr == nullptr)
        return false;
    else
    {
        if (key < ptr->info)
            ::search(ptr->lChild, key);
        else if (key > ptr->info)
            ::search(ptr->rChild, key);
        else
            return true;
    }
}

// Non-recursive search
bool search_itr(Node *root, int key)
{

    Node *trav = root;
    while (trav)
    {
        if (key < trav->info)
            trav = trav->lChild;
        else if (key > trav->info)
            trav = trav->rChild;
        else
            return true;
    }
    return false;
}

// find Node with min key
Node *findMin(Node *ptr)
{
    if (ptr == nullptr)
        return nullptr;
    if (ptr->lChild)
        return ::findMin(ptr->lChild);
    else
        return ptr;
}

// find node with Max key
Node *findMax(Node *ptr)
{
    if (ptr == nullptr)
        return nullptr;
    if (ptr->rChild)
        return ::findMax(ptr->rChild);
    else
        return ptr;
}

int main()
{
    int arr[] = {67, 34, 80, 12, 45, 78, 95, 38, 60, 79};
    Node *root = nullptr;
    for (int i = 0; i < 10; i++)
    {
        // root = ::insert(root, arr[i]);
        root = ::insert_itr(root, arr[i]);
    }

    ::inOrder(root);
    cout << endl;
    cout << "34 present : " << ::search(root, 34) << endl;
    cout << "34 present : " << ::search_itr(root, 34) << endl;

    cout << "Min value in tree is : " << ::findMin(root)->info << endl;
    cout << "Max value in tree is : " << ::findMax(root)->info << endl;
    cout << endl;
}