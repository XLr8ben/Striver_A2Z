#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <math.h>
using namespace std;

// Quick Sort
// Algorithm
// The core idea behind Quicksort lies in partitioning the array around a pivot element such that all elements smaller than the pivot lie to its left and all greater elements lie to its right. This positioning ensures that the pivot is in its correct sorted place. By doing this for each recursive call, the problem is broken down into smaller subproblems where each side of the pivot can be independently sorted. This divide-and-conquer strategy allows Quicksort to sort parts of the array separately.
// Select a pivot element from the array (commonly the last element, but can be first, middle, or random).
// Rearrange the elements in the array such that all elements smaller than the pivot are placed before it and all greater elements are placed after it (this step is called partitioning).
// After partitioning, the pivot is in its correct sorted position.
// Recursively apply the same process to the subarrays on the left and right of the pivot.
// Base condition for recursion is when the subarray has zero or one element, as it's already sorted.
// Combine the results of the recursive calls to obtain the fully sorted array.

// Time Complexity: O(N*logN), At each step, we divide the whole array, for that we take logN time and n steps are taken for the partitioning. In worst case i.e. when our pivot is always the greatest or the smallest element of the array, the time complexity can be O(N^2).
// Space Complexity: O(N), auxiliary stack space.

int partition(vector<int>& arr, int low, int high){
    int pivot = arr[low];

    int i=low, j=high;

    while(i<j){
        while(arr[i]<=pivot && i<high){
            i++;
        }
        while(arr[j]>pivot && j>low){
            j--;
        }

        if(i<j){
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[low], arr[j]);
    
    return j;    
}


void quicksort(vector<int>& arr, int low, int high){
    if(low>=high) return;

    int pivotIdx = partition(arr, low, high);

    quicksort(arr, low, pivotIdx-1);

    quicksort(arr, pivotIdx+1, high);
    
}

int main()
{
    int n;
    cin>>n;
    vector<int> arr(n);

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    quicksort(arr, 0,  n-1);
    
    for(int ele: arr){
        cout<<ele<<" ";
    }

    return 0;
}
