#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool isPalindrome(const string &s)
{
    int l = 0, r = s.size() - 1;
    while (l < r)
    {
        if (s[l] != s[r])
            return false;
        l++;
        r--;
    }
    return true;
}

bool isNonDecreasing(const string &p)
{
    for (int i = 1; i < p.size(); i++)
        if (p[i] < p[i - 1])
            return false;
    return true;
}

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

        bool ok = false;

        for(int i = 0; i < (1 << n); i++){
            string p = "",x = "";
            vector<int>idx;

            for(int j = 0; j < n; j++){
                if(i & (1 << j)){
                    p += s[j];
                    idx.push_back(j+1);
                }else{
                    x += s[j];
                }
            }

            if(isNonDecreasing(p) && isPalindrome(x)){
                cout<<idx.size()<<endl;
                for(auto &it : idx)cout<<it<<" ";
                cout<<endl;
                ok = true;
                break;
            }
        }

        if(!ok) cout<<-1<<endl;
    }
}
