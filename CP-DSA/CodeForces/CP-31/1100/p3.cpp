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

        vector<pair<ll, ll>> v(n);
        for (ll i = 0; i < n; i++) {
            ll a;
            cin >> a;
            v[i] = {a, i}; 
        }

        sort(v.begin(), v.end());

        vector<ll> pre(n);
        pre[0] = v[0].first;
        for (ll i = 1; i < n; i++) {
            pre[i] = pre[i - 1] + v[i].first;
        }

        vector<ll> ans(n);

        for (ll i = 0; i < n; i++) {
            ll j = i;
            ll found = i;

            while (j < n) {
                pair<ll, ll> temp = {pre[j] + 1, LLONG_MIN};

                ll idx = lower_bound(v.begin(), v.end(), temp) - v.begin();

                if (idx == 0) break;  
                idx--;                 // move to last valid

                if (idx == j) break;   // no progress → stop

                found += (idx - j);    // extend segment
                j = idx;
            }

            ans[v[i].second] = found;
        }

        for (ll i = 0; i < n; i++) {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}