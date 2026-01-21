#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t; 

    while (t--)
    {
        long long a, b;
        cin >> a >> b;

        if (a == b)
            // If both numbers are equal:
            // gcd(a, b) = a = b
            // They are already at maximum excitement
            // No operations needed
            cout << 0 << " " << 0 << "\n";

        if (b > a)
            // Ensure a >= b
            // This makes (a - b) non-negative and simplifies logic
            swap(a, b);

        if (a != b)
        {
            // Now we are sure a > b

            long long gcd = a - b;
            // Key observation:
            // When we increment or decrement both numbers equally,
            // the difference (a - b) stays constant.
            // Any future gcd(a+k, b+k) must divide (a - b).
            // So the maximum possible gcd is (a - b).

            long long moves = min(b % gcd, gcd - b % gcd);
            // We want to make b divisible by (a - b)
            // Because then:
            // gcd(a + k, b + k) = (a - b)

            // b % gcd  -> steps to decrease b to nearest multiple
            // gcd - (b % gcd) -> steps to increase b to next multiple
            // We choose the minimum moves needed

            cout << gcd << " " << moves << "\n";
            // Print:
            // 1) Maximum achievable gcd (excitement)
            // 2) Minimum number of operations needed to reach it
        }
    }
}
