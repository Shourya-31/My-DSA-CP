#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        long long n, p;
        cin >> n >> p;
        vector<pair<long long, long long>> v(n);

        vector<long long> a(n);
        for (auto &it : a)
            cin >> it;

        vector<long long> b(n);
        for (auto &it : b)
            cin >> it;

        for (int i = 0; i < n; i++)
        {
            v[i] = {b[i], a[i]};
        }

        sort(v.begin(), v.end());

        long long min_cost = p;
        long long already_shared = 1;

        for (auto &it : v)
        {
            long long sharing_cost = it.first;
            long long can_be_shared = it.second;

            if (sharing_cost >= p)
                break;

            if (already_shared + can_be_shared > n)
            {
                min_cost += (n - already_shared) * sharing_cost;
                already_shared = n;
                break;
            }
            else
            {
                min_cost += can_be_shared * sharing_cost;
                already_shared += can_be_shared;
            }
        }

        min_cost += (n - already_shared) * p;
        cout << min_cost << endl;
    }
}