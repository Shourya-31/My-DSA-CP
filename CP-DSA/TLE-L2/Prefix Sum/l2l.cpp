#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(n, vector<int>(m));
    vector<vector<int>> pref(n, vector<int>(m));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> v[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        {
            for (int j = 0; j < m; j++)
            {
                pref[i][j] = v[i][j];

                if (j > 0)
                {
                    pref[i][j] += pref[i][j - 1];
                }
                if (i > 0)
                {
                    pref[i][j] += pref[i - 1][j];
                }
                if (i > 0 && j > 0)
                {
                    pref[i][j] -= pref[i - 1][j - 1];
                }
            }
        }
    }

    int q;
    cin >> q;
    while (q--)
    {
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;

        int ans = pref[l2][r2];
        if (l1 > 0)
        {
            ans -= pref[l1 - 1][r2];
        }
        if (r1 > 0)
        {
            ans -= pref[l2][r1 - 1];
        }
        if (l1 > 0 && r1 > 0)
        {
            ans += pref[l1 - 1][r1 - 1];
        }

        cout << ans << " "<<endl;
    }
}

int main()
{
    solve();
}