#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        string s;
        cin>>s;

        // 2 ops we have:
        // Delete one char from s => 1 coin
        // Swap any 2 nums => 0 coin

        // Constraints: ti != si
        // means after performing ith oprn:
        //            ti != si
        // And empty string is also good

        long long count_0s = 0;
        long long count_1s = 0;
        for(auto &it : s){
            if(it == '1'){
                count_1s++;
            }else{
                count_0s++;
            }
        }

        long long length_of_t = 0;
        for(int i=0; i<s.size(); i++){
            if(s[i] == '0' && count_1s > 0){
                count_1s--; // Use a '1' to make a pair with '0'
                length_of_t++; // Increase the length of the good string
            }else if(s[i] == '1' && count_0s > 0){
                count_0s--; // Use a '0' to make a pair with '1'
                length_of_t++; //Increase the length of good string
            }else{
                break;
            }
        }

        cout<<(s.size() - length_of_t)<<endl;
    }
}