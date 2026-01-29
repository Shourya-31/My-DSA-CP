#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll t;
    cin >> t;

    while (t--)
    {
        ll n, k;
        cin >> n >> k;

        vector<ll> a(n);
        vector<pair<ll, ll>> v;

        // Adjust the health points to determine the effective health after damage
        for (ll i = 1; i <= n; i++)
        {
            ll a;
            cin >> a;

            ll rem = a % k;
            // If the remainder is 0, set it to k to handle full damage cases
            if (rem == 0)
                rem = k;

            v.push_back({rem, i});
        }
        // Sort the monsters based on effective health and index
        // Sort in descending order of effective health, and ascending order of index if health is the same
        sort(v.begin(), v.end(), [](auto &x, auto &y)
             {
            if(x.first == y.first) return x.second < y.second;
            return x.first > y.first; });

        for (auto &it : v)
            cout << it.second << " ";
        cout << endl;
    }
}