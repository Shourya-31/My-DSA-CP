#include <iostream>
#include <vector>
using namespace std;

int main() {
    long long n;
    cin >> n;

    long long total = n * (n + 1) / 2;

    if (total % 2 != 0) {
        cout << "NO\n";
        return 0;
    }

    cout << "YES\n";

    vector<long long> set1, set2;

    if (n % 4 == 0) {
        for (long long i = 1; i <= n; i += 4) {
            set1.push_back(i);
            set1.push_back(i + 3);

            set2.push_back(i + 1);
            set2.push_back(i + 2);
        }
    } else { // n % 4 == 3
        set1.push_back(1);
        set1.push_back(2);
        set2.push_back(3);

        for (long long i = 4; i <= n; i += 4) {
            set1.push_back(i);
            set1.push_back(i + 3);

            set2.push_back(i + 1);
            set2.push_back(i + 2);
        }
    }

    cout << set1.size() << "\n";
    for (auto x : set1) cout << x << " ";
    cout << "\n";

    cout << set2.size() << "\n";
    for (auto x : set2) cout << x << " ";
    cout << "\n";

    return 0;
}
