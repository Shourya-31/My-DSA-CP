// Understanding
// So for a good array => GCD < Length
// And its beutiful => All Prefixes with length >= 2 are good => 1st condition is true
// Also, array contains (+)ve int with size >= 2

// Solution
// So instead of checking:

// “Are all prefixes good in the current order?”

// We check:

// “Can I reorder the array so that all prefixes become good?”

// If array is not good then its a "NO"
// If array is good and beautiful then "YES"

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;                 
    cin >> t;

    while (t--) {
        long long n;       
        cin >> n;

        vector<long long> A(n);   
        for (int i = 0; i < n; i++) {
            cin >> A[i];       
        }
        int flag = 0;       // Flag to track if a "good" condition is found

        // Loop over all possible pairs (i, j) where i < j
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {

                // Compute GCD of A[i] and A[j]
                // If GCD is <= 2, we mark flag = 1
                // This indicates the array satisfies the required condition
                if (__gcd(A[i], A[j]) <= 2) {
                    flag = 1;
                }
            }
        }

        // If no such pair was found, array is NOT good/beautiful
        if (flag == 0) {
            cout << "NO" << endl;
        }
        // If at least one valid pair exists, array is good/beautiful
        else {
            cout << "YES" << endl;
        }
    }

    return 0;
}
