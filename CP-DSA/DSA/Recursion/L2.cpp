// Recursion in Memory => Function calls are stored in a call stack in memory
// When a function is called, its parameters and local variables are pushed onto the call stack
// When the function returns, its data is popped from the stack

// Example 1: Print numbers from n to 1 using recursion
#include <iostream>
using namespace std;

void print(int n){
    if(n == 0){
        return;
    }

    cout<<n<<" ";
    print(n-1);
}

int main() {
    int n;
    cin>>n;
    print(n);
    return 0;
}