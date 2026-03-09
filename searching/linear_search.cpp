#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter array size (max 100): ";
    cin >> n;
    if (n > 100) n = 100; // restrict for simplicity

    int arr[100];
    cout << "Enter array elements:\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int key;
    cout << "Enter element to search: ";
    cin >> key;

    int index = -1;

    // Linear Search
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == key)
        {
            index = i; // element found at index i
            break;
        }
    }

    if (index != -1)
        cout << "Element " << key << " found at index " << index << endl;
    else
        cout << "Element " << key << " not found in the array.\n";

    return 0;
}
