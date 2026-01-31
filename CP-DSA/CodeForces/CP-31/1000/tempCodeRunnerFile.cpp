#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main()
{
    ll N, D;
    cin >> N >> D;

    vector<ll> P(N);
    for (auto &it : P)
        cin >> it;

    // Cummilating logic:-
    ll wins = 0;
    // The logic is clicking slowly, what we can do is
    // D % (*max_element(P.begin(),P.end())) = r
    // we will track with a count var that if r is greater than max_element or not
    // when the r becomes < max_element, we will add 1 to count var
    // and then multiply the (count+1) with max_element
    // when we win, we will delete the indices from array

    ll mx = *max_element(P.begin(), P.end());
    ll r = D % mx;
    ll count = 0;

    while (!P.empty())
    {
        while (r > mx)
        {
            r = D % mx;
            count++;

            if (r < mx)
            {
                wins++;

                // erase first (count + 1) elements safely
                if (count + 1 <= (ll)P.size())
                    P.erase(P.begin(), P.begin() + count + 1);

                if (P.empty())
                    break;

                mx = *max_element(P.begin(), P.end());
                break;
            }
        }
    }

    cout<<wins<<endl;
}