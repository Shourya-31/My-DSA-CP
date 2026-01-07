// Understanding:
// Initially he has some string, then he performs an operation on it
// Adding 1 & 0 to the ends of the string
// Means to get the length of shortest string
// We need to deduct 0s & 1s simoultaneaously from both sides of string
// After doing that, when the moment comes that there is no 0s & 1s left simoultaneaously
// Which means, either both ends contain 0s or 1s
// Then that will be our answer

// Solution
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        string s;
        cin>>s;

        while(s.front() != s.back() && s.size() > 1){
            s.pop_back();
            s.erase(0,1);
        }

        cout<<s.size()<<endl;
    }
    return 0;
}