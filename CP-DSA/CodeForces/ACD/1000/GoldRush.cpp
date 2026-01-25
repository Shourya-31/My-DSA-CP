#include <bits/stdc++.h>
using namespace std;

bool canReach(int n, int m)
{
    if (n == m)
        return true;
    if (n < m)
        return false;
    if (n % 3 != 0)
        return false;

    return canReach(n / 3, m) || canReach(2 * n / 3, m);
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, m;
        cin >> n >> m;

        if (canReach(n, m))
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
}