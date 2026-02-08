#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ll n;
    cin>>n;

    ll n_copy = n;

    vector<ll> ans;

    while(n_copy != 1){
        if(n_copy % 2 == 0){
            n_copy /= 2;
            ans.push_back(n_copy);
        }else{
            n_copy *= 3;
            n_copy++;
            ans.push_back(n_copy);
        }
    }

    cout<<n<<" ";
    for(auto &x : ans){
        cout<<x<<" ";
    }
    cout<<endl;
}