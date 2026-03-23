#include <iostream>
using namespace std;

// Partition function (Lomuto scheme)
int partition(int arr[], int low, int high) {
    int pivot = arr[high];  // Choose the last element as pivot
    int i = low - 1;        // Index of smaller element

    for(int j = low; j <= high - 1; j++) {
        if(arr[j] < pivot) {
            i++;
            // Swap arr[i] and arr[j]
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    // Swap arr[i + 1] and arr[high] (pivot)
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1; // Return pivot index
}

// Quick Sort function
void quickSort(int arr[], int low, int high) {
    if(low < high) {
        int pi = partition(arr, low, high); // Partitioning index

        quickSort(arr, low, pi - 1);  // Sort left part
        quickSort(arr, pi + 1, high); // Sort right part
    }
}

int main() {
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    int arr[100]; // Simple fixed-size array
    cout << "Enter " << n << " elements:\n";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    quickSort(arr, 0, n - 1);

    cout << "\nSorted array in ascending order:\n";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    cout << "\n\nTime Complexity Analysis:\n";
    cout << "Average Case: O(n log n)\n";
    cout << "Worst Case: O(n^2) (when array is already sorted or reverse sorted)\n";

    return 0;
}
