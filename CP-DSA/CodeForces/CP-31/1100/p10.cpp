#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, x;
        cin >> n >> x;

        vector<int> a(n), b(n), c(n);

        for (auto &it : a) cin >> it;
        for (auto &it : b) cin >> it;
        for (auto &it : c) cin >> it;

        int u = 0;

        for (int i = 0; i < n; i++)
        {
            if ( (a[i] | x) == x )
                u |= a[i];
            else
                break;
        }

        for (int i = 0; i < n; i++)
        {
            if ( (b[i] | x) == x )
                u |= b[i];
            else
                break;
        }

        for (int i = 0; i < n; i++)
        {
            if ( (c[i] | x) == x )
                u |= c[i];
            else
                break;
        }

        cout << (u == x ? "YES" : "NO") << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}