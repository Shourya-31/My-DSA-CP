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

        long long ops = LLONG_MAX;

        long long arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        bool sorted = true;

        for(int i=0; i<n-1; i++){
            if(arr[i]>arr[i+1]){
                sorted = false;
                break;
            }
        }

        if(!sorted){
            cout<<0<<endl;
            continue;
        }

        for(int i=0; i<n-1; i++){
            ops = min(arr[i+1] - arr[i], ops);

        }

        cout<<(ops/2)+1<<endl;
    }
    return 0;
}
