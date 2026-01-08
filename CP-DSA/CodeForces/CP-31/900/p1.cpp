// Solution
#include <bits/stdc++.h>
using namespace std;

// dx and dy are NOT moves themselves.
// They only represent sign combinations:
// (-,-), (+,-), (-,+), (+,+)
int dx[4] = {-1, 1, -1, 1};
int dy[4] = {-1, -1, 1, 1};

int main()
{
    int t;
    cin >> t;  // number of test cases

    while (t--)
    {
        int a, b;
        cin >> a >> b;  // knight move lengths

        int xk, yk;
        cin >> xk >> yk;  // king position

        int xq, yq;
        cin >> xq >> yq;  // queen position

        // king_hits will store all board positions
        // where a knight can be placed such that it attacks the king
        set<pair<int,int>> king_hits;

        // queen_hits will store all board positions
        // where a knight can be placed such that it attacks the queen
        set<pair<int,int>> queen_hits;

        // Loop over 4 sign combinations
        for(int j = 0; j < 4; j++)
        {
            // ---- KING PART ----
            // If a knight is at (xk + dx[j]*a, yk + dy[j]*b),
            // it can move (±a, ±b) and land on the king
            king_hits.insert({xk + dx[j] * a, yk + dy[j] * b});

            // If a knight is at (xk + dx[j]*b, yk + dy[j]*a),
            // it can move (±b, ±a) and land on the king
            king_hits.insert({xk + dx[j] * b, yk + dy[j] * a});

            // ---- QUEEN PART ----
            // Same logic as above, but centered around the queen
            queen_hits.insert({xq + dx[j] * a, yq + dy[j] * b});
            queen_hits.insert({xq + dx[j] * b, yq + dy[j] * a});
        }

        int ans = 0;  // number of valid fork positions

        // Go through every square from which the knight attacks the king
        for(auto position : king_hits)
        {
            // queen_hits.find(position) checks whether the SAME square
            // also exists in queen_hits
            //
            // If found:
            //   - a knight placed at this square attacks the king
            //   - AND attacks the queen
            //
            // queen_hits.end() means "not found"
            if(queen_hits.find(position) != queen_hits.end())
            {
                ans++;  // this square is a valid fork position
            }
        }

        // Print how many such squares exist
        cout << ans << endl;
    }

    return 0;
}

// find(position) looks for that exact (x, y) pair

// It does not loop like a for

// It does a fast tree lookup

// What does find(position) return?

// If position exists in queen_hits
// → returns an iterator pointing to that element

// If position does NOT exist
// → returns queen_hits.end()

// What does queen_hits.end() mean?

// It is a special marker

// It means: “past the last element”

// It is commonly used to indicate “not found”
