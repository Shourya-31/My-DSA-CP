// https://codeforces.com/problemset/problem/1704/B
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
// Thought process:-
// The ai must be in the range of [ai-x,ai+x]
// We will play in intersections, meaning that
// if the v value is satisfying multiple intersections we wont change it
// Intersection formula = [max(l1,l2), min(r1,r2)]

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

        ll ans = 0;
        vector<pair<ll,ll>> intersections(n);
        for(int i=0; i<n; i++){
            intersections[i] = {a[i] - x, a[i] + x};
        }

        ll l = intersections[0].first;
        ll r = intersections[0].second;

        for(int i=1; i<n; i++){
            l=max(l,intersections[i].first);
            r=min(r,intersections[i].second);

            if(l > r){
                ans++;
                l = intersections[i].first;
                r = intersections[i].second;
            }
        }
        // ll v = x;

        // bool good = true;
        // for (int i = 0; i < n; i++)
        // {
        //     ll newL = a[i] - x;
        //     ll newR = a[i] + x;

        //     if (abs(v - a[i]) <= x)
        //     {
        //         good = true;
        //         continue;
        //     }
        //     else
        //     {
        //         good = false;
        //         ans++;
        //         ll L = max(L, newL);
        //         ll R = min(R, newR);
        //     }
        // }

        cout << ans << endl;
    }
}
// TC:- O(n)