#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
    ll t;
    cin>>t;

    while(t--){
        ll n;
        cin>>n;

        char c;
        cin>>c;

        string s;
        cin>>s;

        s+=s;
        n*=2;

        ll ans = INT_MIN;
        ll green_idx = -1;

        for(int i=n-1; i>=0; i--){
            if(s[i] == 'g'){
                green_idx = i;
            }
            if(s[i] == c){
                ll difference = green_idx - i;
                ans = max(ans,difference);
            }
        }

        cout<<ans<<endl;
    }
}