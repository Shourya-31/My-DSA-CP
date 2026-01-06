// Solution

#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        vector<int> A(n),B(n);
        for(int i=0; i<n; i++){
            cin>>A[i];
        }

        int mx = *max_element(A.begin(),A.end());
        int mn = *min_element(A.begin(), A.end());

        int C = mn + mx;

        for(int i=0; i<n; i++){
            B[i] = C - A[i];
        }

        for(int x : B){
            cout<<x<<" ";
        }
        cout<<endl;
    }
    return 0;
}