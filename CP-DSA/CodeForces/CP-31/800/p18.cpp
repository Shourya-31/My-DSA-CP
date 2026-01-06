// Solution
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int x, k;
        cin >> x >> k;

        // If x is itself a valid jump
        if(x % k != 0){
            cout<<1<<endl;
            cout<<x<<endl;
        }
        // If x is divisible by k -> split
        else{
            cout<<2<<endl;
            cout<<x - 1<<" "<<1<<endl;
        }

    }
}