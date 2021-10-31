#include <iostream>
using namespace std;

int digitSum(int num)
{
    if (num / 10 == 0)
        return num % 10;
    else
    {
        int sum = 0;
        sum = (num % 10) + digitSum(num / 10);
        return sum;
    }
}

int main()
{
    cout << "Enter any number : ";
    int n;
    cin >> n;
    cout << "Sum of Digit is : " << ::digitSum(n) << endl;
}