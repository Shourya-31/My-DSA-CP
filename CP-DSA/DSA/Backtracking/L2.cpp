// Backtracking on Array:

#include <bits/stdc++.h>
using namespace std;

void printArr(int arr[], int n){
    for(int i = 0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void changeArr(int arr[], int n, int i){
    if(i == n){
        printArr(arr, n);
        return;
    }

    arr[i]=arr[i]+1;
    changeArr(arr, n, i+1);
    arr[i] -= 2;
}

int main(){
    int arr[5] = {0,1,2,3,4};
    int n = 5;
    changeArr(arr, n, 0);
    printArr(arr, n);
    return 0;
}