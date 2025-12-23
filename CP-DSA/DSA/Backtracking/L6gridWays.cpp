// Find number of ways to reach from (0,0) to (n-1,m-1) in a grid of size n x m
// Allowed moves- Right or Down

// Aproach: Recursion + Backtracking
// Recursively down waale ke liye call lagayenge aur right waale ke liye call lagayenge
// Then dono calls ke return values ko add kar denge

#include <bits/stdc++.h>
using namespace std;

int gridWays(int r, int c, int n, int m){

    // Base Case
    if(r == n-1 && c == m-1){
        return 1;
    }
    if(r >= n || c >= m){
        return 0;
    }

    // Right
    int val1 = gridWays(r,c+1,n,m);

    // Down
    int val2 = gridWays(r+1,c,n,m);

    return val1 + val2;
}

int main(){
    int n,m;
    cout<<"Enter grid size (n x m): ";
    cin>>n>>m;

    cout<<gridWays(0,0,n,m)<<endl;

    return 0;
}
 
// Time Complexity: O(2^(n+m))
// Space Complexity: O(n+m) [Recursive Stack Space]