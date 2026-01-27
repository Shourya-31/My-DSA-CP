#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll n;
    cin >> n;
    unordered_map<string, ll> freq;

    while (n--)
    {
        string s;
        cin >> s;
        freq[s]++;
    }

    string ans = "";
    ll mx = 0;

    for(auto &it : freq){
        if(it.second > mx){
            mx = it.second;
            ans = it.first;
        }
    }

    cout<<ans<<endl;
}