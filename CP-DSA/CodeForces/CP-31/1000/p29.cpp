#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll a, b;
        cin >> a >> b;

        ll ra = a;
        ll rb = b;

        while (ra % 2 == 0)
            ra /= 2;
        while (rb % 2 == 0)
            rb /= 2;

        if (ra != rb){
            cout << -1 << endl;}
        else{
            a /= ra;
            b /= rb;

            a = log2(a);
            b = log2(b);

            ll ans = ceil(abs(a - b)/3.0);
            cout << ans << endl;

        }

        // if (a == b)
        // {
        //     cout << 0 << endl;
        // }

        // ll ops = 0;

        // // to check if the nums belong to -1 category
        // bool flag = false;

        // while (a != b)
        // {
        //     if (a > b)
        //     {
        //         a /= 2;
        //         ops++;
        //     }
        //     else if (a < b)
        //     {
        //         b /= 2;
        //         ops++;
        //     }
        //     if (a == b)
        //     {
        //         break;
        //     }
        //     flag = true;
        // }

        // if (flag)
        // {
        //     cout << ops << endl;
        // }
        // else
        // {
        //     cout << -1 << endl;
        // }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}