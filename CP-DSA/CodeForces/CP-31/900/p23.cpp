#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (auto &it : a)
            cin >> it;

        long long total_and = a[0];
        for (auto &it : a)
            total_and &= it;
        
        cout << total_and << "\n";
    }
}