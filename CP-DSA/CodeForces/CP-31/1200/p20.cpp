#include <bits/stdc++.h>
using namespace std;

using ll = long long;

bool isPallindrome(string s)
{
    ll i = 0, j = s.length() - 1;

    while (i < j)
    {
        if (s[i] != s[j])
        {
            return false;
        }

        i++;
        j--;
    }

    return true;
}

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

        ll ans = n + 1;
        for (ll c = 0; c < 26; ++c)
        {
            ll l = 0, r = n - 1, count = 0;
            while (l <= r)
            {
                // If both characters match, keep them and move inward
                if (s[l] == s[r])
                {
                    l++, r--;
                }
                // If left character is the one we're trying to delete
                else if (s[l] == char('a' + c))
                {
                    count++, l++;
                }
                // If right character is the one we're trying to delete
                else if (s[r] == char('a' + c))
                {
                    count++, r--;
                }
                // Neither side can be deleted -> impossible for this character
                else
                {
                    count = n + 1;
                    break;
                }
            }
            ans = min(ans, count);
        }

        if (ans == n + 1)
            ans = -1;
        cout << ans << endl;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}