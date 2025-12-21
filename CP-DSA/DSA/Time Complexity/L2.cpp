// Recursiin in Time COmplexity:

// Approach 1: 
// total work done = (recursive calls)*(work done in each call)

// Approach 2: Recurrence Tree Method
// Write Recurrence Relation

// Space Complexity of Recursion:
// Depends on call stack size
// Each recursive call adds a new layer to the call stack
// (max depth of recursion tree)*(space per call)

// Example 1: Sum of N numbers
int sum(int n) {
    if (n == 0){
        return 0;
    }

    return n + sum(n - 1);
}

// Time Complexity Analysis:
// T(n) = T(n-1) + O(1)
// T(n-1) => time taken to compute sum(n-1)
// O(1) => time taken for addition and function call overhead
// Base Case: T(0) = O(1)

// TC = total work done = (number of calls)*(work done in each call) 
// => n*O(1) = O(n)
// Therefore Time Complexity is O(n)