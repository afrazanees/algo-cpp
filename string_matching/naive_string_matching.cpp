#include <iostream>
#include <string>
using namespace std;

int main()
{
    string text, pattern;
    
    cout << "Enter the text: ";
    getline(cin, text); // allows spaces
    
    cout << "Enter the pattern to search: ";
    getline(cin, pattern);

    int n = text.length();
    int m = pattern.length();
    bool found = false;

    cout << "\nPattern found at positions (0-based index): ";

    // Naive String Matching
    for (int i = 0; i <= n - m; i++) // slide pattern over text
    {
        int j;
        for (j = 0; j < m; j++)
        {
            if (text[i + j] != pattern[j])
                break; // mismatch found
        }
        if (j == m)
        {
            cout << i << " "; // pattern found at index i
            found = true;
        }
    }

    if (!found)
        cout << "Pattern not found in the text.";

    cout << endl;
    return 0;
}
