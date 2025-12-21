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

// Space Complexity Analysis:
// Max depth of recursion tree = n
// Space per call = O(1)
// SC = (max depth of recursion tree)*(space per call)
// Therefore Space Complexity is O(n)

// Example 2: Factorial of N
int factorial(int n) {
    if (n == 0) {
        return 1;
    }

    return n * factorial(n - 1);
}
// Time Complexity Analysis:
// T(n) = T(n-1) + O(1)
// Time Complexity is O(n)
// Space Complexity Analysis:
// Space Complexity is O(n)

// Example 3: Fibonacci of N
int fibonacci(int n) {
    if (n == 1 || n == 0) {
        return n;
    }

    return fibonacci(n - 1) + fibonacci(n - 2);
}
// Time Complexity Analysis:
// T(n) = T(n-1) + T(n-2) + O(1)
// Drawing Recurrence Tree, we can see that the number of calls grows exponentially
// Therefore Time Complexity is O(2^n)

// Space Complexity Analysis:
// Max depth of recursion tree = n
// Space Complexity is O(n)


// Master's Theorem:
// Used in solving recurrences of the form:
// T(n) = aT(n/b) + f(n)
// where a >= 1, b > 1, and f(n) is an asymptotically positive function
// Case 1: If f(n) = O(n^(log_b(a) - ε)) for some ε > 0, then T(n) = Θ(n^(log_b(a)))
// Case 2: If f(n) = Θ(n^(log_b(a)) * log^k(n)) for some k >= 0, then T(n) = Θ(n^(log_b(a)) * log^(k+1)(n))
// Case 3: If f(n) = Ω(n^(log_b(a) + ε)) for some ε > 0, and af(n/b) <= cf(n) for some c < 1 and sufficiently large n, then T(n) = Θ(f(n))