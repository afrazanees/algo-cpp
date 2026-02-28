#include <iostream>
using namespace std;

// Structure to store job information
struct Job {
    int id;
    int deadline;
    int profit;
};

int main() {
    int n;
    cout << "Enter the number of jobs: ";
    cin >> n;

    if(n <= 0) {
        cout << "Number of jobs must be positive.\n";
        return 0;
    }

    Job jobs[100]; // Fixed-size array for simplicity

    // Input for each job
    for(int i = 0; i < n; i++) {
        cout << "\nJob " << i + 1 << ":\n";
        cout << "  Enter job ID: ";
        cin >> jobs[i].id;
        cout << "  Enter deadline (in days): ";
        cin >> jobs[i].deadline;
        cout << "  Enter profit: ";
        cin >> jobs[i].profit;
    }

    // Sort jobs in descending order of profit (simple selection sort)
    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            if(jobs[j].profit > jobs[i].profit) {
                Job temp = jobs[i];
                jobs[i] = jobs[j];
                jobs[j] = temp;
            }
        }
    }

    // Find maximum deadline to size the schedule
    int maxDeadline = 0;
    for(int i = 0; i < n; i++) {
        if(jobs[i].deadline > maxDeadline)
            maxDeadline = jobs[i].deadline;
    }

    int slot[100] = {0}; // Array to keep track of free time slots
    int totalProfit = 0;

    cout << "\nScheduled jobs to maximize profit:\n";
    for(int i = 0; i < n; i++) {
        // Find a free slot for this job (start from its deadline)
        for(int j = min(maxDeadline, jobs[i].deadline); j > 0; j--) {
            if(slot[j] == 0) { // If slot is free
                slot[j] = jobs[i].id; // Assign job to this slot
                totalProfit += jobs[i].profit;
                cout << "  Job " << jobs[i].id << " scheduled at day " << j << " with profit " << jobs[i].profit << "\n";
                break;
            }
        }
    }

    cout << "\nTotal profit: " << totalProfit << endl;
    return 0;
}
