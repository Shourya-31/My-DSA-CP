#include <bits/stdc++.h>
using namespace std;

using ll = long long;

// bool isPalindrome(const std::vector<ll> &vec)
// {
//     return std::equal(vec.begin(), vec.begin() + vec.size() / 2, vec.rbegin());
// }

void solve()
{
    int t;
    cin >> t;

    while (t--)
    {
        ll n;
        cin >> n;

        vector<ll> a(n);

        for (auto &it : a)
            cin >> it;

        // // We need to make pallindrom for biggest x
        // vector<ll> b(n);
        // ll x = 1;

        // for (ll i = 0; i < n; i++)
        // {
        //     b[i] = a[i];
        // }

        // ll i = 0;
        // while (!isPalindrome(b))
        // {
        //     b[i] = b[i] % x;
        //     i++;

        //     if (i == n && !isPalindrome(b))
        //         x++;

        //     i = 0;
        //     b = a;

        //     if (isPalindrome(b))
        //     {
        //         break;
        //     }
        // }

        // cout << x << endl;

        ll g = 0;

        for (int i = 0; i < n / 2; i++) {
            g = gcd(g, abs(a[i] - a[n - 1 - i]));
        }

        cout << g << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}