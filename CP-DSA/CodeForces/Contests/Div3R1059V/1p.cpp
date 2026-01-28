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

        vector<ll> prefSum(n);
        prefSum[0] = a[0];
        for (ll i = 1; i < n; i++)
        {
            prefSum[i] = prefSum[i - 1] + a[i];
        }

        ll max_avg = 0;
        ll sum = 0;

        for (ll l = 0; l < n; l++)
        {
            for (ll r = l; r < n; r++)
            {
                if(l==0){
                    sum = prefSum[r];
                }else{
                    sum = prefSum[r] - prefSum[l - 1];
                }
                ll deno = r - l + 1;

                ll avg = sum / deno;

                max_avg = max(max_avg,avg);
            }
        }

        cout<<max_avg<<endl;
    }
}