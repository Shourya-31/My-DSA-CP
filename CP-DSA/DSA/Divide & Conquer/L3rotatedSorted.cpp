// Search in Rotated SOrted Array:
// An array was there, with distinct numbers
// then w.r.t. a pivot, it was rotated and finally a new array was formed
// We have to search for a key in the new array

// We can go with Linear Search but the TC will be O(n)
// Therefore for better TC we will go by Modified Binary Search with TC: O(log n)
// Now for this, Binary Search will need a completely sorted array, either in ascending or descending order

// Steps:
// 1.) mid nikalo => (si+ei)/2
// 2.) if arr[mid]==target key then return arr[mid]
// 3.) Now the given array will be divided into 2 parts, the starting of first part will be si
// and the ending of 2nd part will be ei

// Now:
// Case:1 => Case a: arr[si]<=key<=arr[mid], then we will move left
//           Case b: arr[si]<=key<=arr[mid] => False then we will move rightwards
// Case:2 => Case c: arr[mid]<=key<=arr[ei], then we will move rightwards
//           Case d: arr[mid]<=key<=arr[ei] => False then we will move left

// For deciding where mid lies: arr[si]<=mid

#include <bits/stdc++.h>
using namespace std;

int search(int arr[], int si, int ei, int key){
    if(si>ei){
        return -1;
    }

    int mid = (si+ei)/2;
    if(arr[mid] == key){
        return mid;
    }

    if(arr[si] <= arr[mid]){
        //L1
        if(arr[si] <= key && key <= arr[mid]){
            //left
            return search(arr, si, mid-1,key);
        } else{
            //right half
            return search(arr,mid+1,ei,key);
        }
    } else{
        //L2
        if(arr[mid] <= key && key <= arr[ei]){
            //right half
            return search(arr, mid+1, ei, key);
        } else{
            //left half
            return search(arr, si, mid-1, key);
        }
    }
}

// void printArr(int arr[], int n){
//     for(int i=0; i<n; i++){
//         cout<<arr[i]<<" ";
//     }
//     cout<<endl;
// }

int main() {
    int n;
    cout<<"Enter size of array: ";
    cin>>n;

    int arr[n];
    cout<<"Enter elements of array: ";
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    int k;
    cout<<"Enter target key: "<<endl;
    cin>>k;

    cout<<"idx: "<<search(arr,0,n-1,k)<<endl;
    return 0;
}