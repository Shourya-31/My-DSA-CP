#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long long t;
    cin >> t;

    while (t--) {
        long long x, n;
        cin >> x >> n;

        // If no jumps, position remains the same
        if (n == 0) {
            cout << x << "\n";
            continue;
        }

        // Jumps repeat their net effect every 4 steps
        // So only n % 4 matters
        long long r = n % 4;

        // Case 1: Starting position is EVEN
        // First jump goes LEFT, this fixes the whole 4-jump cycle
        if (x % 2 == 0) {

            // After 4k jumps → net change = 0
            if (r == 0)
                cout << x << "\n";

            // After 4k + 1 jumps → big move to the left
            else if (r == 1)
                cout << x - n << "\n";

            // After 4k + 2 jumps → small move to the right
            else if (r == 2)
                cout << x + 1 << "\n";

            // After 4k + 3 jumps → big move to the right
            else
                cout << x + (n + 1) << "\n";
        }

        // Case 2: Starting position is ODD
        // First jump goes RIGHT, cycle is mirrored
        else {

            // After 4k jumps → net change = 0
            if (r == 0)
                cout << x << "\n";

            // After 4k + 1 jumps → big move to the right
            else if (r == 1)
                cout << x + n << "\n";

            // After 4k + 2 jumps → small move to the left
            else if (r == 2)
                cout << x - 1 << "\n";

            // After 4k + 3 jumps → big move to the left
            else
                cout << x - (n + 1) << "\n";
        }
    }
}
