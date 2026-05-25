#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve()
{
    int t;
    cin >> t;

    while (t--)
    {
        string s;
        cin >> s;

        int n = s.size();

        string a = s + s;

        ll cnt = 0;
        ll k = 0;

        for (char c : a)
        {
            if (c == '1')
            {
                cnt++;
                k = max(k, cnt);
            }
            else
            {
                cnt = 0;
            }
        }

        k = min(k, (ll)n);

        if (k == n)
        {
            cout << 1LL * n * n << '\n';
        }
        else
        {
            ll x = (k + 1) / 2;
            ll y = (k + 2) / 2;

            cout << x * y << '\n';
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}