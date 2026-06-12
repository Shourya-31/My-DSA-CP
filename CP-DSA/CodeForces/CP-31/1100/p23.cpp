#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, l, r;
        cin >> n >> l >> r;

        vector<ll> a(n + 1);

        bool flag = true;
        for (int i = 1; i <= n; i++)
        {
            a[i] = ((l + i - 1) / i) * i;
            // ceiling(l / i)

            if (a[i] > r)
            {
                flag = false;
                break;
            }
        }
        // for (ll i = l; i <= r; ++i)
        // {
        //     for (ll j = i; j <= r; ++j)
        //     {
        //         if (__gcd(i, j) == 1)
        //         {
        //             a[i].push_back(j);
        //             // Store j as a number that is coprime with i
        //             // pairs[i].push_back(j);
        //         }
        //     }
        // }

        // auto coprime = [](long long a, long long b)
        // {
        //     return __gcd(a, b) == 1;
        // };

        // for (ll i = 1; i < n; i++)
        // {
        //     if (!coprime(i, a[i]))
        //     {
        //         flag = false;
        //         break;
        //     }
        // }

        if (flag)
        {
            cout << "YES" << endl;
            for (int i = 1; i <= n; i++)
            {
                cout << a[i] << " ";
            }
            cout << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}