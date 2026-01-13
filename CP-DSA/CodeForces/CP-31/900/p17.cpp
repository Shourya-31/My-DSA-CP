// Solution
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

        vector<long long> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        int ops = 0;
        sort(arr.begin(), arr.end());

        unordered_map<long long, long long> freq;
        long long max_freq = 1, curr = 1;

        for (int i = 1; i < n; i++)
        {
            if (arr[i] == arr[i - 1])
                curr++;
            else
                curr = 1;

            max_freq = max(max_freq, curr);
        }


        while (max_freq < n)
        {
            ops++;
            long long use = min(max_freq, n - max_freq);
            ops += use;
            max_freq += use;
        }
        cout << ops << endl;
    }
    return 0;
}