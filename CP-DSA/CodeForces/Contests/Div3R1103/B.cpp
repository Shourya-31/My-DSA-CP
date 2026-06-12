#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, k;
        cin >> n >> k;

        string s;
        cin >> s;

        // Choose an integer i
        // Invert chars at positions i & i+k
        // => Change 0 to 1 and 1 to 0

        // Goal:- Make entire string equal to zero
        // O/P:- YES if he can NO if he cannot

        // bool flag = false;

        // vector<ll> a;
        // for (ll i = 0; i < n; i++)
        // {
        //     a.push_back(s[i] - '0');
        // }

        // vector<ll> zero;

        // for (int i = 0; i < a.size(); i++)
        // {
        //     if (a[i] == 0)
        //     {
        //         zero.push_back(i);
        //         flag = true;
        //     }
        // }

        // i feel i should break the string into the
        // valid chains according to k and check if there
        // are even ones or not, if there are even ones
        // then it can become zero and if not then noooo

        bool flag = true;

        for (int r = 0; r < k; r++)
        {
            int ones = 0;

            for (int position = r; position < n; position += k)
            {
                if (s[position] == '1')
                    ones++;
            }

            if (ones % 2)
            {
                flag = false;
                break;
            }
        }

        cout << (flag ? "YES" : "NO") << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}