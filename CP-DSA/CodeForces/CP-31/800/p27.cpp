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

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        for (int i = 0; i < n; i++)
        {
            if (arr[i] == 2)
            {
                count++;
            }
        }

        int target = count / 2;
        int pref = 0;

        if (count % 2 != 0)
        {
            cout << -1 << endl;
            continue;
        }
        else
        {
            for (int i = 0; i < n; i++)
            {
                if (arr[i] == 2)
                {
                    pref++;
                }
                if(pref == target){
                    cout<<i + 1<<endl;
                    break;
                }
            }
        }
    }
}