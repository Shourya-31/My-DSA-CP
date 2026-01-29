#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll t;
    cin >> t;

    while (t--)
    {
        ll n;
        cin >> n;

        vector<ll> a(n), b(n);
        for (auto &it : a)
            cin >> it;
        for (auto &it : b)
            cin >> it;

        unordered_map<ll,ll> streak_A, streak_B;

        for(ll i=0; i<n;){
            ll j=i;
            while(j<n && a[j] == a[i]) j++;

            streak_A[a[i]] = max(streak_A[a[i]], j-i);
            i=j;
        }

        for (ll i = 0; i < n; )
        {
            ll j = i;
            while (j < n && b[j] == b[i]) j++;

            streak_B[b[i]] = max(streak_B[b[i]], j - i);
            i = j;
        }

        ll ans=0;

        for(auto &it : streak_A){
            ll val = it.first;
            ans = max(ans,streak_A[val]+streak_B[val]);
        }

        for(auto &it : streak_B){
            ll val = it.first;
            ans = max(ans, streak_A[val]+streak_B[val]);
        }

        cout<<ans<<endl;
    }
}