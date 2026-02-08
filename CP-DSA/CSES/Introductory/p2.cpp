#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll n;
    cin >> n;

    vector<ll> a(n - 1);
    for (auto &it : a)
    {
        cin >> it;
    }

    sort(a.begin(), a.end());

    ll ans = 0;

    if (a[0] != 1)
    {
        cout << 1 << endl;
        return 0;
    }

    for (int i = 1; i < a.size(); i++)
    {
        if (a[i] - a[i - 1] > 1)
        {
            ans = a[i - 1] + 1;
            cout << ans << endl;
            return 0;
        }
    }

    cout << n << endl;
}