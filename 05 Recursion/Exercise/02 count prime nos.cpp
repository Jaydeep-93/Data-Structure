#include <iostream>
using namespace std;
bool isPrime(int num)
{
    for (int i = 2; i < num; i++)
    {
        if (num % i == 0)
            return false;
    }
    return true;
}
int countPrime(int n1, int n2)
{
    if (n1 > n2)
        return 0;
    else
    {
        if (isPrime(n1))
        {
            cout << n1 << endl;
            return 1 + countPrime(n1 + 1, n2);
        }
        else
        {
            return countPrime(n1 + 1, n2);
        }
    }
}

int main()
{
    int n1, n2;
    cout << "Enter lower limit : ";
    cin >> n1;
    cout << "Enter upper limit : ";
    cin >> n2;

    int result = ::countPrime(n1, n2);
    cout << "count is : " << result << endl;
}