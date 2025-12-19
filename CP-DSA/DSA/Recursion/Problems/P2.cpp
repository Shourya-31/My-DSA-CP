// Remove Duplicates in String using Recursion
// For example, for input string "aabbcc", the output should be "abc"

// We will analyze the problem step by step:
// 1. What work is being done in each recursive call?
// In each recursive call, we will check the first character of the string
// and see if it is already present in the result string formed so far.     

// 2. What is the base case?
// The base case will be when the input string is empty.
// In that case, we will return the result string formed so far.

// Recursive Relation:
// We will make a recursive call by removing the first character of the input string

// To track if the character is already present in the result string
// We will make a boolean array of size 26 (for lowercase letters) initialized to false
// When we encounter a character, we will mark its corresponding index in the boolean array as true
// If we encounter the character again, we will skip it

// map[i] = true indicates that character 'a' + i is already present in the result string, in that case we will skip it
// else we will include it in the result string and mark map[i] = true

#include <bits/stdc++.h>
using namespace std;

void removeDuplicates(string str, string ans, int i, int map[26]){
    if(i == str.length()){
        cout<<"Ans: "<<ans<<endl;
        return;
    }

    char ch = str[i];
    int mapIdx = (int)(ch - 'a'); // a => 0, b => 1, c => 2 ...

    if (map[mapIdx] == true) { // Duplicate found
        removeDuplicates(str, ans, i + 1, map); // skip the character
    } else { // Not a duplicate
        map[mapIdx] = true;
        removeDuplicates(str, ans + str[i], i + 1, map); // include the character
    }
}

int main() {
    string str;
    cin>>str;
    string ans = "";
    int map[26] = {false}; // Initialize all to false
    removeDuplicates(str, ans, 0, map);
    return 0;
}

// Similarly, we can solve by going from end to start of the string
// In that case, we will build the result string in reverse order