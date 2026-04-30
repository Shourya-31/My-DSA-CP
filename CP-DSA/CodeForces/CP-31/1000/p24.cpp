#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, m;
        cin >> n >> m;
        vector<vector<ll>> a(n, vector<ll>(m));
        for (ll i = 0; i < n; i++)
        {
            for (ll j = 0; j < m; j++)
            {
                cin >> a[i][j];
            }
        }

        // for (int i = 0; i < n; i++)
        // {
        //     for (int j = 0; j < m; j++)
        //     {

        //         // Upper adjacent
        //         if (i - 1 >= 0)
        //         {
        //             if (a[i - 1][j] < 0)
        //             {
        //                 a[i - 1][j] = -a[i - 1][j]; // Make it positive
        //             }
        //         }

        //         // Lower adjacent
        //         if (i + 1 < n)
        //         {
        //             if (a[i + 1][j] < 0)
        //             {
        //                 a[i + 1][j] = -a[i + 1][j]; // Make it positive
        //             }
        //         }
        //     }
        // }

        // ll X = 0;
        // for(auto &it: a){
        //     for(auto &jt: it){
        //         X += jt;
        //     }
        // }

        ll negatives = 0;
        ll mins = INT_MAX;
        ll sum = 0;

        for(ll i = 0; i < n; i++){
            for(ll j = 0; j < m; j++){
                if(a[i][j] < 0){
                    negatives++;
                }
                mins = min(mins, abs(a[i][j]));
                sum += abs(a[i][j]);
            }
        }

        if (negatives % 2 == 0)
			cout << sum << endl;
		else
			cout << sum - 2 * abs(mins) << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}