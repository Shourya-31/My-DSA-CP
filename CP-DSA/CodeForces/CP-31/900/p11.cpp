// Solution
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;

        vector<long long> arr(n);
        for(int i=0; i<n; i++){
            cin>>arr[i];
        }

        int count = 0;
        bool inSet = false;

        for(int i=0; i<n; i++){
            if(arr[i] != 0){
                if(!inSet){
                    count++;
                    inSet = true;
                }
            }else{
                inSet = false;
            }
        }
        cout<<min(count,2)<<endl;
    }
}