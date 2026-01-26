#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll s, n;
    cin >> s >> n;

    vector<pair<ll, ll>> dragons;

    while (n--)
    {
        ll x, y;
        cin >> x >> y;
        dragons.push_back({x, y});
    }

    sort(dragons.begin(), dragons.end());

    bool levelUp = true;

    for (auto &it : dragons)
    {
        ll x = it.first;
        ll y = it.second;

        if (s > x)
        {
            s += y;
        }
        else
        {
            levelUp = false;
            break;
        }
    }
    
    if (levelUp)
        cout << "YES\n";
    else
        cout << "NO\n";
}