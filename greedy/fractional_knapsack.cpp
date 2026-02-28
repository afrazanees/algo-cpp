#include <iostream>
using namespace std;

// Structure to store item information
struct Item {
    int value;
    int weight;
    double ratio;
};

int main() {
    int n;
    cout << "Enter the number of items: ";
    cin >> n;

    if(n <= 0) {
        cout << "Number of items should be positive.\n";
        return 0;
    }

    Item items[100]; // Fixed-size array for simplicity

    // Input for each item
    for(int i = 0; i < n; i++) {
        cout << "\nItem " << i + 1 << ":\n";
        cout << "  Enter value: ";
        cin >> items[i].value;
        cout << "  Enter weight: ";
        cin >> items[i].weight;

        if(items[i].value < 0 || items[i].weight <= 0) {
            cout << "  Value must be non-negative and weight must be positive.\n";
            i--; // Ask input again for the same item
            continue;
        }

        items[i].ratio = (double)items[i].value / items[i].weight; // value-to-weight ratio
    }

    int capacity;
    cout << "\nEnter the capacity of the knapsack: ";
    cin >> capacity;

    if(capacity <= 0) {
        cout << "Knapsack capacity must be positive.\n";
        return 0;
    }

    // Sort items by value-to-weight ratio (simple selection sort)
    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            if(items[j].ratio > items[i].ratio) {
                Item temp = items[i];
                items[i] = items[j];
                items[j] = temp;
            }
        }
    }

    double totalProfit = 0.0;
    cout << "\nItems taken in the knapsack:\n";

    for(int i = 0; i < n; i++) {
        if(items[i].weight <= capacity) {
            totalProfit += items[i].value;
            capacity -= items[i].weight;
            cout << "  Taken full item with value " << items[i].value 
                 << " and weight " << items[i].weight << "\n";
        } else {
            double fraction = (double)capacity / items[i].weight;
            totalProfit += items[i].value * fraction;
            cout << "  Taken " << fraction*100 << "% of item with value " 
                 << items[i].value << " and weight " << items[i].weight << "\n";
            break; // Knapsack is full
        }
    }

    cout << "\nTotal profit in the knapsack: " << totalProfit << endl;
    return 0;
}
