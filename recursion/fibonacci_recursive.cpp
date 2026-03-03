#include <iostream>
using namespace std;

// Recursive function to compute nth Fibonacci number
int fibonacci(int n)
{
    if (n == 0) // Base case: F(0) = 0
        return 0;
    else if (n == 1) // Base case: F(1) = 1
        return 1;
    else
        return fibonacci(n - 1) + fibonacci(n - 2); // Recursive call
}

int main()
{
    int n;
    cout << "Enter the position n (non-negative integer): ";
    cin >> n;

    if (n < 0)
    {
        cout << "Fibonacci number is not defined for negative numbers.\n";
        return 0;
    }

    int result = fibonacci(n);
    cout << "The " << n << "th Fibonacci number is: " << result << endl;

    return 0;
}
