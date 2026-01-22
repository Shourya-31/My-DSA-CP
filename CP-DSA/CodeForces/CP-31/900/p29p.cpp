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

        bool flag = false;

        for (int j = 1; j < n - 1; j++)
        {
            int i = -1;
            int k = -1;
            for (int left = 0; left < j; left++)
            {
                if (a[left] < a[j])
                {
                    i = left;
                    break;
                }
            }

            for (int right = j + 1; right < n; right++)
            {
                if (a[right] < a[j])
                {
                    k = right;
                    break;
                }
            }

            if (i != -1 && k != -1)
            {
                cout << "YES\n";
                cout << i + 1 << " " << j + 1 << " " << k + 1 << "\n";
                flag = true;
                break;
            }
        }
        if (!flag)
            cout << "NO\n";
    }
}