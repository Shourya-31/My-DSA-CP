#include <bits/stdc++.h>
using namespace std;

/*
Function: min_operations

Purpose:
- Calculate the minimum number of digit deletions required
  to make the string `s` end with `possible_values`
  (one of: "00", "25", "50", "75").

Core idea:
- A number is divisible by 25 iff its last two digits are
  one of the above patterns.
- We try to form the pattern from RIGHT to LEFT.
- Any digit that does not help in forming the pattern
  must be deleted.
*/
int min_operations(string s, string possible_values)
{
    int ops = 0;  
    // Number of deletions required

    int checker_index = possible_values.size() - 1;
    // Points to the current digit of pattern we are trying to match
    // Start from the last digit of the pattern (rightmost)

    // Traverse the number from right to left
    for (int i = s.size() - 1; i >= 0; i--)
    {
        // If current digit matches the needed pattern digit
        if (s[i] == possible_values[checker_index]) {
            checker_index--;  // Move left in the pattern

            // If all pattern digits are matched
            if (checker_index < 0) {
                break;  // Stop scanning
            }
        }
        else {
            // Digit does not help form the pattern,
            // so it must be deleted
            ops++;
        }
    }

    // If we couldn't match the full pattern,
    // making divisibility by 25 is impossible
    if (checker_index >= 0) {
        ops = INT_MAX;
    }

    return ops;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        /*
        Problem:
        - Given a positive integer as a string
        - We can delete digits (keeping order)
        - Stop when:
          1) The number becomes divisible by 25, OR
          2) Only one digit remains
        - Find the minimum deletions needed
        */

        string s;
        cin >> s;

        int ans = INT_MAX;

        // Valid endings for divisibility by 25
        vector<string> patterns = {"00", "25", "50", "75"};

        // Try forming each valid ending
        for (auto pattern : patterns) {
            ans = min(ans, min_operations(s, pattern));
        }

        // Output the minimum deletions required
        // (INT_MAX means impossible)
        cout << ans << endl;
    }
}
