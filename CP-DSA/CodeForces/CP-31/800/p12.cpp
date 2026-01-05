// Approach
// She writes down only those ai (2≤i≤m) such that ai−1≤ai
// Let the length of this sequence be denoted as n
// Therefore a2 >= a1 and so on
// So if in sequence: [a1,a2,a3,a4,a5]
// Vika has to make it work in her formula then we will consider from array A only
// And wont look for the formula to work in Array B

// Solution
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        long long n;
        cin >> n;

        vector<long long> B(n);
        for (int i = 0; i < n; i++)
        {
            cin >> B[i];
        }

        vector<long long> A;

        A.push_back(B[0]); // a1 is always there

        for (int i = 1; i < n; i++)
        {
            if (B[i] >= B[i - 1])
            {
                A.push_back(B[i]);
            }
            else
            {
                A.push_back(B[i]);
                A.push_back(B[i]);
            }
        }

        cout << A.size() << endl;

        for (long long x : A)
        {
            cout << x<<" ";
        }

        cout << "\n";
    }
    return 0;
}
