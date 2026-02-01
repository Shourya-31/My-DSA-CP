#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        ll n, x;
        cin >> n >> x;

        vector<ll> a(n);
        for (auto &it : a)
            cin >> it;

        multiset<ll> ms;
        // stores current segment elements in sorted order
        // gives O(log n) insert
        // *begin()  -> min
        // *rbegin() -> max
        ll ans = 0; // number of times we must break segment

        for (int i = 0; i < n; i++)
        {
            ms.insert(a[i]); // add current element into current segment

            ll mini = *ms.begin(); // smallest value in segment
            ll maxi = *ms.rbegin(); // largest value in segment

            if (maxi - mini > 2 * x)
            // if spread too big, can't adjust within ±x
            // condition derived from:
            // |max - min| <= 2x  must hold
            {
                ans++; 
                ms.clear(); // discard previous segment
                ms.insert(a[i]); // start new segment from current element only
            }
        }

        cout << ans << "\n";
    }
}
