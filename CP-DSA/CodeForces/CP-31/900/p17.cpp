// Solution
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        long long n;
        cin >> n;

        vector<long long> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        // Sort the array so that equal elements become consecutive
        // This allows counting frequencies without using a map
        sort(arr.begin(), arr.end());

        // Find the maximum frequency of any element
        long long max_freq = 1;    // At least one occurrence exists
        long long curr = 1;        // Frequency of current element

        for (int i = 1; i < n; i++)
        {
            if (arr[i] == arr[i - 1])
            {
                curr++;            // Same element continues
            }
            else
            {
                curr = 1;          // New element starts
            }

            // Track the highest frequency seen so far
            max_freq = max(max_freq, curr);
        }

        int ops = 0;               // Total operations required

        // Goal: make one copy where all n elements are equal
        // We already have 'max_freq' copies of the best element
        while (max_freq < n)
        {
            ops++;                 // One clone operation
                                   // Cloning doubles available copies conceptually

            // Number of elements we can convert in this round
            // Limited by:
            // 1) how many correct elements we already have (max_freq)
            // 2) how many more elements are still needed (n - max_freq)
            long long use = min(max_freq, n - max_freq);

            ops += use;            // Each conversion requires one swap
            max_freq += use;       // Increase count of correct elements
        }
        cout << ops << endl;
    }
    return 0;
}