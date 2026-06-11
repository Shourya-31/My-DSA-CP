#include <bits/stdc++.h>
using namespace std;

using ll = long long;
vector<ll> pairs[1001];
// array of vector
// in pairs of i we store which num has gcd with i = 1
void solve()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<ll> idx(1001, 0);

        for (ll i=1; i<=n; ++i){
            int x;
            cin >> x;
            idx[x] = i;
        }

        // auto coprime = [](long long a, long long b) {
        //     return __gcd(a, b) == 1;
        // };

        // We will iterate from 1 to 1000
        // and will see if it has occured in the array
        // if it has occured then we will check if it is coprime with any other element in the array
        // then we will see max(ans, idx[i]+idx[x])

        ll ans = -1;
        for(ll i=1; i<=1000; ++i){
            if(idx[i] == 0){
                continue;
            }

            for(auto &j : pairs[i]){
                if(idx[j] != 0){
                    ans = max(ans, idx[i]+idx[j]);
                }
            }
        }

        cout<<ans<<"\n";

    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for(ll i=1; i<=1000; ++i){
        for(ll j=i; j<=1000; ++j){
            if(__gcd(i, j) == 1){
                // Store j as a number that is coprime with i
                pairs[i].push_back(j);
            }
        }
    }

    solve();
}