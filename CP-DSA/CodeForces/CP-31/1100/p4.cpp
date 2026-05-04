#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vector<ll> a(n);
        for (auto &it : a)
            cin >> it;

        ll curr = a[0];
        ll ans = a[0];

        for (ll i = 1; i < n; i++)
        {
            if (abs(a[i]) % 2 != abs(a[i - 1]) % 2)
            {
                curr = max(a[i], curr + a[i]);
            }
            else
            {
                curr = a[i];
            }
            ans = max(ans, curr);
        }
        cout << ans << "\n";
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}