#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <math.h>
using namespace std;

// Merge Sort Algorithm
// Algorithm
// Merge Sort is a classic divide and conquer algorithm. The core idea is based on breaking down a big problem into smaller, manageable sub-problems i.e. sorting smaller arrays and then merging those solutions to get the final sorted result.

// It is much easier to merge two sorted arrays than to sort a large unsorted one. Therefore, instead of trying to sort the entire array at once, Merge Sort breaks it into halves repeatedly until we reach arrays of size 1 (which are trivially sorted), and then merges them back in sorted order. This makes the algorithm efficient and predictable, especially for large datasets.
// If the array has only one or zero elements, it is already sorted, so we return it as is.
// Else, we divide the array into two halves by finding the middle index.
// We then apply the merge sort algorithm recursively on each of the two halves to sort them individually.
// Once we have two sorted halves, we need to merge them into a single sorted array.
// To merge, we compare elements from both halves one by one and place the smaller element into a new array, continuing this until all elements from both halves are used.
// This process is repeated at every level of recursion, and finally, we get one fully sorted array after all merges are complete.

// Time Complexity: O(N*logN), merging two arrays take linear time and array is recursively divided into halves (logN times).
// Space Complexity: O(N), we use a temporary array to store elements in sorted order.

void merge(vector<int>& arr, int low, int mid, int high){
    vector<int> temp;

    int left=low, right=mid+1;

    while(left<=mid && right<=high){
        if(arr[left]<=arr[right]){
            temp.push_back(arr[left]);
            left++;
        }else{
            temp.push_back(arr[right]);
            right++;
        }
    }

    while(left<=mid){
        temp.push_back(arr[left]);
        left++;
    }
    while(right<=high){
        temp.push_back(arr[right]);
        right++;
    }

    for(int i=low;i<=high;i++){
        arr[i] = temp[i-low];
    }
}

void mergeSort(vector<int>& arr, int low, int high){
    if(low>=high) return;

    int mid = (low + high) / 2;

    mergeSort(arr, low, mid);

    mergeSort(arr, mid+1, high);

    merge(arr, low, mid, high);

}

int main()
{
    int n;
    cin>>n;
    vector<int> arr(n);

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    mergeSort(arr, 0, n-1);

    for(int ele: arr){
        cout<<ele<<" ";
    }

    return 0;
}
