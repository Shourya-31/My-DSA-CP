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

