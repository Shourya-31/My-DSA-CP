#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        string s;
        cin >> s;
        // abcad
        // => bcad (cad => ad (a & d) & cd (c & d)) &
        // acad (=> cad (ad (a & d) & cd (c & d)) & 
        // acd (ad (a & d) & cd (c & d))
        map<char,int> freq;
        ll count = 0;
        vector<int> distinct(n,0);
        for(int i=0; i<n; i++){
            freq[s[i]]++;
            if(freq[s[i]] == 1){
                count++;
            }
            distinct[i] = count;
        }

        ll ans=0;
        for(auto &it: distinct){
            ans += it;
        }

        // we iterate over string and count distinct chars
        // so while iterating ans = distinct count at i

        cout << ans << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}