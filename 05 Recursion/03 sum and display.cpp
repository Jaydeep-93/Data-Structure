#include <iostream>
using namespace std;

int sum(int num)
{
    if (num == 0)
        return 0;
    else
    {
        int s = num + sum(num - 1);
        cout << num << "+ ";
        return s;
    }
}

int main()
{
    cout << "Enter any number : ";
    int n;
    cin >> n;
    int result = sum(n);
    cout << endl ; 
    cout << "Sum is : " << result;
    cout << endl;
}