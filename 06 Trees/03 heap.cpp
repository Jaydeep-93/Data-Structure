#include <iostream>
using namespace std;
#include <math.h>

int menuOperatin()
{
    int choice;
    cout << "0.Exit " << endl;
    cout << "1.Insert " << endl;
    cout << "2.Delete" << endl;
    cout << "3.Display" << endl;
    cout << "4.Build Heap" << endl;
    cout << "Enter your choice : ";
    cin >> choice;
    return choice;
}

#define MAX_VAL 999
void insert(int num, int arr[], int *p_hsize);
void del_root(int arr[], int *p_hsizse);
void restoreUp(int arr[], int size);
void restoreDown(int arr[], int size);
void buildHeap(int arr[], int size);
void display(int arr[], int size);

int main()
{
    int arr[100]; // This array will represent actual heap
    arr[0] = MAX_VAL;
    int p_hsizse = 0; // no of nodes currently in heap

    int choice;
    while ((choice = ::menuOperatin()) != 0)
    {
        switch (choice)
        {
        case 1:
            cout << "Enter any number to insert : ";
            // int num;
            // cin >> num;
            // ::insert(num, arr, &p_hsizse);
            // ::display(arr, p_hsizse);
            ::insert(90, arr, &p_hsizse);
            ::insert(70, arr, &p_hsizse);
            ::insert(80, arr, &p_hsizse);
            ::insert(24, arr, &p_hsizse);
            ::insert(59, arr, &p_hsizse);
            ::insert(45, arr, &p_hsizse);
            ::insert(12, arr, &p_hsizse);
            ::insert(14, arr, &p_hsizse);
            ::insert(10, arr, &p_hsizse);
            ::insert(38, arr, &p_hsizse);
            ::insert(46, arr, &p_hsizse);
            ::insert(32, arr, &p_hsizse);
            ::insert(37, arr, &p_hsizse);
            ::display(arr, p_hsizse);
            break;
        case 2:
            cout << "Delete" << endl;
            ::del_root(arr, &p_hsizse);
            ::display(arr, p_hsizse);
            break;
        case 3:
            cout << "Display" << endl;
            ::display(arr, p_hsizse);
            break;
        case 4:
            cout << "Build Heap" << endl;
            break;
        default:
            cout << "Enter valid choice ... " << endl;
            break;
        }
    }
}
void del_root(int arr[], int *p_hsize)
{
    arr[1] = arr[*p_hsize];
    (*p_hsize)--;
    ::restoreDown(arr, *p_hsize);
}
void restoreDown(int arr[], int size)
{
    int par = 1;
    while ((2 * par <= size) && ((2 * par + 1) <= size))
    {
        int childI = (arr[2 * par] > arr[(2 * par) + 1]) ? 2 * par : (2 * par + 1);
        if (arr[par] < arr[childI])
            swap(arr[par], arr[childI]);
        par = childI;
    }
    if (2 * par == size)
        if (arr[par] < arr[size])
            swap(arr[par], arr[size]);
}
void insert(int num, int arr[], int *p_hsizse)
{
    (*p_hsizse)++;
    arr[*p_hsizse] = num;
    ::restoreUp(arr, *p_hsizse);
}
void restoreUp(int arr[], int size)
{
    int i = size;
    int par = floor(i / 2);
    while (arr[par] < arr[i])
    {
        swap(arr[par], arr[i]);
        i = par;
        par = floor(par / 2);
    }
}
void display(int arr[], int size)
{
    if (size == 0)
    {
        cout << "Heap is empty ... " << endl;
        return;
    }
    else
    {
        cout << "heap : ";
        for (int i = 1; i <= size; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
}