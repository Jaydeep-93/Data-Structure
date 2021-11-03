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

// Delete Node in Binary Search Tree
Node *deleteNode(Node *root, int key);
// no child present for node ie leaf node
Node *case_a(Node *root, Node *parent, Node *ptr);
// only one child present for node
Node *case_b(Node *root, Node *parent, Node *ptr);
// both children are present for node
Node *case_c(Node *root, Node *par, Node *ptr);

// recursive delete function
Node *delete_recursive(Node *ptr, int key);

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
    // cout << "34 present : " << ::search(root, 34) << endl;
    // cout << "34 present : " << ::search_itr(root, 34) << endl;

    // cout << "Min value in tree is : " << ::findMin(root)->info << endl;
    // cout << "Max value in tree is : " << ::findMax(root)->info << endl;
    // cout << endl;

    int num;
    cout << "Enter value to enter : ";
    cin >> num;
    // root = ::deleteNode(root, num);
    root = ::delete_recursive(root, num);
    ::inOrder(root);
    cout << endl;
}

// recursive delete function
Node *delete_recursive(Node *ptr, int key)
{
    if (ptr == nullptr)
    {
        cout << "No " << key << " key found in treee " << endl;
        return nullptr;
    }
    if (key < ptr->info)
        ptr->lChild = ::delete_recursive(ptr->lChild, key);
    else if (key > ptr->info)
        ptr->rChild = ::delete_recursive(ptr->rChild, key);
    else
    {
        // key to be deleted found
        if (ptr->rChild && ptr->lChild)
        {
            // if both node exists
            Node *succ = ptr->rChild;
            while (succ->lChild)
                succ = succ->lChild;
            ptr->info = succ->info;
            ptr->rChild = ::delete_recursive(ptr->rChild, ptr->info);
        }
        else
        {
            // only one child
            if (ptr->lChild)
                ptr = ptr->lChild;
            else if (ptr->rChild)
                ptr = ptr->rChild;
            else // no child
                ptr = nullptr;
            return ptr;
        }
    }
}

// Delete Node in Binary Search Tree
Node *deleteNode(Node *root, int key)
{
    Node *parent = root;
    Node *ptr = root;
    while (ptr)
    {
        if (key == ptr->info)
            break;
        parent = ptr;
        if (key < ptr->info)
            ptr = ptr->lChild;
        else
            ptr = ptr->rChild;
    }

    if (ptr == nullptr) // key not present in tree
    {
        cout << key << "  Key not present in Tree " << endl;
        return root;
    }
    else if (ptr->lChild && ptr->rChild) // Both children are present in node
    {
        root = case_c(root, parent, ptr);
    }
    else if (ptr->rChild) // Only right child is present and left is null
    {
        root = case_b(root, parent, ptr);
    }
    else if (ptr->lChild) // obly left child is present and right is null
    {
        root = case_b(root, parent, ptr);
    }
    else // node to be deleted is leaf node ie both children are absent
        root = case_a(root, parent, ptr);
    return root;
}
// no child exists for node
Node *case_a(Node *root, Node *parent, Node *ptr)
{
    if (parent == root)
        root = nullptr;
    else
    {
        if (parent->lChild == ptr)
            parent->lChild = nullptr;
        else
            parent->rChild = nullptr;
    }
    return root;
}
// only one child exists for node wither left or right
Node *case_b(Node *root, Node *parent, Node *ptr)
{
    Node *child = nullptr;
    if (ptr->lChild)
        child = ptr->lChild;
    else
        child = ptr->rChild;

    if (parent == root)
        root = child;
    else if (parent->lChild == ptr)
        parent->lChild = child;
    else
        parent->rChild = child;
    return root;
}
// both children are present
Node *case_c(Node *root, Node *par, Node *ptr)
{
    Node *inParent = ptr;
    Node *inSucc = ptr->rChild;
    while (inSucc->lChild)
    {
        inParent = inSucc;
        inSucc = inSucc->lChild;
    }
    ptr->info = inSucc->info;
    if (inSucc->rChild && inSucc->lChild)
        root = case_a(root, inParent, inSucc);
    else
        root = case_b(root, inParent, inSucc);
    return root;
}