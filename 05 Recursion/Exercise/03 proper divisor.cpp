#include <iostream>
using namespace std;

int properDivisor(int num, int counter = 1)
{
    if (counter == num)
        return 0;
    else
    {
        int sum = 0;
        if (num % counter == 0)
        {
            sum += counter;
            cout << counter << " ";
        }
        return sum + ::properDivisor(num, ++counter);
    }
}

int main()
{
    cout << "Enter any number : ";
    int num;
    cin >> num;
    int result = properDivisor(num);
    cout << "result : " << result << endl;
}