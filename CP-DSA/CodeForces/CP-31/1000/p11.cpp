#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main()
{
    ll n, d;
    cin >> n >> d;

    vector<ll> P(n);
    for (auto &it : P)
        cin >> it;

    sort(P.begin(),P.end());
    // left side = weakest helpers
    // right side = strongest captains

    ll left = -1; // left pointer tracks how many weakest players
    ll right =  n- 1; // right pointer is the current strongest unused player
    ll team_size = 1; // current team size
    ll winner_teams = 0; // counts number of winning teams formed

    while(left < right){ // while we still have unused players
        if((P[right]*team_size) <= d && left < right){
            left++; // take one weakest player as helper
            team_size++;
        }else{ // finalize this team
            winner_teams++;
            right--; // captain consumed, move to next strongest
            team_size = 1; // reset for next team (new captain only)
        }
    }
    cout<<winner_teams<<endl;

}