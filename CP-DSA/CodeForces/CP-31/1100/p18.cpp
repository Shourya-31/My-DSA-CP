#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, k;
        cin >> n >> k;

        vector<ll> a(n);

        for (auto &it : a)
            cin >> it;

        vector<ll> cost(n);

        for (int i = 0; i < n; i++)
            cost[i] = a[i] + i + 1;

        sort(cost.begin(), cost.end());

        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            if (cost[i] <= k)
            {
                k -= cost[i];
                ans++;
            }
            else
                break;
        }

        cout << ans << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}