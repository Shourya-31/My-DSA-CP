#include <bits/stdc++.h>
using namespace std;

int main() {

    int t;
    cin >> t;

    while (t--) {
        string s;
        cin >> s;

        if (s.front() != s.back()) {
            s.back() = s.front();
        }

        cout << s << "\n";
    }
    return 0;
}
