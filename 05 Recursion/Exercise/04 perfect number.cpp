
#include <iostream>
using namespace std;

int isPerfect(int num, int counter = 1)
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
        sum += isPerfect(num, ++counter);
        return sum;
    }
}

int main()
{
    int num;
    cout << "Enter number : ";
    cin >> num;
    int result = ::isPerfect(num);
    if (result == num)
        cout << "perfect" << endl;
    else
        cout << "Not perfect" << endl;
}