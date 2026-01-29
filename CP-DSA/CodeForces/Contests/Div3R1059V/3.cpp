#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll t;
    cin >> t;

    while (t--)
    {
        ll a, b;
        cin >> a >> b;

        if (b > a)
        {
            cout << -1 << "\n";
            continue;
        }

        if (a == b)
        {
            cout << 0 << "\n";
            continue;
        }

        ll x = a ^ b;
        if (x <= a) {
            cout << 1 << "\n";
            cout << x << "\n";
        } else {
            cout << -1 << "\n";
        }
    }
}