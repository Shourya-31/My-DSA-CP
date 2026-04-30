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
        vector<ll> b(n);
        for (auto &it : b)
            cin >> it;

        // vector<ll> a(n);
        // for(auto &it:a) a[it] = 2^b[it];

        // In the first case, a=[16,8,1,2,4,1] Choosing l1=1
        // r1=1 l2=2 and r2=6 works because 16=(8+1+2+4+1)

        // bool ans = false;
        // ll window_sum1 = 0, window_sum2 = 0;
        // ll l1=0, r1=0, l2=0, r2=0;
        // // 1 ≤ l1 ≤ r1 < l2 ≤ r2 ≤ n

        unordered_set<ll> s;
        for (auto &it : b)
        {
            s.insert(it);
        }

        if (s.size() < n)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}