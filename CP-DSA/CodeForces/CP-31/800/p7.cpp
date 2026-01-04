/*
A. Don't Try to Count

Time Limit: 2 seconds
Memory Limit: 256 megabytes

------------------------------------------------------------

You are given:
- A string x of length n
- A string s of length m

Constraint:
n * m ≤ 25

Both strings consist of lowercase Latin letters.

------------------------------------------------------------

Operation:
In one operation, you append the current value of string x
to the end of x itself.

Note:
The value of x changes after each operation.

Example:
x = "aba"
After operations:
"aba" -> "abaaba" -> "abaabaabaaba"

------------------------------------------------------------

Task:
Determine the minimum number of operations after which
string s appears in x as a substring.

A substring is a contiguous segment of a string.

If it is impossible for s to appear in x,
output -1.

------------------------------------------------------------

Input:
- The first line contains an integer t (1 ≤ t ≤ 10^4),
  the number of test cases.

For each test case:
- One line with two integers n and m (1 ≤ n * m ≤ 25)
- One line with string x of length n
- One line with string s of length m

------------------------------------------------------------

Output:
For each test case, output a single integer:
- The minimum number of operations required
- Or -1 if it is not possible

------------------------------------------------------------

Example Input:
12
1 5
a
aaaaa
5 5
eforc
force
2 5
ab
ababa
3 5
aba
ababa
4 3
babb
bbb
5 1
aaaaa
a
4 2
aabb
ba
2 8
bk
kbkbkbkb
12 2
fjdgmujlcont
tf
2 2
aa
aa
3 5
abb
babba
1 19
m
mmmmmmmmmmmmmmmmmmm

------------------------------------------------------------

Example Output:
3
1
2
-1
1
0
1
3
1
0
2
5

------------------------------------------------------------
*/

// Solution:
#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        string x, s;
        cin >> x >> s;

        int ans = -1;

        for (int ops = 0; ops <= 10; ops++) {
            if (x.find(s) != -1) {
                ans = ops;
                break;
            }
            x += x;
        }

        cout << ans << '\n';
    }
    return 0;
}