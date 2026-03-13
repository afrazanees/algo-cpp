#include <iostream>
using namespace std;

int main() {
    int n;

    cout << "Enter the number of elements in the array: ";
    cin >> n;

    int arr[100]; // Simple fixed-size array for beginners
    cout << "Enter " << n << " elements:\n";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int comparisons = 0;
    int swaps = 0;

    // Bubble Sort
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            comparisons++; // Counting comparisons
            if(arr[j] > arr[j + 1]) {
                // Swap the elements
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swaps++; // Counting swaps
            }
        }
    }

    cout << "\nSorted array in ascending order:\n";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    cout << "\n\nTotal comparisons: " << comparisons;
    cout << "\nTotal swaps: " << swaps << endl;

    return 0;
}
