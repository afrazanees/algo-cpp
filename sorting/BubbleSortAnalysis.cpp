#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n, int &comparisons, int &swaps)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            comparisons++;
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swaps++;
            }
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

    bubbleSort(arr, n, comparisons, swaps);

    cout << "\nBubble Sort Analysis:" << endl;
    cout << "Comparisons: " << comparisons << endl;
    cout << "Swaps: " << swaps << endl;

    return 0;
}
