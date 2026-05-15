#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, k;
        cin >> n >> k;

        vector<ll> a(n);

        for (auto &it : a)
            cin >> it;

        sort(a.begin(), a.end());

        vector<ll> pref(n+1, 0);

        for(int i=0; i<n; i++){
            pref[i+1] = pref[i] + a[i];
        }



        ll total = pref[n];

        ll ans = 0;

        for (int x = 0; x <= k; x++)
        {
            ll sum = total;

            // remove 2*x smallest
           sum -= pref[2*x];

            // remove (k-x) largest
           sum -= (pref[n] - pref[n - (k-x)]);

            ans = max(ans, sum);
        }

        cout << ans << endl;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}