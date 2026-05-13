#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve()
{
    ll t;
    cin >> t;

    while (t--)
    {
        ll n, c;
        cin >> n >> c;

        vector<ll> s(n);

        for (auto &x : s)
            cin >> x;

        ll low = 1;
        ll high = 1e9;
        ll ans = 0;

        while (low <= high)
        {
            ll mid = (low + high) / 2;

            long long sum = 0;

            for (ll i = 0; i < n; i++)
            {
                ll side = s[i] + 2 * mid;

                sum += side * side;

                if (sum > c)
                    break;
            }

            if (sum == c)
            {
                ans = mid;
                break;
            }
            else if (sum < c)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
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