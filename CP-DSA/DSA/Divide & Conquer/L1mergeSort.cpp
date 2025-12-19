// Divide & Conquere:
// A recursive algorithm to split a bigger probelm into smaller sub-problems until they become simple enough to be solved directly.

// Merge Sort Algorithm: An efficient, stable sorting algorithm that follows the divide and conquer paradigm.
// Time Complexity: O(n log n) in all cases (best, average, worst).
// Space Complexity: O(n) due to the temporary arrays used for merging.

// Approach:
// 1. Divide the unsorted array into n subarrays, each containing one element (a single element is considered sorted).
// 2. Repeatedly merge subarrays to produce new sorted subarrays until there is only one subarray remaining, which will be the sorted array.

// We will write a merge function to merge 2 sorted halves of an array.
// We will take 2 iterators, one for start of first half and other for start of second half.
// We will create a temporary array to store the merged result and then copy it back to the original array.
// We will compare elements from both halves and insert the smaller element into the temporary array.

#include <bits/stdc++.h>
using namespace std;

void merge(int arr[], int si, int mid, int ei){
    vector<int> temp;
    int i = si; // iterator for left half
    int j = mid+1; // iterator for right half

    while(i <= mid && j <= ei){
        if(arr[i] <= arr[j]){
            temp.push_back(arr[i++]);
        } else{
            temp.push_back(arr[j++]);
        }
    }

    while(i <= mid){
        temp.push_back(arr[i++]);
    }
    while(j <= ei){
        temp.push_back(arr[j++]);
    }

    // Finally copy the sorted temp array to original array
    for(int idx = si, x = 0; idx <= ei; idx++){
        arr[idx]=temp[x++];
    }
}

void mergeSort(int arr[], int si, int ei) {
    if(si >= ei){
        return;
    }
    int mid = (si+ei)/2; // si + (ei-si)/2

    mergeSort(arr,si,mid); //left sort
    mergeSort(arr,mid+1,ei); //right sort

    merge(arr,si,mid,ei); //merge both halves => Conquer
    // A Recursive function to divide the array into halves until single element is left
}

void printArr(int arr[], int n){
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main() {
    int n;
    cout<<"Enter size of array: ";
    cin>>n;

    int arr[n];
    cout<<"Enter elements of array: ";
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    mergeSort(arr,0,n-1);
    cout<<"Sorted array: ";
    printArr(arr,n);
    return 0;
}