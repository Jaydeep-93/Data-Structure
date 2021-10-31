#include <iostream>
using namespace std;

int takeAndAddNumber()
{
    cout << "Enter no to ben enter : ";
    int n;
    cin >> n;
    if (n == 0)
        return 0;
    else
    {
        int sum = 0;
        sum = n + takeAndAddNumber();
        return sum;
    }
}

int main()
{
    cout << "result is : " << takeAndAddNumber() << endl;
}