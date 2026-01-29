#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        vector<int> p(n);
        vector<bool> used(n + 1, false);

        p[n - 1] = 1;
        used[1] = true;

        for (int i = n - 1; i >= 1; --i)
        {
            bool found = false;
            for (int val = 1; val <= n; ++val)
            {
                if (!used[val] && abs(val - p[i]) % i == 0)
                {
                    p[i - 1] = val;
                    used[val] = true;
                    found = true;
                    break;
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            cout << p[i] << (i == n - 1 ? "" : " ");
        }
        cout << endl;
    }
    return 0;
}