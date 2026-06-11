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

        vector<ll> a(n);

        for (auto &it : a)
            cin >> it;

        ll ans_sum = 0;

        // for (int i = 1; i < n; i++)
        // {
        //     ll max_ele = max(a[i], a[i - 1]);
        //     ll min_ele = min(a[i], a[i - 1]);
        //     if (min_ele < 0)
        //     {
        //         max_ele = -max_ele;
        //         min_ele = -min_ele;
        //     }
        // }

        sort(a.begin(), a.end());


        vector<ll> b;
        for (ll i = 0; i < n; i++)
        {
            if (a[i] < 0)
            {
                b.push_back(i);
            }
        }

        ll min_ele = LLONG_MAX;

        for(ll i=0; i<n; i++){
            min_ele = min(min_ele, abs(a[i]));
        }

            for(ll i=0; i<n; i++){
                ans_sum += abs(a[i]);
            }
        

        if (b.size() % 2 != 0)
        {
            ans_sum -= 2 * min_ele;
        }
        // for (ll i = 1; i < b.size(); i++)
        // {
        //     if ((abs(a[b[i]]) > abs(a[b[i] - 1])) && (a[b[i]] < 0))
        //     {
        //         a[b[i]] = -a[b[i]];
        //     }
        //     else if ((abs(a[b[i]]) < abs(a[b[i] - 1])) && (a[b[i] - 1] < 0))
        //     {
        //         a[b[i] - 1] = -a[b[i] - 1];
        //     }
        // }

        cout << ans_sum << "\n";
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}