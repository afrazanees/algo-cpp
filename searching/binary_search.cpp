#include <iostream>
using namespace std;

// Binary Search function using Divide and Conquer
int binarySearch(int arr[], int low, int high, int key) {
    if(low <= high) {
        int mid = low + (high - low) / 2; // Middle element

        if(arr[mid] == key)
            return mid; // Element found
        else if(arr[mid] > key)
            return binarySearch(arr, low, mid - 1, key); // Search left half
        else
            return binarySearch(arr, mid + 1, high, key); // Search right half
    }
    return -1; // Element not found
}

int main() {
    int n;
    cout << "Enter the number of elements in the sorted array: ";
    cin >> n;

    int arr[100]; // Simple fixed-size array
    cout << "Enter " << n << " elements in sorted order:\n";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int key;
    cout << "Enter the element to search: ";
    cin >> key;

    int result = binarySearch(arr, 0, n - 1, key);

    if(result != -1)
        cout << "Element " << key << " found at index " << result << ".\n";
    else
        cout << "Element " << key << " not found in the array.\n";

    cout << "\nTime Complexity Analysis:\n";
    cout << "Best Case: O(1) (element is at the middle)\n";
    cout << "Worst/Average Case: O(log n)\n";

    return 0;
}
