#include <iostream>
using namespace std;

void selectionSort(int arr[], int n, int &comparisons, int &swaps)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            comparisons++;
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        if (minIndex != i)
        {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
            swaps++;
        }
    }
}

int main()
{
    int n;
    cout << "Enter array size (max 100): ";
    cin >> n;
    if (n > 100) n = 100;

    int arr[100];

    cout << "Enter array elements:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int comparisons = 0, swaps = 0;

    selectionSort(arr, n, comparisons, swaps);

    cout << "\nSelection Sort Analysis:" << endl;
    cout << "Comparisons: " << comparisons << endl;
    cout << "Swaps: " << swaps << endl;

    return 0;
}
