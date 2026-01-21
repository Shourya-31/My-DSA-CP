// Problem: Contiguous Array
// Given a binary array, find the maximum length of a contiguous subarray with equal number of 0 and 1.

// Approach: Map with prefix sum
// let 0 be -1 and 1 be +1
// Now calculate prefix sum
// If at any two indices i and j, prefix sum is same, then the subarray between i+1 to j has equal number of 0s and 1s
// If the num x occurs at i,j,k in the prefix sum array, then the index where the first occurance of x is found is (k - i)
// Since we want the maximum length, we will store the first occurance of each prefix sum in a map
#include <bits/stdc++.h>
using namespace std;

int solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    map<int, int> mp;
    mp[0] = -1; // prefix sum 0 occurs at index -1
    
    int ans = 0;
    int sum = 0;
    for(int i=0; i<n; i++){ //nlogn
        if(v[i] == 0){
            sum -= 1;
        }else{
            sum += 1;
        }

        if(sum == 0){
            ans = max(ans,i+1);
        }else{
            if(mp.find(sum) != mp.end()){
                ans = max(ans,i - mp[sum]);
                // if sum is already present, then we store index updated
            }
            //update the sum index only if it is not present
            else{
                mp[sum] = i;
            }
        }
    }
    return ans;
}

int main(){
    cout<<solve()<<endl;
    return 0;
}

// TC: O(nlogn)
