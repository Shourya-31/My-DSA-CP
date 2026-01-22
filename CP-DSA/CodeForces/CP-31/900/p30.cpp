#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;

    while(t--){
        string s;
        cin>>s;

        long long count_zeroes = 0;
        long long count_ones = 0;
        for(long long i = 0; i < s.size(); i++){
            if(s[i] == '0'){
                count_zeroes++;
            }else{
                count_ones++;
            }
        }

        long long ops= min(count_ones, count_zeroes);
        if(ops % 2 != 0){
            cout<<"DA\n";
        }else{
            cout<<"NET\n";
        }
    }
}