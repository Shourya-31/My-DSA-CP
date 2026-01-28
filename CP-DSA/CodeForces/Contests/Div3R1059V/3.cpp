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
        // x1 will store the highest power of 2 that is <= a
        ll x1 = 1;
        // Keep left-shifting x1 (multiplying by 2)
        // until shifting once more would exceed a
        // After the loop, x1 = 2^k where 2^k <= a < 2^(k+1)
        while ((x1 << 1) <= a)
            x1 <<= 1;

        // XOR a with its highest set bit
        // This turns OFF the MSB of a
        // Resulting value a2 is strictly smaller than a
        ll a2 = a ^ x1;
        // We want final value to become b
        // Since a2 ^ x2 = b  ⇒  x2 = a2 ^ b
        // x2 will always be < x1, hence <= a2, so the operation is valid
        ll x2 = a2 ^ b;

        cout << 2 << "\n";
        cout << x1 << " " << x2 << "\n";
    }
}