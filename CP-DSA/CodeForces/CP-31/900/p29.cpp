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
        vector<long long> v(n);
        for (auto &it : v)
            cin >> it;

        int flag = false; // if there exists a triplet
        for(int j = 1; j <n - 1; j++){
            int i = -1, k = -1;

            for(int left = 0; left<j; left++){
                if(v[left] < v[j]){
                    i = left;
                    break;
                }
            }

            for(int right = j +1; right<n; right++){
                if(v[right] < v[j]){
                    k = right;
                    break;
                }
            }

            if(i != -1 && k != -1){
                cout<<"YES\n";
                cout<<i + 1<<" "<<j + 1<<" "<<k + 1<<"\n";
                flag = true;
                break;
            }
        }
        if(!flag) cout<<"NO\n";
    }
}