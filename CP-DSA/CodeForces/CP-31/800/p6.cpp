// A. Doremy's Paint 3
// time limit per test: 1 second
// memory limit per test: 256 megabytes

// An array b1, b2, …, bn of positive integers is good if all the sums of two
// adjacent elements are equal to the same value.

// More formally, the array is good if there exists a k such that:
// b1 + b2 = b2 + b3 = … = b(n−1) + bn = k

// Doremy has an array a of length n.
// Now Doremy can permute its elements (change their order) however she wants.
// Determine if she can make the array good.

// Input
// The input consists of multiple test cases.
// The first line contains a single integer t (1 ≤ t ≤ 100) — the number of test cases.
// The description of the test cases follows.

// The first line of each test case contains a single integer n (2 ≤ n ≤ 100) —
// the length of the array a.

// The second line of each test case contains n integers
// a1, a2, …, an (1 ≤ ai ≤ 100000).

// There are no constraints on the sum of n over all test cases.

// Output
// For each test case, print "Yes" (without quotes) if it is possible to make
// the array good, and "No" (without quotes) otherwise.

// You can output the answer in any case (upper or lower).
// For example, the strings "yEs", "yes", "Yes", and "YES" will be recognized
// as positive responses.

// Example

// Input
// 5
// 2
// 8 9
// 3
// 1 1 2
// 4
// 1 1 4 5
// 5
// 2 3 3 3 3
// 4
// 100000 100000 100000 100000

// Output
// Yes
// Yes
// No
// No
// Yes

// Note
// In the first test case, [8, 9] and [9, 8] are good.

// In the second test case, [1, 2, 1] is good because
// a1 + a2 = a2 + a3 = 3.

// In the third test case, it can be shown that no permutation is good.

/*
APPROACH:

- We are allowed to permute the array in any order.
- The condition b1 + b2 = b2 + b3 = ... means adjacent elements must form
  the same sum every time.

KEY OBSERVATION:
- If more than 2 distinct values exist, it is impossible to keep all adjacent
  sums equal after permutation.
- So the array must contain at most 2 distinct numbers.

CASES:
1) Only 1 distinct number:
   - All elements are same.
   - Every adjacent sum is equal automatically.
   - Answer is YES.

2) Exactly 2 distinct numbers:
   - To keep sums equal, elements must be placed alternately
     (x, y, x, y, ...).
   - This requires:
       a) Both numbers appear the same number of times, OR
       b) Array length is odd and their frequencies differ by exactly 1
          (the extra element goes in the middle).

IMPLEMENTATION:
- Count frequencies using a map.
- If number of distinct elements >= 3 → print NO.
- Otherwise, compare the two frequencies using above rules.

TIME COMPLEXITY:
- O(n) per test case.

SPACE COMPLEXITY:
- O(1) extra space (at most 2 distinct elements stored).
*/


// Solution Code:

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;  // Number of test cases

    while (t--)
    {
        long long n;
        cin >> n;  // Length of the array

        long long arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];  // Read array elements
        }

        // Map to store frequency of each distinct value
        map<long long, long long> frequency_map;

        // Count frequency of each number
        for (int i = 0; i < n; i++)
        {
            frequency_map[arr[i]]++;
        }

        // If there are 3 or more distinct elements
        // It's impossible to make adjacent sums equal
        if (frequency_map.size() >= 3)
        {
            cout << "No" << endl;
        }
        else
        {
            // Get frequency of the smallest element
            long long freq_1 = frequency_map.begin()->second;

            // Get frequency of the largest element
            long long freq_2 = frequency_map.rbegin()->second;

            // Case 1:
            // If both elements appear same number of times
            // Example: [1,2,1,2] → perfectly alternating
            if (freq_1 == freq_2)
            {
                cout << "Yes" << endl;
            }

            // Case 2:
            // If n is odd and frequency difference is exactly 1
            // Example: [1,2,1] → middle element repeats
            else if (n % 2 == 1 && abs(freq_1 - freq_2) == 1)
            {
                cout << "Yes" << endl;
            }

            // Otherwise, arrangement is impossible
            else
            {
                cout << "No" << endl;
            }
        }
    }

    return 0;
}
