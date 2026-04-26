#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    ll t;
    cin >> t;

    while (t--)
    {
        ll n;
        cin >> n;
        string s;
        cin >> s;
        ll ans = 0;

        ll ops = 0;

        // ))))()
        // so if we have it like this,
        // then what can we do is if we encountern
        // ) this bracket in an index and in next too
        // then we will plus the answer by 2

        for (ll i = 0; i < n - 1; i++)
        {
            if (s[i] == ')')
            {
                ans--;
            }
            else if (s[i] == '(')
            {
                ans++;
            }
            if (ans < 0)
            {
                ops++;
                ans = 0;
            }
        }

        cout << ops << "\n";
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}