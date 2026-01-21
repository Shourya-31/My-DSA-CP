#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin>>n;
        vector<long long> a(n);
        for (auto &it : a)
            cin >> it;

        long long count_of_ones = 0;
        long long count_of_zeroes = 0;
        for(auto &it : a){
            if(it == 1) count_of_ones++;
            else if(it == 0) count_of_zeroes++;
        }

        long long ans = pow(2,count_of_zeroes)*count_of_ones;
        cout<<ans<<"\n";
    }// Since 0 can either be included or not  there are 2^count_of_zeroes ways to choose 0s
     // and each of these ways can be paired with any of the count_of_ones 1s.
    return 0;
}