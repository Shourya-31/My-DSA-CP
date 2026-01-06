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
        int count = 0;
        int max_length = 0;

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        for (int i = 0; i < n; i++)
        {
            if (arr[i] == 0)
            {
                count++;
            }
            else
            {
                count = 0;
            }
            max_length = max(max_length, count);
        }

        cout << max_length << endl;
    }
    return 0;
}