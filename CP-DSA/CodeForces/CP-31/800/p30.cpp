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

        int ans = 0;
        // Count numbers from 1 to 9
        ans = ans + min(n, 9);

        // Count numbers like 10, 20, 30 ... 100, 200 ...
        for (int p = 10; p <= n; p *= 10)
        {
            ans = ans + min(9, n / p);
            // But we must ensure: d * p <= n
            // => d <= n / p

            // So the actual count of valid numbers for this p is:
            // the minimum of:
            // 1) 9 (because digit d can be at most 9)
            // 2) n / p (because we cannot exceed n)
        }

        cout << ans << endl;
    }
}