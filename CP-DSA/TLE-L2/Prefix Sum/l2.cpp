// 2D Prefix Sum => Similar to 1D prefix sum but applied to 2D arrays (matrices).

// Problem: for a given point (x1, y1) to (x2, y2) find the sum of all elements in that sub-matrix in O(1) time.
// Treat these 2 points as diagonal ends of the sub-matrix
// Approach: P[x2][y2] - P[x1-1][y2] (Upper layer) - P[x2][y1-1] (Left layer) + P[x1-1][y1-1] (Overlapped area which is subtracted twice)
// If x1 = 0 or y1 = 0, then we don't subtract those layers.
// Approach: P[i][j] = A[i][j] + P[i-1][j] + P[i][j-1] - P[i-1][j-1]
#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(n, vector<int>(m));

    vector<vector<int>> pre(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        {
            for (int j = 0; j < m; j++)
            {
                pre[i][j] = v[i][j];
                if (j > 0)
                {
                    pre[i][j] += pre[i][j - 1];
                }
                if (i > 0)
                {
                    pre[i][j] += pre[i - 1][j];
                }
                if (i > 0 && j > 0)
                {
                    pre[i][j] -= pre[i - 1][j - 1];
                }
              //  pre[i][j] = pre[i][j - 1] + pre[i - 1][j] - pre[i - 1][j - 1] + v[i][j];
              // The above line will give out of bound error when i = 0 or j = 0
              // Therefore we are adding the terms based on conditional checks
            }
        }
    }

    int q;
    cin>>q;
    while(q--){
        int l1,r1,l2,r2;
        cin>>l1>>r1>>l2>>r2;
        
        int ans = 0;
        if(l1>0){
            ans-=pre[l1-1][r2];
        }
        if(r1>0){
            ans-=pre[l2][r1-1];
        }
        if(l1>0 && r1>0){
            ans+=pre[l1-1][r1-1];
        }
        cout<<ans<<" ";
        //ans = pre[l2][r2]-pre[l1-1][r2]-pre[l2][r1-1]+pre[l1-1][r1-1];
    }
}