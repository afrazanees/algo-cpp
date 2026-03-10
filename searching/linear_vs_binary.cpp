#include <iostream>
using namespace std;

int linearSearch(int arr[], int n, int key, int &ops)
{
    for (int i = 0; i < n; i++)
    {
        ops++;
        if (arr[i] == key)
            return i;
    }
    return -1;
}

int binarySearch(int arr[], int n, int key, int &ops)
{
    int low = 0, high = n - 1;
    while (low <= high)
    {
        ops++;
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

    int key;
    cout << "Enter element to search: ";
    cin >> key;

    int ops1 = 0, ops2 = 0;

    linearSearch(arr, n, key, ops1);
    binarySearch(arr, n, key, ops2);

    cout << "\nLinear Search Operations: " << ops1 << endl;
    cout << "Binary Search Operations: " << ops2 << endl;

    return 0;
}
