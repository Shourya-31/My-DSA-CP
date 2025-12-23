// Find Permutations of a given string using backtracking
// Example: str = "abc"
// Output: abc, acb, bac, bca, cab, cba => 6 permutations = n!

// Pseudo Code:
// f(str, ans){
// base case = if str is empty print ans and return
//    for(i=0; i<str.size(); i++){
//        ch = str[i]
//        f(del str[i], ans + ch) => remove ch from str and add it to ans
// }

#include <bits/stdc++.h>
using namespace std;

void permutations(string str, string ans)
{
    if (str.size() == 0)
    {
        cout << ans << "\n";
        return;
    }

    for (int i = 0; i < str.size(); i++)
    {
        char ch = str[i];
        // "abcdefghilu", i = 2 => "ab"+"defghilu" => str.substr(0,i)+str.substr(i+1,str.size()-i-1);
        string nextStr = str.substr(0, i) + str.substr(i + 1, str.size() - i - 1);
        permutations(nextStr, ans + ch); // ith char choice to add in permutation
    }
}

int main() {
    string str = "abcde";
    string ans = "";
    permutations(str, ans);
    return 0;
}