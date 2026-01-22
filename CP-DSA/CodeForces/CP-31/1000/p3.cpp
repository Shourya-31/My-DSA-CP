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

        long long already_shared = 1;
        long long minimum_cost = p;

        // Populate the vector with pairs of (sharing cost, max shares)
        for (int i = 0; i < n; i++)
            v[i] = {b[i], a[i]};

        sort(v.begin(), v.end());

        for (auto &it : v)
        {
            // Max number of residents this resident can share with
            long long can_be_shared = it.second;
            // Cost for this resident to share
            long long sharing_cost = it.first;

            // If the sharing cost is greater than or equal to direct sharing cost, break
            if (sharing_cost >= p)
                break;

            if (already_shared + can_be_shared > n)
            {
                minimum_cost += (n - already_shared) * sharing_cost;
                already_shared = n; // All residents are informed
                break;
            }
            else
            {
                minimum_cost += can_be_shared * sharing_cost; // Add cost for sharing
                already_shared += can_be_shared; // Update the count of informed residents
            }
        }

        // Add the cost for the remaining residents to be informed directly
        minimum_cost += (n - already_shared) * p;
        cout << minimum_cost << endl;
    }
}