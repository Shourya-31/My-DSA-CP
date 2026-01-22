#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        long long n, k;
        cin >> n >> k;

        vector<long long> v(n);
        for (auto &it : v)
            cin >> it;

        long long ans = INT_MAX;
        long long even_counts = 0;
        for (long long i = 0; i < n; i++)
        {
            if (v[i] % 2 == 0)
            {
                even_counts++;
            }
            if (v[i] % k == 0)
            {
                ans = 0;
            }
            ans = min(ans, (k - v[i] % k));
        }

        if (k == 4)
        {
            if (even_counts >= 2)
            {
                ans = min(ans, 0LL);
            }
            if (even_counts == 1)
            {
                ans = min(ans, 1LL);
            }
            if (even_counts == 0)
            {
                ans = min(ans, 2LL);
            }
        }
        cout << ans << endl;
    }

    return 0;
}
