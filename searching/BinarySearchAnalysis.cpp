#include <iostream>
using namespace std;

int binarySearch(int arr[], int n, int key, int &operations)
{
    int low = 0;
    int high = n - 1;

    while (low <= high)
    {
        operations++;
        int mid = (low + high) / 2;

        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int main()
{
    int n;
    cout << "Enter array size (max 100): ";
    cin >> n;
    if (n > 100) n = 100;

    int arr[100];

    cout << "Enter sorted array elements:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int operations;

    // Best Case (middle element)
    operations = 0;
    binarySearch(arr, n, arr[n/2], operations);
    cout << "\nBest Case Operations: " << operations << endl;

    // Average Case (first element)
    operations = 0;
    binarySearch(arr, n, arr[0], operations);
    cout << "Average Case Operations: " << operations << endl;

    // Worst Case (element not in array)
    operations = 0;
    binarySearch(arr, n, -999, operations);
    cout << "Worst Case Operations: " << operations << endl;

    return 0;
}
