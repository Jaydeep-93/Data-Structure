#include <iostream>
using namespace std;

int power(int base, int expo)
{
    if (expo == 0)
        return 1;
    else
    {
        int pow = 1;
        pow = base * ::power(base, expo - 1);
        return pow;
    }
}

int main()
{
    cout << "Enter base :";
    int base;
    cin >> base;
    cout << "Enter exponent : ";
    int exponent;
    cin >> exponent;

    cout << "result of " << base << "^" << exponent << " : " << ::power(base, exponent) << endl;
}