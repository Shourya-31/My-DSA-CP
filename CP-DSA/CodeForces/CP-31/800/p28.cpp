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

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        sort(arr, arr + n);
        int mx = arr[n - 1];
        int mn = arr[0];

        if (mx == mn)
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;
            cout << mx << " ";
            for (int i = 0; i < n - 1; i++)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
