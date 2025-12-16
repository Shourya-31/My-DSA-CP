// Question: Check if array is sorted using recursion

#include<iostream>
using namespace std;

bool isSorted(int arr[], int n, int i) {
    if(i == n-1) {
        return true;
    }

    if(arr[i]>arr[i+1]) {
        return false;
    }

    return isSorted(arr, n, i+1);
}

int main () {
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    bool ans = isSorted(arr, n, 0);
    if(ans) {
        cout<<"Array is sorted";
    } else {
        cout<<"Array is not sorted";
    }

    return 0;
}