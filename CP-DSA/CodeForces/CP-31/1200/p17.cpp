#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        ll x;
        cin >> n >> x;

        vector<ll> a(n);
        for (auto &v : a)
            cin >> v;

        sort(a.begin(), a.end());

        vector<ll> pref(n + 1, 0);

        for (int i = 1; i <= n; i++)
            pref[i] = pref[i - 1] + a[i - 1];

        ll ans = 0;
        ll days = 0;

        for (int i = n; i >= 1; i--) {
            ll cost = pref[i] + days * i;

            if (cost > x)
                continue;

            ll extra = (x - cost) / i + 1;

            ans += extra * i;
            days += extra;
        }

        cout << ans << '\n';
    }

    return 0;
}