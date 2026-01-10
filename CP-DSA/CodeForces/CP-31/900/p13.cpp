// Solution
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<long long> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        long long ans = a[n - 1] - a[0];

        // Check the maximum difference between any element and the first element
        for (int i = 1; i < n; i++)
        {
            ans = max(ans, a[i] - a[0]);
        }
        
        // Check the maximum difference between the last element and any other element
        for (int i = 0; i < n - 1; i++)
        {
            ans = max(ans, a[n - 1] - a[i]);
        }

        // Check the maximum difference between consecutive elements
        for (int i = 0; i < n - 1; i++)
        {
            ans = max(ans, a[i] - a[i + 1]);
        }

        cout << ans << endl;
    }
}