#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    int arr[100]; // Fixed-size array for simplicity
    cout << "Enter " << n << " elements:\n";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int comparisons = 0;
    int swaps = 0;

    // Selection Sort
    for(int i = 0; i < n - 1; i++) {
        int min_index = i;
        for(int j = i + 1; j < n; j++) {
            comparisons++; // Count each comparison
            if(arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        // Swap if a smaller element was found
        if(min_index != i) {
            int temp = arr[i];
            arr[i] = arr[min_index];
            arr[min_index] = temp;
            swaps++; // Count the swap
        }
    }

    cout << "\nSorted array in ascending order:\n";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    cout << "\n\nTotal comparisons: " << comparisons;
    cout << "\nTotal swaps: " << swaps << endl;

    cout << "\nTime Complexity Analysis (approx):\n";
    cout << "Best, Average, Worst case: O(n^2)\n";

    return 0;
}
