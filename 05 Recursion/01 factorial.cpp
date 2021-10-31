#include <iostream>
using namespace std;

int factorial(int num);

int main()
{
    cout << "Enter any number : ";
    int num;
    cin >> num;
    cout << "factorail is : " << factorial(num) << endl;
    return 0;
}

int factorial(int num)
{
    if (num == 0)
        return 1;
    else
        return num * factorial(num - 1);
}