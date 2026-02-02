#include<bits/stdc++.h>
using namespace std;

using ll = long long;
// https://codeforces.com/problemset/problem/1632/B
int main(){
    int t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;

        n--;
        ll  msb = log2(n);
        vector<ll> p;
        ll num = pow(2, msb) - 1;
        while(num >= 0){
            p.push_back(num);
            num--;
        }
        num = pow(2,msb);
        while(num <= n){
            p.push_back(num);
            num++;
        }

        for(auto &it : p){
            cout<<it<<" ";
        }
        cout<<endl;

    }
}