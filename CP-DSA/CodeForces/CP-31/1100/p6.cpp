#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    ll t; 
    cin >> t;

    while(t--){
        ll n, q; 
        cin >> n >> q;

        vector<ll> v(n); 
        for(auto &it : v) cin >> it;

        vector<ll> u(q);
        for(auto &ut : u) cin >> ut;

        ll mini = 31;
        // mini stores the smallest x_i seen so far.

        for(ll i = 0; i < q; i++){

            if(u[i] < mini){

                ll add = (1LL << (u[i]-1));
                ll div = (1LL << u[i]);

                for(ll j = 0; j < n; j++){

                    if(v[j] % div == 0){
                        v[j] += add;
                    }

                }

                mini = u[i];
            }
        }

        for(auto &it : v){
            cout << it << " ";
        }

        cout << endl;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}