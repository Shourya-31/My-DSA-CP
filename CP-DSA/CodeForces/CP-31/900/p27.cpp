#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        long long n, x;
        cin >> n >> x;

        long long sum = 0;
        long long max_beauty = 0;
        vector<long long> a(n);
        for (auto &it : a){
            cin >> it;
            sum += it;
            max_beauty += (it + x - 1) / x;
        }
            
        vector<long long> b = a;
        long long min_beauty = (sum + x - 1) / x;
        cout<< min_beauty << " " << max_beauty << "\n";
    }
}