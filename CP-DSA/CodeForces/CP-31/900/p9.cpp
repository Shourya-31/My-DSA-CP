// Solution
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        vector<int> arr(n);
        for(int i=0; i<n; i++){
            cin>>arr[i];
        }

        int k = 0;
        for(int i = 0; i < n; i++){
            k = __gcd(k, abs(arr[i] - (i + 1)));
        }

        // Since we need to maximize k and ensure that k remains multiple for all arr[i]
        // Therefore we will make k = gcd(|arr[i]-(i+1)|)
        cout<<k<<endl;
    }
}