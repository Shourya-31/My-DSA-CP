#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        long long n;
        cin >> n;

        string s;
        cin >> s;

        unordered_map<char, int> fa;
        unordered_map<char, int> fb;

        bool brk = false;
        string si = "";
        string sj = "";
        for (int i = 0; i < s.size() - 1; i++)
        {
            if(!brk){
                // si+=s[i];
                fa[s[i]]++;
            }
            
            if (fa.find(s[i]) != fa.end())
            {
                brk = true;
                if(brk){
                    // sj+=s;
                    fb[s[i]]++;
                }
            }
        }

        for(auto &it : si){
            fa[it]++;
        }

        for(auto &it : sj){
            fb[it]++;
        }

        cout<<fa.size()+fb.size()<<endl;
    }
}