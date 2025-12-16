// Recursion => Function that calls itself repeatedly until a base condition is met
// Mathematical Example => Factorial of a number n is represented as n! and is calculated as:
// n! = n * (n-1)! where (n-1)! is the factorial of (n-1)

#include <iostream>
using namespace std;

int factorial(int n){
    if(n==0){
        return 1;
    }

    return n*factorial(n-1);
}

int main() {
    int ans = factorial(5);
    cout<<ans;
    return 0;
}

// It is a method of solving computational problems where the solution depends on solutions to smaller instances of the same problem.
// We must know:
// 1. Base Condition => The condition under which the recursion ends
// 2. Recursive Relation => The relation in which the function calls itself with modified parameters
// 3. Work done in each call => The operations performed in each function call