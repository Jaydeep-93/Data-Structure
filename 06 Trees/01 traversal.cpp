#include <iostream>
using namespace std;
#include <stack>
#include <queue>

class Node
{
public:
    char info;
    Node *rchild;
    Node *lChild;
    Node(char data)
    {
        info = data;
        rchild = NULL;
        lChild = NULL;
    }
};

// Recursive
void preOrder(Node *ptr)
{
    if (ptr == nullptr)
        return;
    else
    {
        cout << ptr->info << " ";
        ::preOrder(ptr->lChild);
        ::preOrder(ptr->rchild);
    }
}
void inOrder(Node *ptr)
{
    if (ptr == NULL)
        return;
    else
    {
        ::inOrder(ptr->lChild);
        cout << ptr->info << " ";
        ::inOrder(ptr->rchild);
    }
}
void postOrder(Node *ptr)
{
    if (ptr == NULL)
        return;
    else
    {
        ::postOrder(ptr->lChild);
        ::postOrder(ptr->rchild);
        cout << ptr->info << " ";
    }
}

// Non-Recursive
void preOrder_itr(Node *root)
{
    if (root == NULL)
        return;
    else
    {
        stack<Node *> stack;
        stack.push(root);

        while (!stack.empty())
        {
            Node *ptr = stack.top();
            stack.pop();
            cout << ptr->info << " ";

            if (ptr->rchild != NULL)
                stack.push(ptr->rchild);
            if (ptr->lChild != NULL)
                stack.push(ptr->lChild);
        }
    }
}

void inOrder_itr(Node *root)
{
    if (root == NULL)
        return;
    else
    {
        stack<Node *> stack;
        Node *ptr = root;
        while (!stack.empty() || ptr != NULL)
        {
            if (ptr != NULL)
            {
                stack.push(ptr);
                ptr = ptr->lChild;
            }
            else
            {
                ptr = stack.top();
                stack.pop();
                cout << ptr->info << " ";
                ptr = ptr->rchild;
            }
        }
    }
}

void postOrder_itr(Node *root)
{
    if (!root)
        return;
    else
    {
        stack<Node *> s;
        s.push(root);
        stack<char> out;
        while (!s.empty())
        {
            Node *ptr = s.top();
            s.pop();
            out.push(ptr->info);
            if (ptr->lChild)
                s.push(ptr->lChild);
            if (ptr->rchild)
                s.push(ptr->rchild);
        }
        while (!out.empty())
        {
            cout << out.top() << " ";
            out.pop();
        }
    }
}

// Level Order traversal
void levelOrder(Node *root)
{
    if (!root)
        return;
    else
    {
        queue<Node *> q;
        q.push(root);
        while (!q.empty())
        {
            Node *ptr = q.front();
            q.pop();
            cout << ptr->info << " ";
            if (ptr->lChild)
                q.push(ptr->lChild);
            if (ptr->rchild)
                q.push(ptr->rchild);
        }
    }
}

int main()
{
    Node *root = new Node('A');
    root->lChild = new Node('B');
    root->lChild->lChild = new Node('D');
    root->lChild->rchild = new Node('E');
    root->lChild->rchild->lChild = new Node('H');
    root->lChild->rchild->rchild = new Node('I');
    root->rchild = new Node('C');
    root->rchild->lChild = new Node('F');
    root->rchild->rchild = new Node('G');
    root->rchild->rchild->lChild = new Node('J');

    // Recursive
    // cout << "preOrder   : ";
    // ::preOrder(root);
    // cout << endl;

    // cout << "inOrder    : ";
    // ::inOrder(root);
    // cout << endl;

    // cout << "postOrder  : ";
    // ::postOrder(root);
    // cout << endl;

    // Non_recursive
    // cout << "preOrder   : ";
    // ::preOrder_itr(root);

    // cout << "inOrder    : ";
    // ::inOrder_itr(root);
    // cout << endl;

    // cout << "postOrder  : ";
    // ::postOrder_itr(root);
    // cout << endl;

    cout << "Level Order  : ";
    ::levelOrder(root);
    cout << endl;
}