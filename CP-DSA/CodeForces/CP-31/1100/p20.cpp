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

        // A Prefix Sum question
        // We will divide our array into 2 subsegments
        // Array b will contain m values if we divide array into m different subsegments
        // & gcd(b1, b2, b3, ... bm) <= gcd(b1+b2, b3, ... bm) <= gcd(b1+b2+b3, ... bm) <= ... <= gcd(b1+b2+...+bm)
        // since b1 & b2 are multiples of g
        // Therefore b1 + b2 will also be a multiple of g

        // ans_sum = gcd(pref_sum, total_sum - pref_sum)
        // maximum = max(ans, ans_sum)

        ll ans = 0;
        ll total_sum = accumulate(a.begin(), a.end(), 0LL);
        // The above line will give us the total sum of the array a
        ll pref_sum = 0;
        for(ll i=0; i<n-1; i++){
            pref_sum += a[i];
            ans = max(ans, __gcd(pref_sum, total_sum - pref_sum));
        }

        cout<<ans<<"\n";
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}