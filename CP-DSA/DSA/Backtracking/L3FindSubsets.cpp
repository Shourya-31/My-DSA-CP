// Find & print all subsets of a set of a given string using backtracking
// Approach: At every character we have two choices either to include it in the current subset or exclude it.
// So we recurse and backtrack for every character in the string.
// Making a W shaped pattern.

// f(string str, string subset){
//     ch = str[0]
//   f(str.substr(1,n-1), subset + ch) // include
//   f(str.substr(1,n-1), subset)      // exclude
// }

// f(string str, string subset){

// Base idea:
// str     -> remaining characters to process
// subset  -> subset formed so far

// Take the first character of the string
// ch = str[0]

// Recursive call 1: INCLUDE the character
// Add ch to subset and process the remaining string
// f(str.substr(1), subset + ch)

// Recursive call 2: EXCLUDE the character
// Do not add ch to subset, just process the remaining string
// f(str.substr(1), subset)

// }

// Base Case: when str is empty print the subset.

#include <bits/stdc++.h>
using namespace std;

void printSubsets(string str, string subset){
    if(str.size() == 0){
        cout<<subset<<"\n";
        return;
    }

    char ch = str[0];

    //yes choice
    printSubsets(str.substr(1,str.size()-1), subset + ch);

    //no choice
    printSubsets(str.substr(1,str.size()-1), subset);
}

int main(){
    string str = "abc";
    string subset = "";

    printSubsets(str, subset);
    return 0;
}

// Sabse pehele YES choices aayengi phir NO choices aayengi.
// Time Complexity: O(2^n) where n is the length of the string.
// Reccurance relation: T(n) = 2*T(n-1) + O(1)

// Space Complexity: O(n) for the recursion stack.