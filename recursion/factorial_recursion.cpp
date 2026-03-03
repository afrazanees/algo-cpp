#include <iostream>
using namespace std;

// Recursive function to calculate factorial
int factorial(int n)
{
    if (n == 0 || n == 1)  // Base case
        return 1;
    else
        return n * factorial(n - 1);  // Recursive call
}

int main()
{
    int n;
    cout << "Enter a non-negative integer: ";
    cin >> n;

    if (n < 0)
    {
        cout << "Factorial is not defined for negative numbers.\n";
        return 0;
    }

    int result = factorial(n);
    cout << "Factorial of " << n << " is: " << result << endl;

    return 0;
}
