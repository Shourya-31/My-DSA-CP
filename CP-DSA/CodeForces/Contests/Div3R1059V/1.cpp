#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vector<ll> a(n);

        for (auto &it : a)
            cin >> it;

        ll max_Avg = 0;
        ll sum = 0;

        vector<int> prefixSum(n);
        prefixSum[0] = a[0];
        for (int i = 1; i < n; i++)
            prefixSum[i] = prefixSum[i - 1] + a[i];

        for (ll l = 0; l < n; l++)
        {
            for (ll r = l; r < n; r++)
            {
                if (l == 0)
                    sum = prefixSum[r];
                else
                    sum = prefixSum[r] - prefixSum[l - 1];
                    
                ll len = r - l + 1;
                ll avg = sum / len;

                max_Avg = max(max_Avg, avg);
            }
        }

        cout << max_Avg << endl;
    }
}