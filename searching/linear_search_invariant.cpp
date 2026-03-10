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

    int key;
    cout << "Enter element to search: ";
    cin >> key;

    bool found = false;
    cout << "\nLinear Search Steps (Loop Invariant: key not found in previous elements):\n";
    for (int i = 0; i < n; i++)
    {
        cout << "Checking index " << i << ": " << arr[i];
        if (arr[i] == key)
        {
            cout << " -> Found!";
            found = true;
        }
        cout << endl;

        if (found) break;
    }

    if (!found)
        cout << "\nElement not found in array.\n";

    return 0;
}
