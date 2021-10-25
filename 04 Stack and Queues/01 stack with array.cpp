#include <iostream>
using namespace std;

class stack
{
public:
    int top;
    int *stack_arr;
    int capacity;
    stack()
    {
        top = -1;
        stack_arr = new int[5];
        for (int i = 0; i < 5; i++)
            stack_arr[i] = -1;
        capacity = 5;
    }
    void push(int data)
    {
        if (!isFUll())
            this->stack_arr[++top] = data;
    }
    int peek()
    {
        if (!isEmpty())
            return this->stack_arr[top];
        else
            return -1;
    }
    void pop()
    {
        if (!isEmpty())
            stack_arr[top--] = -1;
    }

    bool isEmpty()
    {
        return top == -1;
    }
    bool isFUll()
    {
        return top == capacity - 1;
    }
    int size()
    {
        return top + 1;
    }
    // auxilary function
    void display()
    {
        cout << "---------------" << endl;
        for (int i = 0; i < capacity; i++)
        {
            cout << i << "      " << stack_arr[i] << endl;
        }
        cout << "---------------" << endl;
    }
};

int main()
{
    stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);

    s.pop();
    cout << s.peek() << endl ; 
    s.display();
}