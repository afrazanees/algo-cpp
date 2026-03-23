#include <iostream>
using namespace std;

// Merge two sorted subarrays arr[l..m] and arr[m+1..r]
void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1; // size of first subarray
    int n2 = r - m;     // size of second subarray

    int left[100], right[100]; // Temporary arrays (for simplicity)

    // Copy data to temp arrays
    for(int i = 0; i < n1; i++)
        left[i] = arr[l + i];
    for(int j = 0; j < n2; j++)
        right[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;

    // Merge back into arr[l..r]
    while(i < n1 && j < n2) {
        if(left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
        } else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    // Copy remaining elements
    while(i < n1) {
        arr[k] = left[i];
        i++; k++;
    }
    while(j < n2) {
        arr[k] = right[j];
        j++; k++;
    }
}

// Merge Sort function
void mergeSort(int arr[], int l, int r) {
    if(l < r) {
        int m = l + (r - l) / 2; // Middle point
        mergeSort(arr, l, m);    // Sort first half
        mergeSort(arr, m + 1, r);// Sort second half
        merge(arr, l, m, r);     // Merge the two halves
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

    mergeSort(arr, 0, n - 1);

    cout << "\nSorted array in ascending order:\n";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    cout << "\n\nTime Complexity Analysis (approx):\n";
    cout << "Best, Average, Worst case: O(n log n)\n";

    return 0;
}
