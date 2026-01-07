// Solution
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        vector<int> A(n);
        int zeroes = 0;
        int ones = 0;
       
        for(int i=0; i<n; i++){
            cin>>A[i];
            if(A[i] == 0){
                zeroes++;
            }else if(A[i] == 1){
                ones++;
            }
        }

        if(A[0] == 1 || A[n-1] == 1){
            cout<<"Alice"<<endl;
        }else{
            cout<<"Bob"<<endl;
        }

    }
}