#include <iostream>
using namespace std;

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

    // Check if array is sorted
    bool sorted = true;
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            sorted = false;
            break;
        }
    }

    if (!sorted)
    {
        cout << "Error: Array is not sorted. Binary Search cannot be performed.\n";
        return 0; // Stop program
    }

    int key;
    cout << "Enter element to search: ";
    cin >> key;

    int low = 0, high = n - 1;
    bool found = false;
    int mid;

    cout << "\nBinary Search Steps (Loop Invariant: key is within arr[low..high]):\n";
    while (low <= high)
    {
        mid = (low + high) / 2;
        cout << "Checking middle index " << mid << ": " << arr[mid] << endl;

        if (arr[mid] == key)
        {
            cout << "Element found at index " << mid << endl;
            found = true;
            break;
        }
        else if (arr[mid] < key)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }

        // Verify invariant
        cout << "Updated search range: arr[" << low << ".." << high << "]\n";
    }

    if (!found)
        cout << "Element not found in array.\n";

    return 0;
}
