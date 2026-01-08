// Solution
#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;                 // number of test cases

    while (t--) {
        int n, k;
        cin >> n >> k;        // n = length of string, k = allowed removals

        string s;
        cin >> s;             // input string

        unordered_map<char, int> freq;
        // freq[c] = how many times character 'c' appears in string s

        for (char c : s) {
            freq[c]++;        // count frequency of each character
        }

        int odd = 0;
        // odd = number of characters having odd frequency

        for (auto &p : freq) {
            // p is a reference to each key-value pair in the map
            // p.first  = character
            // p.second = frequency of that character

            if (p.second % 2 == 1) {
                odd++;        // count characters with odd frequency
            }
        }

        // A palindrome can have at most:
        // 1 odd frequency character (center)
        // plus k characters we are allowed to remove
        // so total allowed odd frequencies = k + 1

        if (odd > k + 1)
            cout << "NO\n";
        else
            cout << "YES\n";
    }
}
