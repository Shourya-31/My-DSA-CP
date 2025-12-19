// Tiling Problem: Given a 2 x N board and tiles of size 2 x 1, count the number of ways to tile the board.
// Time Complexity: O(2^N) Exponential
// Space Complexity: O(N) for the recursion stack
// DP gives most optimal solution but here we will solve using recursion

// Approach:

// 1. If we place a tile vertically, we are left with a 2 x (n-1) board.
// And in it will be 2 ways to place remaining tiles. 
// a.) Place remaining tiles vertically
// b.) Place remaining tiles horizontally   
// 2. If we place two tiles horizontally, we are left with a 2 x (n-2) board.

// Therefore, the Clarity must be:
// What work is being done in each recursive call?
// In each recursive call, we are reducing the problem size by either 1 or 2
// To place thee tile either vertically or horizontally


// And the Base Case must be:
// If n == 0 or n == 1, return 1
// For n == 0, there is one way to tile the board (do nothing)
// For n == 1, there is one way to tile the board (place one tile vertically)

// Recursive Relation: 
// T(n) = T(n-1) + T(n-2) => Taking solutions of both the cases

// Solution Code:
#include <iostream>
using namespace std;

int tilingProblem(int n) {
    // Base Case
    if (n == 0 || n == 1) {
        return 1;
    } else {
        int tp1 = tilingProblem(n - 1); // Place tile vertically
        int tp2 = tilingProblem(n - 2); // Place tile horizontally

        return tp1 + tp2; // Total ways
    }
}
    

int main() {
    int n;
    cin>>n;
    cout << tilingProblem(n) << endl;
    return 0;
}