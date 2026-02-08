#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    string s;
    cin >> s;

    int max_len = 1;
    int curr_len = 1;

    for (int c = 1; c < s.size(); c++)
    {
        if(s[c] == s[c-1]){
            curr_len++;
        }else{
            curr_len = 1;
        }
        max_len = max(max_len,curr_len);
    }

    cout<<max_len<<endl;
}