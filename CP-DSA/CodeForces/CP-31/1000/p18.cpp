#include <bits/stdc++.h>
using namespace std;

using ll = long long;
// https://codeforces.com/problemset/problem/1620/B
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        ll w, h;
        cin >> w >> h;
        ll mx_area = 0;

        for (int i = 0; i < 4; i++)
        {
            ll k;
            cin >> k;

            ll first, last;

            for (int j = 0; j < k; j++)
            {
                ll x;
                cin >> x;
                if (j == 0)
                    first = x;
                if (j == k - 1)
                    last = x;
            }

            ll base = last - first;
            ll height;
            if (i <= 1)
            {
                height = h;
            }
            else
            {
                height = w;
            }

            mx_area = max(mx_area, base * height);
        }
        cout << mx_area << endl;
    }
    return 0;
}
