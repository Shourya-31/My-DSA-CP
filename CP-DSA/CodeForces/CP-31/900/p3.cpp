// Solution
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        long long n, k, x;
        cin >> n >> k >> x;

        long long mn_sum = k * (k + 1) / 2;
        // From 0 to k
        long long mx_sum = k * (2 * n - k + 1) / 2;
//         Since numbers go up to n-1, the largest k are:
//         n-k+1, n-k+2, n-k+3, ... , n

        if(x >= mn_sum && x <= mx_sum){
            cout<<"YES\n";
        }else{
            cout<<"NO\n";
        }        
    }
    return 0;
}