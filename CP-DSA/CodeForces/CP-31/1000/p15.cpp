#include<bits/stdc++.h>
using namespace std;
using ll = long long;
// https://codeforces.com/problemset/problem/1690/D
int main(){
    int t;
    cin>>t;
    while(t--){
        ll n,k;
        cin>>n>>k;
        string s;
        cin>>s;

        vector<ll>prefix(n+1, 0);
        for(int i=0; i<n; i++){
            prefix[i+1] = prefix[i]+(s[i] == 'W');
        }

        ll min_cells = INT_MAX;
        for(int i=0; i<=n-k; i++){
            ll diff = prefix[i+k] - prefix[i];
            min_cells = min(min_cells, diff);
        }
        cout<<min_cells<<endl;
    }
}