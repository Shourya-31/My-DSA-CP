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

        ll X = -1;

        // for (ll i = 0; i < n; i++)
        // {
        //     for (ll j = 0; j < n; j++)
        //     {
        //          i = rand() % n;
        //          j = rand() % n;

        //          if(a[i]^a[j] == X){
        //             swap(a[i],a[j]);
        //          }
        //     }
        // }

        for (ll i = 0; i < n; i++)
        {
            // If the value is not equal to its index,
            // then this element is misplaced and must
            // participate in some swap.
            if (a[i] != i)
            {
                // First misplaced element encountered.
                if (X == -1)

                    // Start the AND value with this element.
                    X = a[i];
                else

                    // For every other misplaced element,
                    // keep taking bitwise AND.
                    X &= a[i];
            }
        }

        cout << X << endl;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}