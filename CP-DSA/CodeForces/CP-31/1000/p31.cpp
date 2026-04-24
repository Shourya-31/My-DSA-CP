#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    ll n;
    cin >> n;

    string s;
    cin >> s;

    bool flag = false;

    for (int i = 0; i < n - 1; i++)
    {
        if (s[i] > s[i + 1])
        {
            flag = true;
            cout << "YES" << endl;
            cout << i + 1 << " " << i + 2 << endl;
            break;
        }
    }

    if (!flag)
    {
        cout << "NO" << endl;
    }
}

int main(){
    solve();
    return 0;
}