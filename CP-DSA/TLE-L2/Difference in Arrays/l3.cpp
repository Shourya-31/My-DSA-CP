// Difference Arrays:

// A difference array can be used to perform multiple range updates
// where we need to find the final state of the arrays only after performing all the queries.
// Difference array helps us achieve the TC above in O(N) time total and space.
// We can process every range update in O(1)
// When we need to print our final answer, we perform an O(N) computation

// Example:
// An array filled with 0s initially,
// we have q queries of the form: L R x
// For each query, we need to add x to all elements from index L to R (both inclusive).
// After performing all the queries, we need to print the final state of the array.

#include <bits/stdc++.h>
using namespace std;

// Approach 1:
void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    int q;
    cin >> q;
    while (q--)
    {
        int l, r, x;
        cin >> l >> r >> x;
        for (int i = l; i <= r; i++)
        {
            v[i] += x;
        }
    }
} // TC: O(n*q) -- inefficient for large n and q

// Approach 2: Using Difference Array
// This approach works on the principle of prefix sums
// We will maintain a difference array diff[] which will store that by how much each index value will change
// Rule to update diff[] for each query L R x:
// diff[L] += x
// if(R + 1 < n) diff[R + 1] -= x;
// The real array can be obtained by taking prefix sum of diff[] array

void solve1()
{
    int n;
    cin >> n;

    // Original array
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    int q;
    cin >> q;

    // Difference array initialized with 0
    // Size n+1 is taken to safely handle r+1 updates
    vector<int> diff(n + 1, 0);

    while (q--)
    {
        int l, r, x;
        cin >> l >> r >> x;

        // Start adding x from index l
        diff[l] += x;

        // Stop adding x after index r
        // This cancels the effect beyond r
        if (r + 1 < n)
            diff[r + 1] -= x;
    }

    // Convert difference array into actual increments
    // by taking prefix sum
    for (int i = 1; i <= n; i++)
    {
        diff[i] += diff[i - 1];
    }

    // Apply the computed increments to original array
    for (int i = 0; i < n; i++)
    {
        v[i] += diff[i];
        cout << v[i] << " ";
    }
    cout << endl;
}
// TC: O(n + q)
// SC: O(n)