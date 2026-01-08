// Solution
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;                      // number of test cases

    while (t--) {
        long long a, b;
        int n;
        cin >> a >> b >> n;         // a = max timer value
                                    // b = initial timer
                                    // n = number of tools

        long long ans = b;          // start with initial time 'b'
                                    // this is the time bomb survives without tools

        for (int i = 0; i < n; i++) {
            long long x;
            cin >> x;               // x = timer increase of current tool

            /*
             Each tool can increase the timer by x.
             BUT:
             - Timer cannot exceed 'a'
             - After using a tool, timer decreases by 1 in the same second
             - So maximum effective gain from any tool is (a - 1)

             Therefore:
             real contribution of this tool = min(x, a - 1)
            */

            ans += min(x, a - 1);   // add maximum useful seconds from this tool
//             - The timer never actually stays at value 'a'
//             - The maximum value you can start a new second with is (a - 1)
        }

        cout << ans << '\n';        // total maximum time before explosion
    }

    return 0;
}
