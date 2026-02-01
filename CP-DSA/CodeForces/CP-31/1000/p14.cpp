#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// https://codeforces.com/problemset/problem/1691/B

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        ll n;
        cin >> n;

        vector<ll> s(n);
        for (auto &it : s)
            cin >> it;

        map<ll, ll> freq;
        for (int i = 0; i < n; i++)
            freq[s[i]]++;

        bool flag = false;
        vector<int> ans(n);

        for (auto &i : freq)
        {
            if (i.second == 1)
            {
                flag = true;
                break;
            }
        }

        if (flag)
        {
            cout << -1 << "\n";
            continue;
        }

        // create permutation array separately (DON'T overwrite sizes)
        vector<int> perm(n);
        for (int i = 0; i < n; i++)
            perm[i] = i + 1;

        ll l = 0, r = 0;

        while (r < n)
        {
            if (s[l] == s[r])
            {
                r++;
            }
            else
            {
                rotate(perm.begin() + l, perm.begin() + l + 1, perm.begin() + r);
                l = r;
            }
        }

        rotate(perm.begin() + l, perm.begin() + l + 1, perm.begin() + r);

        for (auto &it : perm)
            cout << it << " ";

        cout << "\n";
    }
}
