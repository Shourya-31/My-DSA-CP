#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    vector<long long> freq(26, 0);

    for (char c : s) {
        freq[c - 'A']++;
    }

    int oddCount = 0;
    int oddIndex = -1;

    for (int i = 0; i < 26; i++) {
        if (freq[i] % 2 != 0) {
            oddCount++;
            oddIndex = i;
        }
    }

    if (oddCount > 1) {
        cout << "NO SOLUTION\n";
        return 0;
    }

    string firstHalf = "";
    string middle = "";

    for (int i = 0; i < 26; i++) {
        if (freq[i] % 2 == 1) {
            middle = string(freq[i], char('A' + i));
        } else {
            firstHalf += string(freq[i] / 2, char('A' + i));
        }
    }

    string secondHalf = firstHalf;
    reverse(secondHalf.begin(), secondHalf.end());

    cout << firstHalf + middle + secondHalf << endl;

    return 0;
}
