#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve()
{
    int t;
    cin >> t;

    while (t--)
    {
        string s;
        cin >> s;
        int n = (int)s.size();
        // the difference between the frequencies of u and v in t is not more than 1

        // string should be periodic => Repeating string
        // it should contain unique characters
        // If the string is not periodic then it will not be balanced
        // Condition is sufficient

        set<char> c;
        int k;
        for (k = 0; k < n; k++)
        {
            if (c.find(s[k]) == c.end())
            {
                c.insert(s[k]);
            }
            else
            {
                break; // if a character comes for a second time without repeatition
            }
        }

        bool ok = true;

        for (int i = k; i < n; i++)
        {
            if (s[i] != s[i - k])
            {
                ok = false;
                break;
            }
        }

        cout << (ok ? "YES" : "NO") << '\n';

        // vector<map<char, int>> freqs;
        // vector<string> subs;
        // bool flag = true;
        // for (int i = 0; i < s.size(); i++)
        // {
        //     for (int j = i; j < s.size(); j++)
        //     {
        //         // subs.push_back(s.substr(i, j - i + 1));
        //         string sub = s.substr(i, j - i + 1);
        //         subs.push_back(sub);

        //         map<char, int> freq;

        //         for (char ch : sub)
        //             freq[ch]++;
        //         freqs.push_back(freq);
        //     }
        // }

        // for (auto &freq : freqs)
        // {
        //     if (abs(freq['a'] - freq['b']) > 1)
        //     {
        //         flag = false;
        //         break;
        //     }
        // }

        // if (flag)
        // {
        //     cout << "YES" << endl;
        // }
        // else
        // {
        //     cout << "NO" << endl;
        // }

        // for (int i = 0; i < subs.size(); i++)
        // {
        //     for (auto &sub : subs)
        //     {
        //         freq[sub]++;
        //     }
        // }

        // for (auto &sub : subs)
        // {
        //     vector<char, int> freq(26, 0);

        //     for (char ch : sub)
        //     {
        //         freq[ch - 'a']++;
        //     }
        // }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}