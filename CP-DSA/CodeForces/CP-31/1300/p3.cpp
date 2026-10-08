#include <iostream>
#include <vector>
#include <map>
using namespace std;

#define int long long

void solve()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<int> a(n);

        for (auto &x : a)
            cin >> x;

        bool exists = false;

        map<int, int> mp;

        // Prefix sum before taking any element
        mp[0] = 1;

        int sum = 0;

        for (int i = 0; i < n; i++)
        {
            if (i % 2 == 0)
                sum += a[i];
            else
                sum -= a[i];

            // If this prefix sum appeared before,
            // the subarray between those two positions
            // has equal odd/even sums.
            if (mp[sum] > 0)
            {
                exists = true;
                break;
            }

            mp[sum]++;
        }

        if (exists)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}