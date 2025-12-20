// Time Complexity:
// This is the amount of time taken by an algorithm as a function of input size (n).
// Measured in number of operations or steps taken to complete the task.

// Constant Time Complexity: O(1)
// The execution time remains constant regardless of the input size.
// Example: Accessing an element in an array by index.
// Actually one of the best time complexities.
// A good time complexity aims for lesser number of operations as n increases.

// Big O Notation:
// A mathematical notation used to describe the upper bound of an algorithm's time complexity.
// Upper Bound means the worst-case scenario for an algorithm's growth rate.
// Isse zada to nhi hogi, lekin kam ho sakti hai.
// Worst case me save kar liya to best case me apne aap safe ho jayega
// Calculating Big O Notation involves identifying the dominant term in the time complexity expression
// and ignoring constant factors and lower-order terms.
// Example: If an algorithm has a time complexity of 3n^2 + 5n + 2, its Big O notation is O(n^2).
// Because as n grows larger, n^2 grows faster than n or any constant.
// Example: logn+n^3 => O(n^3)

// Mathematical Formula for Time Complexity:
// Limit as n approaches infinity of T(n)/f(n) = C
// Where T(n) is the time complexity of the algorithm, f(n) is a function representing the growth rate, and C is a constant greater than 0.
// If the limit results in a finite constant C, then T(n) is O(f(n)).
// Example: T(n) = 3n^2 + 5n + 2
// Let's choose f(n) = n^2
// Limit as n approaches infinity of (3n^2 + 5n + 2) / n^2 = Limit as n approaches infinity of (3 + 5/n + 2/n^2) = 3
// Since the limit results in a finite constant (3), we can conclude that T(n) is O(n^2).

// Big Omega Notation: (Ω) => Best Case
// A mathematical notation used to describe the lower bound of an algorithm's time complexity.

// Big Theta Notation: (Θ) => Average Case
// A mathematical notation used to describe the tight bound of an algorithm's time complexity.

// Space Complexity:
// This is the amount of memory space taken by an algorithm as a function of input size (n).
// 
//