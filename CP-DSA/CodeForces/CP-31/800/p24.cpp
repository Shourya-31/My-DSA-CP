// Solution
#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;                  // Number of test cases

    while (t--) {
        int n;
        cin >> n;              // Size of the array

        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];     // Input array elements
        }

        int total_xor = 0;     // Will store XOR of all array elements

        // Compute XOR of the entire array
        // total_xor = a1 ^ a2 ^ a3 ^ ... ^ an
        for (int i = 0; i < n; i++) {
            total_xor ^= arr[i];
        }

        /*
            We want:
            (a1 ^ x) ^ (a2 ^ x) ^ ... ^ (an ^ x) = 0

            This simplifies to:
            (a1 ^ a2 ^ ... ^ an) ^ (x ^ x ^ ...)

            If n is even:
                x ^ x ^ ... (even times) = 0
                Final XOR = total_xor
                So total_xor must already be 0

            If n is odd:
                x ^ x ^ ... (odd times) = x
                Final XOR = total_xor ^ x = 0
                So x = total_xor
        */

        if (n % 2 == 1) {
            // Odd length array:
            // Choosing x = total_xor makes the final XOR equal to 0
            cout << total_xor << endl;
        } else {
            // Even length array:
            // x disappears, so XOR must already be 0
            if (total_xor == 0) {
                // Any x works, choose 0
                cout << 0 << endl;
            } else {
                // Impossible to make final XOR 0
                cout << -1 << endl;
            }
        }
    }

    return 0;
}
