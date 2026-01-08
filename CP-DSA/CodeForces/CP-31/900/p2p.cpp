#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;

    while(t--){
        int n,k;
        cin>>n>>k;

        string s;
        cin>>s;

        unordered_map<char,int> freq;

        for(char c : s){
            freq[c]++;
        }

        int odd = 0;

        for( auto &p : freq){
            if(p.second % 2 == 1){
                odd++;
            }
        }

        if(odd > k+1){
            cout<<"No"<<endl;
        }else{
            cout<<"Yes"<<endl;
        }
    }
}