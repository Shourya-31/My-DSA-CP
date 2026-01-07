// Solution
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;                 // Number of test cases

    while (t--)
    {
        int n;
        cin >> n;             // Size of the array

        int arr[n];
        int count = 0;        // Total count of '2's in the array

        // Input the array
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        // Count total number of 2s in the entire array
        for (int i = 0; i < n; i++)
        {
            if (arr[i] == 2)
            {
                count++;
            }
        }

        // Each prefix should contain half of total 2s
        int target = count / 2;

        int pref = 0;         // Prefix count of 2s

        // If total number of 2s is odd, we cannot split them equally
        if (count % 2 != 0)
        {
            cout << -1 << endl;
            continue;         // Move to next test case
        }
        else
        {
            // Traverse the array to find the first prefix
            // where prefix count of 2s becomes equal to target
            for (int i = 0; i < n; i++)
            {
                if (arr[i] == 2)
                {
                    pref++;   // Increase prefix count when we see a 2
                }

                // When prefix has exactly half of total 2s
                if (pref == target)
                {
                    cout << i + 1 << endl; // +1 because output is 1-based
                    break;                 // Stop at first valid prefix
                }
            }
        }
    }
}
