#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;   // number of test cases

    while (t--) {
        int n, a, b;
        cin >> n >> a >> b;

        /*
        Case 1:
        If a == b == n, then both permutations are fully identical.
        Longest common prefix = n
        Longest common suffix = n
        Always possible.
        */

        /*
        Case 2:
        We need to place:
        - a elements as common prefix
        - b elements as common suffix
        - at least 2 extra elements in between to break prefix and suffix
        So total needed length = a + b + 2

        If this fits inside n, answer is Yes.
        */

        if ((a + b + 2 <= n) || (a == b && b == n)) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
}
