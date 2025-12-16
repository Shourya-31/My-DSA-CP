// Question: First Occurance of an element in an array using recursion

#include <iostream>
#include <vector>
using namespace std;

int firstOccurance(vector<int> arr, int i, int key) {
    if (i == arr.size()) {
        return -1;
    }

    if(arr[i] == key) {
        return i;
    }

    return firstOccurance(arr, i+1, key);
}

int lastOccurance(vector<int> arr, int i, int key) {
    if(i ==  arr.size()) {
        return -1;
    }

    int idxFOund = lastOccurance(arr, i+1, key);
    if(idxFOund == -1 && arr[i] == key) {
        return i;
    }

    return idxFOund;
}

int main() {
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n;i++){
        cin>>arr[i];
    }

    cout<<"Enter the key to search: ";
    int key;
    cin>>key;
    // int ans = firstOccurance(arr, 0, key);
    // cout<<ans;
    int ans = lastOccurance(arr, 0, key);
    cout<<ans;
    return 0;
}