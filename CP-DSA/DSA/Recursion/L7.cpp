// Question: Print X to the power N using recursion
// Time Complexity: log(n)
// We will half the power at each step
#include <iostream>
using namespace std;

int pow(int x, int n) {
    if(n == 0) {
        return 1;
    }
    int halfPower = pow(x,n/2);
    int halfPowerSq = halfPower * halfPower;

    if(n%2 != 0) {
        // If n is odd
        return halfPowerSq = x * halfPowerSq;
    }
    return halfPowerSq;
}

int main() {
    int x, n;
    cin>>x>>n;
    int ans = pow(x, n);
    cout<<ans;
    return 0;
}