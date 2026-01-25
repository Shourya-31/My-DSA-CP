#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;

        vector<long long> a(n);
        for (auto &it : a)
            cin >> it;

        int l = -1;
        for (int i = 0; i < n; i++)
        {
            if (a[i] != n - i)
            {
                l = i;
                break;
            }
        }

        if (l == -1)
        {
            for (int x : a)
                cout << x << " ";
            cout << "\n";
            continue;
        }

        int r = l;
        long long mx = a[l];
        for (int i = l; i < n; i++)
        {
            if (a[i] > mx)
            {
                mx = a[i];
                r = i;
            }
        }

        reverse(a.begin() + l, a.begin() + r + 1);

        for (int x : a)
            cout << x << " ";
        cout << "\n";
    }
}