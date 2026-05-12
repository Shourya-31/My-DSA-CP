#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    ll t;
    cin >> t;

    while (t--)
    {
        ll n, k, a, b;
        cin >> n >> k >> a >> b;

        vector<ll> x(n + 1), y(n + 1);

        // Read the coordinates of each city
        for (int i = 1; i <= n; i++)
        {
            cin >> x[i] >> y[i];
        }

        ll ans = abs(x[a] - x[b]) + abs(y[a] - y[b]);

        // Initialize minimum costs from s to any major city and from t to any major city
        ll mins = 1e17, mint = 1e17;

        for (ll i = 1; i <= k; i++)
        {
            mins = min(mins, abs(x[a] - x[i]) + abs(y[a] - y[i]));
            mint = min(mint, abs(x[b] - x[i]) + abs(y[b] - y[i]));
        }

        ans = min(ans, mins + mint);

        cout << ans << endl;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}