// Solution
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        string s;
        cin>>s;
        int cur = 1;
        int mx = 1;

        for(int i=0; i<n; i++){
            if(s[i] == s[i-1]){
                cur++;
            }else{
                cur=1;
            }
            mx = max(mx,cur);
        }

         cout << mx + 1 << endl;
    }
}