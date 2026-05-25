#include <bits/stdc++.h>
using namespace std;

using ll = long long;

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

        int l = 0, r = n - 1;

        for (int i = 0; i < n; i++)
        {
            if (a[i] != b[i])
            {
                l = i;
                break;
            }
        }

        for (int i = n - 1; i >= 0; i--)
        {
            if (a[i] != b[i])
            {
                r = i;
                break;
            }
        }

        while (l > 0 && b[l - 1] <= b[l])
            l--;

        while (r < n - 1 && b[r] <= b[r + 1])
            r++;

        cout << l + 1 << " " << r + 1 << endl;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}