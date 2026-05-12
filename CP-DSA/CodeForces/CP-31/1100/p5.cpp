#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    // So he basically prepared n boxes and arranged them in a row for trucks.
    // The ith box from the left weighs ai tons
    // All trucks has same number of boxes, k
    // boxes per truck => number of boxes/number of trucks = k
    // Number of Trucks = number of boxes/k = n/k
    // last batch of k boxes goes to (n/k)th truck
    // each and every truck must have k boxes.
    // if at any point a loading doesnt fit then that k is not possible
    // weight diff of 2 trucks => Max (if one truck (+)nt then 0)

    // This problem establishes difference in turck weights by arranging the boxes in ther row
    // and also by giving first k boxes to first and and second k to second truck
    // the larger the index of box ism the more it weighs
    // so first - last can get the right one

    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vector<ll> a(n);
        for (auto &it : a)
            cin >> it;

        // we will go by prefix sum:-
        // p[4]-p[2]
        // we will run a loop from 0 to n and we will increase i by k
        
         vector<ll> pre(n);
         pre[0]=a[0];

         for(ll i=1; i<n; i++){
            pre[i]=a[i]+pre[i-1];
         }

         ll ans = 0;

         for(ll k=1; k<n; k++){
            if(n%k) continue;

            ll start = k-1; // considering zero based indexing we will stgart after skipping k boxes
            ll maxi = pre[start];
            ll mini=pre[start];

            for(ll idx=start+k; idx<n; idx+=k){
                ll curr = pre[idx]-pre[idx-k];
                // subtracting gives sum of current block of size k
                maxi = max(maxi,curr);
                mini = min(mini,curr);
            }
            ans = max(ans,maxi-mini);
         }
         cout<<ans<<endl;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}