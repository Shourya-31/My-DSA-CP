#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;

    while(t--){
        long long n,k;
        cin>>n>>k;

        vector<long long> a(n*k);
        for(auto &it : a) cin>>it;

        sort(a.begin(), a.end());
        long long pointer = n*k;

        long long sum = 0;
        while(k--){
            pointer -= (n/2 +1);
            sum += a[pointer];
        }
        cout<<sum<<"\n";
    }
}