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
        int count = 0;
        sort(A.begin(),A.end());

        for(int i=0; i<n-1; i++){
            if(abs(A[i+1]-A[i]) > k){
                count++;
            }
        }

        cout<<count<<endl;

    }
}