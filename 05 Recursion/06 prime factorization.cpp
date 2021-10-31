#include <iostream>
using namespace std;

void primeFactorization(int num, int counter = 2)
{
    if (num == 1)
        return;
    else
    {
        if (num % counter == 0)
        {
            cout << counter << " ";
            ::primeFactorization(num / counter);
        }
        else
        {
            ::primeFactorization(num, ++counter);
        }
    }
}

int main()
{
    int num;
    cout << "Enter any number : ";
    cin >> num;
    ::primeFactorization(num);
    cout << endl;
}