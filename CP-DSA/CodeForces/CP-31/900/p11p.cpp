#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;

    while(t--){
        long long n;
        cin>>n;
        vector<long long> A(n);

        bool inSet = false;
        int count =0;

        for(int i=0; i<n; i++){
            cin>>A[i];

            if(A[i] != 0){
                if(!inSet){
                    count++;
                    inSet = true;
                }
            }else{
                inSet = false;
            }
        }

        cout<<min(2,count)<<endl;
    }
}