// Solution
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t; 
    cin >> t; // Number of test cases

    while (t--)
    {
        int x, y, c, d;
        cin >> x >> y >> c >> d; 
        // (x, y) = starting point
        // (c, d) = destination point

        // If destination y is smaller than current y
        // Because y can ONLY increase using diagonal moves,
        // going down in y is impossible
        if (d < y)
        {
            cout << -1 << endl;
            continue;
        }

        // Number of diagonal moves needed to raise y from y to d
        // Each diagonal move increases y by 1
        int moves = d - y;

        // Each diagonal move also increases x by 1
        x = x + moves;

        // After raising y, if x is still less than c,
        // we cannot increase x anymore (only left moves exist)
        if (x < c)
        {
            cout << -1 << endl;
            continue;
        }

        // Now x >= c
        // To reduce x to c, we use left moves
        // Each left move reduces x by 1
        moves = moves + (x - c);

        // Total minimum moves
        cout << moves << endl;
    }

    return 0;
}