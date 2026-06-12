#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        vector<ll> a(n);

        for (auto &it : a)
            cin >> it;

        // ith tower has height hi
        // must choose a xi for each tower i and increase height by xi
        // Exactly ONCE

        // Goal:- To make all towers of equal height
        // O/P:- Min k to finish the game
        // Rule:- xi belongs to [1,k]

        vector<ll> x;
        ll max_ele = *max_element(a.begin(), a.end());

        for (auto &it : a)
        {
            x.push_back(max_ele - it);
        }

        ll x_maxi = *max_element(x.begin(), x.end());
        cout << x_maxi+1<< endl;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}