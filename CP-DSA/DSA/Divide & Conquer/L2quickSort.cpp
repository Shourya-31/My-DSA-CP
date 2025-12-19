// Quick Sort
// Time Complexity: O(n log n) on average, O(n^2) in the worst case
// Space Complexity: O(log n) due to recursive stack space

// Pivot & Partitioning Approach
// 1. Choose a pivot element from the array.
// 2. Partition the array into two sub-arrays: elements less than the pivot and elements greater than the pivot.
// 3. Recursively apply the above steps to the sub-arrays.
// 4. Combine the sorted sub-arrays and the pivot to get the final sorted array.
// 5. The base case for the recursion is when the array has one or zero elements, which are inherently sorted.
// 6. This implementation uses the last element as the pivot.

// For partinioning:
// 1. Initialize a pointer from start - 1 to keep track of the position of the smaller element.
// This will reallocate the left side of the array with elements smaller than the pivot.
// 2. Iterate through the array from start to end - 1.
// 3. If the current element is smaller than the pivot, increment the pointer and swap the current element with the element at the pointer.
// 4. Finally, swap the pivot with the element at the pointer to place it in its correct position.
// 5. Return the pointer index as the partitioning index.

#include <bits/stdc++.h>
using namespace std;

int partition(int arr[], int si, int ei){

// Function to rearrange the array from index si to ei

// Goal:

// Put the pivot in its correct sorted position

// Elements ≤ pivot on the left

// Elements > pivot on the right

// Returns the final index of the pivot

    int i = si-1;
    // i tracks the last index of the “smaller than pivot” region
    int pivot = arr[ei];
    // We choose the last element as the pivot

    for(int j=si; j<ei; j++){
        if(arr[j]<=pivot){
            i++;
            swap(arr[i], arr[j]);
            // Place arr[j] into the correct smaller region
        }
    }

    i++;
    swap(arr[i],arr[ei]);
    // Place arr[j] into the correct smaller region

    // pivotIdx = i
    return i;
}

void quickSort(int arr[], int si, int ei){
    if(si>=ei){
        return;
    }
    int pivotIdx = partition(arr,si,ei);

    quickSort(arr,si,pivotIdx-1); // left part
//  Sort only the part left of the pivot

//  This subarray contains all elements ≤ pivot

//  The pivot itself is excluded because it’s already correct

    quickSort(arr,pivotIdx+1,ei); // right part
//  Sort only the part right of the pivot

//  This subarray contains all elements > pivot

//  Pivot is excluded again
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

    quickSort(arr, 0, n-1);
    cout<<"Sorted array: ";
    printArr(arr,n);
    return 0;
}

// Why Time Complexity in Worst Case is O(n^2):
// When the pivot is repeatedly a smallest/largest element of the array
// As we will need to check all the elements, therefore the operations will be sum of first n natural numbers
// Which implies Time Complexity will be O(n^2)
// This is not encountered much so Quick sort is a nice algorithm