// Solution

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int minNum = abs(arr[0]);

    for (int i = 1; i < n; i++)
    {
        minNum = min(minNum, abs(arr[i]));
    }

    cout << abs(minNum) << endl;

    return 0;
}