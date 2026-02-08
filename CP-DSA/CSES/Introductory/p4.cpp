#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ll n;
    cin>>n;
    vector<ll> a(n);
    for(auto &it : a)cin>>it;

    ll count = 0;
    for(int i=1; i<n; i++){
        if(a[i]<a[i-1]){
            count += a[i-1]-a[i];
            a[i] = a[i-1];
        }
    }

    cout<<count<<endl;
}