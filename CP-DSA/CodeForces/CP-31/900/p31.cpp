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

        long long i = 0;
        while (n != 1)
        {
            if (n % 6 == 0)
            {
                n /= 6;
            }
            else if (n % 3 == 0)
            {
                n *= 2;
            }
            else
            {
                cout << -1 << endl;
                break;
            }

            i++;
        }

        if (n == 1)
        {
            cout << i << endl;
        }
    }
}