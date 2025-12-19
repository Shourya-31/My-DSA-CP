// Binary String Problem
// Print all Binary Strings of size N such that there are no consecutive 1's
// For example, for N = 3, the valid binary strings are:
// 000
// 001
// 010
// 100
// 101

// Base case:
// N = 0 => ""
// N = 1 => "0", "1"

// Recursive Relation:
// We need to track the last placed character
// If last placed character is '0', we can place either '0' or '1' at the current position
// If last placed character is '1', we can only place '0' at the current

// F(n, lastPlace, ans)
// if(lastPlace != 1) {
// F(n-1,0,ans+'0')
// F(n-1,1,ans+'1')
// } else {
// F(n-1,0,ans+'0')
// }

#include <bits/stdc++.h>
using namespace std;

void binString(int n, int lastPlace, string ans) {
    if(n == 0){
        cout<<ans<<endl;
        return;
    }

    if(lastPlace != 1){
        binString(n-1, 0, ans + '0');
        binString(n-1, 1, ans + '1');
    }else{
        binString(n-1,0,ans + '0');
    }
}

int main(){
    int n;
    cin>>n;
    string ans = "";
    binString(n, 0, ans);
    return 0;
}