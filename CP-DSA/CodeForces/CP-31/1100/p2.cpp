#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;

        vector<ll> a(n);
        for (auto &it : a)
            cin >> it;

        vector<ll> b(n);
        for (auto &it : b)
            cin >> it;

        // ll count_quests = 0;
        // ll XP = 0;

        // for (ll i = 0; i < k; i++)
        // {
        //     XP += a[i];
        //     count_quests++;
        //     if (i == n)
        //     {
        //         for (ll j = n; j < k; j++)
        //         {
        //             XP += b[i];
        //             count_quests++;
        //         }
        //     }

        //     if(count_quests == k)
        //         break;
        // }

        // cout << XP << "\n";

        ll maxi = 0;
        ll sum = 0;
        ll ans = 0;
        for (ll i = 0; i < min(n, k); i++)
        {
            sum += a[i];
            maxi = max(maxi, b[i]);
            ans = max(ans, sum + (k - i - 1) * maxi);
        }

        cout << ans << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}