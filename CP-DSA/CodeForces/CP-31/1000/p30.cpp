#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    // Array is good if for each pair of indexes i<j
    // the condition j−aj≠i−ai holds.
    // j - aj != i - ai is the core condition
    // we will use loop ans swap for this

    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vector<ll> a(n);
        for (auto &it : a)
            cin >> it;

        sort(a.rbegin(), a.rend());

        for (auto &it : a)
            cout << it << " ";
        cout << endl;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}