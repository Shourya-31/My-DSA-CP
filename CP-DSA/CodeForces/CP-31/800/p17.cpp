#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t; 
    // Number of test cases

    while (t--)
    {
        int n, k, x;
        cin >> n >> k >> x;
        // n = target sum we want to make
        // k = numbers available from 1 to k
        // x = forbidden number (cannot be used at all)

        /*
        Core idea:
        - We have unlimited supply of numbers from 1 to k except x
        - We must form sum exactly equal to n
        - If possible, print:
            YES
            count of numbers used
            the numbers themselves
        */

        // CASE 1: x != 1
        // This means number 1 is allowed
        // Since we have unlimited 1s, we can always form any n
        if (x != 1)
        {
            cout << "YES\n";

            // Using '1' exactly n times
            // Total count of integers = n
            cout << n << "\n";

            for (int i = 0; i < n; i++)
            {
                cout << 1 << " ";
            }
            cout << "\n";
        }
        else
        {
            // CASE 2: x == 1
            // Number 1 is forbidden, so we cannot use 1

            // If k == 1, then the only number available was 1
            // But 1 is forbidden → no numbers available
            // Hence impossible to form any positive sum
            if (k == 1)
            {
                cout << "NO\n";
                continue;
            }

            // Now we have numbers >= 2 available

            // If n is even:
            // We can use only 2s to form n
            if (n % 2 == 0)
            {
                cout << "YES\n";

                // Number of integers used = n / 2
                cout << n / 2 << "\n";

                for (int i = 0; i < n / 2; i++)
                {
                    cout << 2 << " ";
                }
                cout << "\n";
            }
            else
            {
                // n is odd and 1 is forbidden
                // To make an odd sum, we need at least one odd number
                // The smallest odd number possible is 3

                // If k < 3, then 3 is not available
                // Only 2s exist → cannot make odd sum
                if (k < 3)
                {
                    cout << "NO\n";
                }
                else
                {
                    // We can use one 3 to handle oddness
                    // Remaining sum becomes (n - 3), which is even
                    // Fill the rest using 2s

                    cout << "YES\n";

                    // Count = 1 (for 3) + (n - 3) / 2 (number of 2s)
                    cout << (n - 3) / 2 + 1 << "\n";

                    cout << 3 << " ";
                    for (int i = 0; i < (n - 3) / 2; i++)
                    {
                        cout << 2 << " ";
                    }
                    cout << "\n";
                }
            }
        }
    }

    return 0;
}