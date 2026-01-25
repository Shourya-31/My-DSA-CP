#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;

    string target = "hello";
    int j = 0;

    for (auto &c : s)
    {
        if (c == target[j])
        {
            j++;
        }
        if (j == target.size())
        {
            break;
        }
    }

    if (j == target.size())
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }
}