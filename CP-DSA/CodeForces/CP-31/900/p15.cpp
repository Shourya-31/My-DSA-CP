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

        vector<long long> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        long long count = 0;

        for (int i = n - 2; i >= 0; i--)
        {
            while (arr[i] >= arr[i + 1])
            {
                arr[i] = arr[i] / 2;
                count++;
                if (arr[i] == 0)
                {
                    break;
                }
            }

            if(arr[i] == 0 && arr[i+1] == 0){
                count = -1;
                break;
            }
        }
            cout << count << endl;
    }
    return 0;
}