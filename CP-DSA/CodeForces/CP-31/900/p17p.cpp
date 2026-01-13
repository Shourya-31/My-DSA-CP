#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        long long n;
        cin>>n;

       vector <long long> A(n);
       for(int i=0; i<n; i++){
        cin>>A[i];
       }
       long long curr = 1;
       long long max_freq = 1;

       sort(A.begin(),A.end());
       for(int i=1; i<n; i++){
        if(A[i] == A[n-1]){
            curr++;
        }else{
            curr = 1;
        }
        max_freq = max(max_freq, curr);
       }

       int ops = 0;
    
       while(max_freq < n){
        ops++;

        long long use = min(max_freq, n- max_freq);

        ops += use;
        max_freq += use;
       }
       cout<<ops<<endl;
    }
    return 0;
}