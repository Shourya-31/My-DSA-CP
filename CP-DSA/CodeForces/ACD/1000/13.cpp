#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool isLucky(ll x)
{
    while (x > 0)
    {
        int d = x % 10;
        if (d != 4 && d != 7)
        {
            return false;
        }
        x /= 10;
    }
    return true;
}

int main()
{
    ll n;
    cin >> n;

    bool ok = false;
    for (int i = 1; i <= n; i++)
    {
        if (isLucky(i))
        {
            if (n % i == 0)
            {
                ok = true;
                break;
            }
        }
    }

    cout << (ok ? "YES\n" : "NO\n");
}