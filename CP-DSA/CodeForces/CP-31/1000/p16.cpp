#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int t;
    cin>>t;
    
    while(t--){
        ll n,r,b;
        cin>>n>>r>>b;
        string s;

        // Thought process:
        // We end up placing r/(b+1) r's beside every b
        // And the remaining r's will be distributed evenly
        // extra r's = r % (b+1)
        // Pigion Hole problem
        ll length_red = r/(b+1);
        ll extra_red = r%(b+1);

        for(int time=1; time<=b+1; time++){
            for(int i=0; i<length_red; i++){
                s +='R';
            }

            if(extra_red > 0){
                s += 'R';
                extra_red--;
            }

            if(time != b+1){
                s += 'B';
            }
        }
        cout<<s<<endl;
    }
}