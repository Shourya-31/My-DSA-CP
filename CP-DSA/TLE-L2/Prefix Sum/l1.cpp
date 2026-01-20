// Prefix Sum => A powerful technique that can be used to pre-process an array
// to facilitate fast sub-array sum queries without modifying the OG array.

// Example: Array: [1, 2, 3, 4, 5]
// Prefix Sum Array: [1, 3, 6, 10, 15]
// To find the sum of elements from index 1 to 3 (2 + 3 + 4):
// Sum = PrefixSum[3] - PrefixSum[0] = 10 - 1 = 9

// Example Code:

#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);

    for (auto &it : arr)
        cin >> it;

    int q;
    cin >> q;
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        int sum = 0;
        for (int i = l; i <= r; i++)
        {
            sum += arr[i];
        }
        cout << sum << " " << endl;
    }
}

// Time complexity: O(n*q)