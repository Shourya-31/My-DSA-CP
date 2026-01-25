#include <bits/stdc++.h>
using namespace std;

int main()
{

    int t;
    cin >> t;

    while (t--)
    {
        long long n, s, x;
        cin >> n >> s >> x;

        vector<long long> a(n);
        for (auto &it : a)
            cin >> it;

        long long sum = 0;
        for (auto &it : a)
            sum += it;

        bool good = true;

        while (sum != s)
        {
            sum += x;

            if (sum > s)
            {
                good = false;
                break;
            }
        }

        if (good)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
}