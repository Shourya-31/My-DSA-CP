#include<bits/stdc++.h>
using namespace std;
using ll = long long;

long long factorial(int n) {
    unsigned long long fact = 1;
    for (int i = 2; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

// long long nCr(int n, int r) {
//     if (r < 0 || r > n) return 0; 
//     unsigned long long numerator = factorial(n);
//     unsigned long long denominator = factorial(r) * factorial(n - r);
//     return numerator / denominator;
// }

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n,k,q;
        cin>>n>>k>>q;
        vector<ll> a(n);
        for(auto &it : a)cin>>it;

        ll ans = 0;
        ll len = 0;

        for(ll i = 0; i < n; i++){
            if(a[i] <= q){
                len++;
            }else{
                if(len >= k){
                    ll x = len - k + 1;
                    ans += x*(x+1)/2;
                }
                len = 0;
            }
        }

        if(len >= k){
            ll x = len - k + 1;
            ans += x*(x+1)/2;
        }

        cout<<ans<<endl;
    }
}