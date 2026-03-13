#include <iostream>
using namespace std;

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void bubbleSortWithInvariant(int arr[], int n)
{
    cout << "\nInitial Array: ";
    printArray(arr, n);

    for (int i = 0; i < n - 1; i++)
    {
        // Loop invariant: 
        // After i-th pass, last i elements are sorted
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }

        // Verify loop invariant after each pass
        cout << "Array after pass " << i + 1 << " (last " << i + 1 << " elements sorted): ";
        printArray(arr, n);
    }
}

int main()
{
    int n;
    cout << "Enter array size (max 20 for easy display): ";
    cin >> n;

    if (n > 20) n = 20; // restrict size for display

    int arr[20];

    cout << "Enter array elements:\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    bubbleSortWithInvariant(arr, n);

    cout << "\nSorted Array: ";
    printArray(arr, n);

    return 0;
}
