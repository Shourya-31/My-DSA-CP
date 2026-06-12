#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const long long MOD = 1e9 + 7;

void solve()
{
    int t;
    cin >> t;

    while (t--)
    {
        ll n;
        cin >> n;

        // vector<ll> a(n);

        // for (auto &it : a)
        //     cin >> it;

        // Useful Info:
        // Num of demodogs in a cell is i*j
        // El kills all demodogs in the cell she visits
        // she can move right (i, j) -> (i, j+1) or down (i, j) -> (i+1, j)

        // To be calculated:
        // Max num of demodogs El can kill in a path from (1, 1) to (n, n)

        // Approach:
        // This can be solved with a greedy approach where El moves to the cell with the maximum number of demodogs at each step.

        // General term of this series with n=5:
        // 2(0+1+3+6+10) + (1^2 + 2^2 + 3^2 + 4^2)
        // sum from 1 to n 2*k(k-1)/2 + sum from 1 to n-1 k^2

        // Sum comes out to be:
        // n(n-1)(4n+1)/6

        ll ans = ans =
            (((n % MOD) * ((n + 1) % MOD)) % MOD *
             ((4 * n - 1) % MOD)) %
            MOD;

        //         Since n can be very large, we cannot directly compute
        //         n*(n+1)*(4*n-1)*2022 and then divide by 6.

        //         So we perform every multiplication modulo MOD.

        ans = (ans * 2022) % MOD;

        // divide by 6 modulo MOD
        ans = (ans * 166666668LL) % MOD;

        cout << ans << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}