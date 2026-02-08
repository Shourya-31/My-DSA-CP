#include<bits/stdc++.h>
using namespace std;
using ll =long long;

int main(){
    int t;
    cin>>t;

    while(t--){
        ll a,b;
        cin>>a>>b;
        ll ans = INT_MAX;

        for(int add = 0; add < 32; add++){
            ll ops = add;
            ll new_b = b+add;
            if(new_b == 1){
                continue;
            }

            ll copy_a = a;
            while (copy_a > 0)
            {
                copy_a /= new_b;
                ops++;
            }
            ans = min(ans,ops);
        }

        cout<<ans<<endl;
    }
}