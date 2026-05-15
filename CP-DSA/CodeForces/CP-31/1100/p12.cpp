#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;


void solve()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<ll> a(n), b(n);

        for (auto &it : a)
            cin >> it;

        for (auto &it : b)
            cin >> it;

        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        ll ans = 1;

        for (int i = n - 1; i >= 0; i--)
        {
            int cnt = a.end() - upper_bound(a.begin(), a.end(), b[i]);

            // upper_bound returns iterator
            // to first element strictly greater than b[i]
            cnt -= (n - 1 - i);
            //  (n - 1 - i)
            // Remove them from available choices.

                ans = (ans * max(0, cnt)) % MOD;
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