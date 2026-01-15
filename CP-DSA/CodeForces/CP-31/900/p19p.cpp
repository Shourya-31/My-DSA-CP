#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long x, n;
        cin >> x >> n;

        if (n == 0)
        {
            cout << x << endl;
            continue;
        }

        int r = n % 4;

        if (x % 2 == 0)
        {
            if (r == 0)
            {
                cout << x << endl;
            }
            else if (r == 1)
            {
                cout << x - n << endl;
            }
            else if (r == 2)
            {
                cout << x + 1 << endl;
            }
            else
            {
                cout << x + (n + 1);
            }
        }else{
            if (r == 0)
            {
                cout << x << endl;
            }
            else if (r == 1)
            {
                cout << x + n << endl;
            }
            else if (r == 2)
            {
                cout << x - 1 << endl;
            }
            else
            {
                cout << x - (n + 1);
            }
        }
    }
}