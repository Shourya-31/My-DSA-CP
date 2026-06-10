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
        ll k;
        cin >> n >> k;

        vector<vector<ll>> a(n, vector<ll>(n));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> a[i][j];
            }
        }

        bool flag = true;

        ll count = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
               if(a[i][j] != a[n-1-i][n-1-j]){
                   count++;
               }
            }
        }

        count /= 2;

        // The logic I have built for it is:
        // 1.) if the indice of matrix is 1 than replace it with 2 and if its 0  replace it with 3, vice versa applied for 2 and 3
        // 2.) After replacement we will check if indices (i,j) are same or not, if they are same we change the color and reduce k else we dont
        // 3.) After we check all the indices we will check if k is greater than 0 or not, if it is still greater than 0 afeter we have changed the colors and have checked the indices, the answer is yes else no
        
    
        if(count > k){
            flag = false;
        }
        else if((k - count) % 2 != 0 && n % 2 == 0){
            flag = false;
        }
        if(flag){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}