#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;

        vector<int> right(26, 0), left(26, 0);

        int rcnt = 0;
        for (char c : s) {
            if (right[c - 'a'] == 0) rcnt++;
            right[c - 'a']++;
        }

        int lcnt = 0;
        int ans = 0;

        for (int i = 0; i < n - 1; i++) {
            if (left[s[i] - 'a'] == 0) lcnt++;
            left[s[i] - 'a']++;

            right[s[i] - 'a']--;
            if (right[s[i] - 'a'] == 0) rcnt--;

            ans = max(ans, lcnt + rcnt);
        }

        cout << ans << endl;
    }
}
