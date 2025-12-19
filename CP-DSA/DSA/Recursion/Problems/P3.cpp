// Freinds Pairing Problem: Given n friends, each one can remain single or can be paired up with some other friend.
// Find the total number of ways in which friends can remain single or can be paired up.

// Basically a PnC problem but solved using Recursion here

// Approach:
// 1. If the nth friend remains single, we need to solve the problem for (n-1) friends
// 2. If the nth friend pairs up with any of the (n-1) friends, then we have (n-1) choices for that
// After pairing up nth friend with one of the (n-1) friends, we need to solve the problem for (n-2) friends

// Therefore, the Clarity must be:
// What work is being done in each recursive call?
// In each recursive call, we are reducing the problem size by either 1 or 2
// And the Base Case must be:
// If n == 1, return 1 (only one friend can remain single)
// If n == 2, return 2 (either both remain single or they pair up)

// Recursive Relation:
// F(n) = F(n-1) + (n-1) * F(n-2) => Taking solutions of both the cases

// Base Case:
// F(1) = 1
// F(2) = 2

#include <bits/stdc++.h>
using namespace std;

int friendsPairing(int n){
    // Base Case
    if(n == 1 || n == 2){
        return n;
    }
    //single friend
    int f1 = friendsPairing(n-1);
    //pairing friend
    int f2 = (n-1)*friendsPairing(n-2);

    return f1 + f2;
}

int main() {
    int n;
    cin>>n;
    cout<<"Total ways: "<<friendsPairing(n)<<endl;
}