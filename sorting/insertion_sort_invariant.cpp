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

    cout << "\nInsertion Sort Steps:\n";
    for (int i = 1; i < n; i++)
    {
        // Loop invariant: Elements arr[0..i-1] are sorted
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;

        cout << "After inserting element " << i + 1 << ": ";
        printArray(arr, n);
    }

    cout << "\nSorted Array: ";
    printArray(arr, n);

    return 0;
}
