#include <iostream>
#include <string>
using namespace std;

int main()
{
    string text, pattern;

    cout << "Enter the main string: ";
    getline(cin, text);  // allows spaces

    cout << "Enter the substring to search: ";
    getline(cin, pattern);

    int n = text.length();
    int m = pattern.length();
    bool found = false;

    // Brute-force substring search
    for (int i = 0; i <= n - m; i++)
    {
        int j;
        for (j = 0; j < m; j++)
        {
            if (text[i + j] != pattern[j])
            {
                break; // mismatch, move to next position
            }
        }
        if (j == m)
        {
            found = true;
            break; // substring exists
        }
    }

    if (found)
        cout << "Substring exists in the string.\n";
    else
        cout << "Substring does not exist in the string.\n";

    return 0;
}
