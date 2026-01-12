// Solution
#include <bits/stdc++.h>
using namespace std;

int main()
{
    // Number of test cases
    int t;
    cin >> t;

    // Process each test case
    while (t--)
    {
        // s = initial string
        // t = target string we want to end up with
        string s, t;
        cin >> s >> t;

        int n = s.size(); // length of initial string
        int m = t.size(); // length of target string

        // freq_in_t[c] stores how many times
        // character 'A'+c is still needed to form string t
        vector<int> freq_in_t(26, 0);

        // Count frequency of each character in target string t
        for (int i = 0; i < m; i++) {
            freq_in_t[t[i] - 'A']++;
        }

        /*
            We iterate from RIGHT TO LEFT in s.

            Why?
            - Deleting characters from the right does not affect
              the "first occurrence" rule on the left.
            - This allows us to safely decide which characters to keep.

            Logic:
            - If current character s[i] is still needed for t,
              we KEEP it and decrease its required frequency.
            - Otherwise, we DELETE it (mark with '.').
        */
        for (int i = n - 1; i >= 0; i--) {
            // If this character is still required to build t
            if (freq_in_t[s[i] - 'A'] > 0) {
                // Keep it and reduce required count
                freq_in_t[s[i] - 'A']--;
            } else {
                // Otherwise, delete this character
                // (marking with '.' instead of actually removing)
                s[i] = '.';
            }
        }

        // Build the final string after deletions
        string final_string = "";

        for (int i = 0; i < n; i++) {
            // Ignore deleted characters
            if (s[i] != '.') {
                final_string += s[i];
            }
        }

        // If the resulting string exactly matches t,
        // then the transformation is possible
        if (final_string == t) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
