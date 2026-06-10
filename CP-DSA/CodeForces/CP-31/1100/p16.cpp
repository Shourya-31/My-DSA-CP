#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<ll> c(n);

        for (auto &it : c)
            cin >> it;

        //  can select some subsequence of a and add into a
        //  an element equal to the sum of all elements of the subsequence

        // If we go by the problem then we can understad that this is a core problem we can solve by using sliding window approach or prefix sum
        // we can make a window and according to the need of comparision we can expand or shrink the window and we can keep track of the sum of the elements in the window and we can compare it with the required sum

        vector<ll> a(n);
        a[0] = 1;

        sort(c.begin(), c.end());

        bool flag = true;

        if (c[0] != 1){
            flag = false;
        };


        ll sum = 1;
        for (ll i = 1; i < n; i++)
        {
            if (c[i] > sum)
            {
                flag = false;
                break;
            }
            else
            {
                sum += c[i];
            }
        }

        // for(int i=0; i<n; i++){
        //     if(a[i] != c[i]){
        //         flag = false;
        //         break;
        //     }
        // }

        if (flag)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}