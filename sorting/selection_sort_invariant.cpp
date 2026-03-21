#include <iostream>
using namespace std;

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int n;
    cout << "Enter array size (max 20): ";
    cin >> n;
    if (n > 20) n = 20;

    int arr[20];
    cout << "Enter array elements:\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "\nSelection Sort Steps:\n";
    for (int i = 0; i < n - 1; i++)
    {
        // Loop invariant: After i-th pass, first i elements are sorted
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }
        if (minIndex != i)
        {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }

        cout << "After pass " << i + 1 << ": ";
        printArray(arr, n);
    }

    cout << "\nSorted Array: ";
    printArray(arr, n);

    return 0;
}
