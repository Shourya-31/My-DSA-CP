#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n, q;
        cin >> n >> q;

        vector<long long> a(n), b(n);
        for (auto &x : a) cin >> x;
        for (auto &x : b) cin >> x;

        vector<long long> suffMax(n);
        suffMax[n - 1] = b[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            suffMax[i] = max(b[i], suffMax[i + 1]);
        }

        vector<long long> pref(n + 1, 0);
        for (int i = 0; i < n; i++) {
            pref[i + 1] = pref[i] + suffMax[i];
        }

        while (q--) {
            int l, r;
            cin >> l >> r;
            l--; r--;
            cout << pref[r + 1] - pref[l] << " ";
        }
        cout << "\n";
    }
    return 0;
}
