// Stack Overflow: 
// Arised due to excessive recursion depth leading to stack overflow.
// Causes:
// 1.) Too many local variables consuming stack space.
// 2.) Deep recursion without a proper base case.
// Prevention:
// 1.) Optimize the recursive function to reduce depth.
// 2.) Use tail recursion where possible.
// 3.) Increase stack size if necessary (platform dependent).

// Question:
// Sum of first n natural numbers using recursion
#include <iostream>
using namespace std;

int sum(int n){
    if(n == 0){
        return 0;
    }
    return n+sum(n-1);
}

int main() {
    int n;
    cin>>n;
    int ans = sum(n);
    cout<<ans;
    return 0;
}