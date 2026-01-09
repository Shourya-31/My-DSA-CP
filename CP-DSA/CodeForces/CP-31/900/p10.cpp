// Solution
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        long long n, q;
        cin >> n >> q;

        vector<long long> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        long long old_sum = 0;
        for (int i = 0; i < n; i++)
        {
            old_sum += arr[i]; // This never changes because queries are independent
        }

        vector<long long> pref(n + 1, 0);
        for (int i = 1; i <= n; i++)
        {
            pref[i] = pref[i - 1] + arr[i - 1];
        }

        // Build prefix sums
        // a[i-1] because array is 0-indexed
        // Example:
        // prefix_sum[1] = a[0]
        // prefix_sum[2] = a[0] + a[1]

        while (q--)
        {
            long long l, r, k;
            cin >> l >> r >> k;
            // l to r → range to be replaced
            // k → value to replace with

            long long sum_to_remove = pref[r] - pref[l - 1];
            // Sum of elements currently in range [l, r]
            // This is what we are "removing" from old_sum

            long long sum_to_add = (r - l + 1) * k;
            // After replacement, each element becomes k
            // Number of elements = (r - l + 1)

            long long total_sum = old_sum - sum_to_remove + sum_to_add;

            if (total_sum % 2 == 1)
            {
                cout << "YES\n";
            }
            else
            {
                cout << "NO\n";
            }
        }
    }
    return 0;
}