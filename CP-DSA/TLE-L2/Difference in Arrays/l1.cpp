// Problem: Given an array of N elements, answer following Q queries:
// * Query: L,R
// Result = A[L] + 2*A[L+1] + 3*A[L+2] + ... + (R-L+1)*A[R]
// First thing to do in these questions: Write the general term in Ai
#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }

    vector<int> pre1(n + 1, 0), pre2(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        pre1[i] = pre1[i - 1] + (i * arr[i]);
        pre2[i] = pre2[i - 1] + arr[i];
    }
    int q;
    cin >> q;

    while(q--){
        int l,r;
        cin>>l>>r;
        cout<<(pre1[r] - pre1[l-1] - (l-1)*(pre2[r] - pre2[l-1]))<<" "<<endl;
    }// summation of Ai from l to r is pre1[r] - pre1[l-1]
    // Therefore summation (l-1)*Ai from l to r is (l-1)*(pre2[r] - pre2[l-1])

    cout<<endl;
}

int main(){
    solve();
    return 0;
}

// TC: O(n + q)