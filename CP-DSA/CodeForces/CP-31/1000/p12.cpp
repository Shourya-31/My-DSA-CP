#include<bits/stdc++.h>
using namespace std;

using ll = long long;
// https://codeforces.com/problemset/problem/1715/B
int main(){
    int t;
    cin>>t;
    while(t--){
        ll n,k,b,s;
        cin>>n>>k>>b>>s;

        // Idea No.1:- 0 0 0 0 k*b => beauty = b && min sum = k*b
        // Idea No.2:- If we add k-1 to every element then
        // the sum will drastically increase and so max sum = k*b + n*(k-1)
        // Adding more than k-1 will affect the beauty of array
        // Now:- we do given s - k*b  = s'
        // so the remaining s' can be reduced by distributing k-1 to the array
        // till s' is equal to 0

        ll min_s = k*b;
        ll max_s = (k*b) + n*(k-1);

        if(s < min_s || s > max_s){
            cout<<-1<<endl;
        }else{
            vector<ll> ans(n,0);
            ans[0] = min_s;
            s -= min_s;

            for(int i = 0; i < n; i++){
                ll add = min(k-1,s);
                ans[i] += add;
                s -= add;
            }

            for(ll i=0; i<n; i++){
                cout<<ans[i]<<" ";
            }
            cout<<endl;
        }
    }
}