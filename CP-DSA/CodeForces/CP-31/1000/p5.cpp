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

        for (ll i = 1; i <= n; i++)
        {
            ll a;
            cin >> a;

            ll rem = a % k;
            if (rem == 0)
                rem = k;

            v.push_back({rem, i});
        }

        sort(v.begin(), v.end(), [](auto &x, auto &y){
            if(x.first == y.first) return x.second < y.second;
            return x.first > y.first;
        });
        

        for (auto &it : v)
            cout << it.second << " ";
        cout << endl;
    }
}