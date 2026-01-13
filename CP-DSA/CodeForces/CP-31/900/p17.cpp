// Solution
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;

    while(t--){
        long long n;
        cin>>n;

        vector<long long> arr(n);
        bool same = false;
        for(int i=0; i<n; i++){
            cin>>arr[i];
        }

        for(int i=0; i<n-1; i++){
            if(arr[i] == arr[i+1]){
                same = true;
            }else{
                same = false;
            }
        }

        if(same){
            cout<<0<<endl;
        }

        int ops = 0;

        unordered_map<long long,long long> freq;
        long long max_freq = 0;

        for(long long x : arr){
            freq[x]++;
            max_freq = max(max_freq, freq[x]);
        }

        while(max_freq < n){
            ops++;
        long long use = min(max_freq,n - max_freq);
            ops += use;
            max_freq += use;
        }
        cout<<ops<<endl;
    }
    return  0;
}