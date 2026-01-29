#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        string s;
        cin>>s;

        vector<int> right(26,0), left(26,0);

        int r_count = 0;
        for(char c : s){
            if(right[c - 'a'] == 0) r_count++;
            right[c-'a']++;
        }

        int l_count = 0;
        int ans = 0;

        for(int i=0; i<n-1; i++){
            if(left[s[i] - 'a'] == 0) l_count++;
            left[s[i] - 'a']++;

            right[s[i] - 'a']--;
            if(right[s[i] - 'a'] == 0) r_count--;

            ans = max(ans,l_count+r_count);
        }

        cout<<ans<<endl;

    }
}