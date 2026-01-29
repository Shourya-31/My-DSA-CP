#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll t;
    cin >> t;

    while (t--)
    {
        ll n;
        cin >> n;

        vector<ll> a(n), b(n);
        for (auto &it : a)
            cin >> it;
        for (auto &it : b)
            cin >> it;

        unordered_map<ll, ll> streak_A, streak_B;

        for (ll i = 0; i < n;)
        {
            // NO i++ here
            // Because we will jump i manually after processing a full streak
            ll j = i;
            // j is another pointer
            // It will move forward to find where current streak ends
            // So [i, j) will represent a block of same numbers

            while (j < n && a[j] == a[i])
                j++;
            // Move j forward while:
            // 1) We are inside array bounds
            // 2) Value is same as starting streak value a[i]

            // Example:
            // a = [2 2 2 1 1]
            // If i = 0 → a[i] = 2
            // j will go: 0 -> 1 -> 2 -> 3
            // Stops at index 3 because a[3] != 2

            // So streak is from index i=0 to j-1=2
            // Length = j - i

            streak_A[a[i]] = max(streak_A[a[i]], j - i);
            // We store best streak length seen so far for this value

            // a[i] = current number
            // j-i = length of this streak

            // Example:
            // streak_A[2] = max(old_best, current_streak_length)

            // If map didn't have this key → default 0 → works fine

            i = j;
            // Move i to start of next new streak
            // So we SKIP entire processed segment
        }

        for (ll i = 0; i < n;)
        {
            ll j = i;
            while (j < n && b[j] == b[i])
                j++;

            streak_B[b[i]] = max(streak_B[b[i]], j - i);
            i = j;
        }

        ll ans = 0;

        for (auto &it : streak_A)
        {
            ll val = it.first;
            ans = max(ans, streak_A[val] + streak_B[val]);
        }

        for (auto &it : streak_B)
        {
            ll val = it.first;
            ans = max(ans, streak_A[val] + streak_B[val]);
        }

        cout << ans << endl;
    }
}