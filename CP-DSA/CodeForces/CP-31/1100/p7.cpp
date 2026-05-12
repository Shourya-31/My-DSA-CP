#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool check(ll mid,vector<ll>&v,ll w){
    ll units=0; // how many units of water we require
    ll n = v.size();
    for(ll i=0; i<n; i++){
        if(v[i] < mid){ // then only we will have some water
            units += (mid - v[i]);
        }
    }
    if(units <= w){
        return true;
    }else{
        return false;
    }
    // return units <= w;
}

void solve()
{
    ll t;
    cin >> t;

    while (t--)
    {
        ll n, w;
        cin >> n >> w;

        vector<ll> v(n);
        for (auto &it : v)
            cin >> it;

        // okay so here we need an optimum h
        // it should be built such that all the water gets used
        // max water blocks is given

        // We will use Binary Search
        ll si = 1, ei = 1e12, ans = -1;
        while (si <= ei)
        {
            ll mid = si + (ei - si) / 2;
            if (check(mid, v, w))
            {
                ans = mid;
                si = mid + 1;
            }
            else
            {
                ei = mid - 1;
            }
        }
        cout << ans << endl;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}