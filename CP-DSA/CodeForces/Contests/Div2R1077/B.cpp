#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        ll n;
        cin >> n;

        string s;
        cin >> s;

        ll max_s = 0;

        for (auto &it : s)
        {
            if (it == '1')
                max_s++;
        }

        for (int i = 0; i + 2 < n; i++)
        {
            if (s[i] == '0' && s[i+1] == '0' && s[i+2] == '0')
                max_s++;
        }

        cout << max_s << endl;
    }
}
