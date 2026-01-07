// Solution
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        int arr[n];
        int ops = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        bool unparity = false;

        for (int i = 0; i < n-1; i++)
        {
            if (arr[i] % 2 == 1 && arr[i + 1] % 2 == 1)
            {
                unparity = true;
                ops++;
            }
            else if (arr[i] % 2 == 0 && arr[i + 1] % 2 == 0)
            {
                unparity = true;
                ops++;
            }
        }

        if (!unparity)
        {
            cout << 0 << endl;
        }
        else
        {
            cout << ops << endl;
        }
    }
    return 0;
}