// Solution
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;

    while(t--){
        int n,k;
        cin>>n>>k;

        vector<int> A(n);
        for(int i=0; i<n; i++){
            cin>>A[i];
        }
        int count = 1;
        int largest_length = 1;
        sort(A.begin(),A.end());

        for(int i=1; i<n; i++){
            if(abs(A[i]-A[i-1]) <= k){
                count++;
            }else{
                count = 1;
            }

            largest_length = max(largest_length,count);
        }

        cout<<(n - largest_length)<<endl;

    }
}