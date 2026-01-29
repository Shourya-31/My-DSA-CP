#include <bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
    int n;
    cin >> n;
    string s;
    cin >> s;

    vector<bool> blocked(n, false);
    int initial_students = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            initial_students++;
            blocked[i] = true;
            if (i > 0) blocked[i - 1] = true;
            if (i < n - 1) blocked[i + 1] = true;
        }
    }

    int extra_students = 0;
    int current_gap = 0;
    for (int i = 0; i < n; i++) {
        if (!blocked[i]) {
            current_gap++;
        } else {
          
            if (current_gap > 0) {
                extra_students += (current_gap + 2) / 3;
            }
            current_gap = 0;
        }
    }

    if (current_gap > 0) {
        extra_students += (current_gap + 2) / 3;
    }

    cout << initial_students + extra_students << endl;
    }
    return 0;
}