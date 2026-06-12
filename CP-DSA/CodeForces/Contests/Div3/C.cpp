#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve()
{
    int t;
    cin >> t;

    while (t--)
    {
        int a, b, x;
        cin >> a >> b >> x;

        // Choose one of the integers a or b and add 1 to it
        // Choose one of the integers a or band divide it by x with rounding down.
        // Goal:- Find MINIMUM ops

        vector<ll> va, vb;

        // Generate all division states of a
        while (1)
        {
            va.push_back(a);
            // Once reached 0 further divisions stay 0
            if (!a)
                break;

            a /= x;
        }

        while (1)
        {
            vb.push_back(b);

            if (!b)
                break;

            b /= x;
        }

        ll ops = 1e18;

        for(ll i=0; i<va.size(); i++){
            for(ll j=0; j< vb.size(); j++){
                 ops = min(ops,
                      1LL * i + j + abs(va[i] - vb[j]));
                      // i + j + |va[i] - vb[j]| => Total cost
            }
        }

        cout << ops << endl;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}