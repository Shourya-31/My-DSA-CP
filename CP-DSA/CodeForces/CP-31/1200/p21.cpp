#include <bits/stdc++.h>
using namespace std;

using in = long long;

void solve()
{
    // Find pairs i < j such that
    // a[i] * a[j] = i + j

    in t;
    cin >> t;

    while (t--)
    {
        in n;
        cin >> n;

        vector<pair<in,in>> a(n);

        for (in i = 0; i < n; i++)
        {
            cin >> a[i].first;
            a[i].second = i+1;
        }

        sort(a.begin(), a.end());

        in ans = 0;

        for (in i = 0; i <= n; i++)
        {
            for (in j = i + 1; j <= n; j++)
            {

                in product = a[i].first*a[j].first;
                if(product >= 2*n){
                    break;
                }
                if (product == a[i].second+a[j].second)
                {
                    ans++;
                }
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

    return 0;
}