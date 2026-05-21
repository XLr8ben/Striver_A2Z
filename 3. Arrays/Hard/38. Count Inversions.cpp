#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <math.h>
#include <algorithm>
#include <unordered_map>
using namespace std;

// Brute Force Approach
// Algorithm
// An inversion in an array is defined as a pair of indices (i, j) such that i < j and a[i] > a[j]. This measures how far the array is from being sorted. To count inversions, the brute force way is to compare every element with all elements to its right and increment the counter whenever we find an inversion.

// Initialize a counter cnt = 0.
// Use two nested loops:
// Outer loop runs for each element a[i].
// Inner loop checks all elements a[j] where j > i.
// If a[i] > a[j], increment cnt.
// After traversing all pairs, return cnt as the number of inversions.

// Time Complexity: O(N2), as every pair is checked.
// Space Complexity: O(1), since no extra space is used apart from variables.

// int Solution(vector<int>& arr, int n){
//     int cnt=0;

//     for(int i=0;i<n;i++){
//         for(int j=i+1;j<n;j++){
//             if(arr[i]>arr[j]) cnt++;
//         }
//     }
//     return cnt;
// }

// Optimal Approach
// Algorithm
// The brute force approach compares all pairs, but that takes O(N2) time. We can optimize this using the merge sort algorithm. While merging two sorted halves, if an element in the left half is greater than an element in the right half, then all remaining elements in the left half will also be greater than that right element. This allows us to count multiple inversions in one step, instead of checking each pair individually.

// Apply merge sort recursively to divide the array into two halves.
// During the merge step:
// If arr[left] <= arr[right], place arr[left] into the temp array and move left++.
// Otherwise, place arr[right] into the temp array. Since arr[left] > arr[right], all elements from arr[left] to arr[mid] form inversions with arr[right]. So add (mid - left + 1) to the inversion count.
// Copy the merged elements back into the original array.
// The total inversion count is the sum of:
// Inversions in the left half
// Inversions in the right half
// Inversions across the halves (counted during merge)

// Time Complexity: O(N log N), since it is based on merge sort.
// Space Complexity: O(N), for the temporary array used during merging.

int merge(vector<int>& arr, int low, int mid, int high){
    vector<int> temp;
    int cnt=0;

    int left=low, right=mid+1;

    while(left<=mid && right<=high){
        if(arr[left]<=arr[right]){
            temp.push_back(arr[left]);
            left++;
        }else{
            temp.push_back(arr[right]);
            cnt += (mid-left+1);
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
    return cnt;
}

int mergeSort(vector<int>& arr, int low, int high){
    if(low>=high) return 0;
    
    int ans=0;

    int mid = low + (high - low) / 2;

    ans += mergeSort(arr, low, mid);
    ans += mergeSort(arr, mid+1, high);

    ans += merge(arr, low, mid, high);

    return ans;
}

int Solution(vector<int>& arr, int n){
    return mergeSort(arr, 0, n-1);
}

int main()
{
    int n;
    cin>>n;
    vector<int> arr(n);

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    cout<<Solution(arr, n)<<endl;

    return 0;
}
