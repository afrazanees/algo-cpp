#include <iostream>
using namespace std;

int linearSearch(int arr[], int n, int key, int &operations)
{
    for (int i = 0; i < n; i++)
    {
        operations++; // count each comparison
        if (arr[i] == key)
        {
            return i; // element found
        }
    }
    return -1; // element not found
}

int main()
{
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    int arr[1000];

    // Fill array with simple values
    for (int i = 0; i < n; i++)
    {
        arr[i] = i + 1;
    }

    int key;
    int operations;

    // -------- Best Case (element at first position) --------
    key = arr[0];
    operations = 0;
    linearSearch(arr, n, key, operations);
    cout << "\nBest Case (Element at first position):" << endl;
    cout << "Operations: " << operations << endl;

    // -------- Average Case (element at middle position) --------
    key = arr[n / 2];
    operations = 0;
    linearSearch(arr, n, key, operations);
    cout << "\nAverage Case (Element at middle position):" << endl;
    cout << "Operations: " << operations << endl;

    // -------- Worst Case (element not in array) --------
    key = -1; // value not in array
    operations = 0;
    linearSearch(arr, n, key, operations);
    cout << "\nWorst Case (Element not in array):" << endl;
    cout << "Operations: " << operations << endl;

    return 0;
}
