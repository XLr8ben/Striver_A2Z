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
// A peak element in an array refers to the element that is greater than both of its neighbors. Basically, if arr[i] is the peak element, arr[i] > arr[i-1] and arr[i] > arr[i+1].
// Now if we want to visualize an array with the peak elements from the graphical point of view, there can be 4 cases:
// Case 1: An array with a single peak number:
// Case 2: An array with multiple peaks:
// Case 3: Last element as peak element:
// Case 4: First element as peak element:
// The brute force approach to find peak element is to traverse the entire array and compare the current element with both of its neighbours. If it is greater than both of its neighbours we can simply return it as our peak element.
// For the elements at first and last index, since both the neighbours are not available, we can just check their only neighbour element and return if its a peak element or not.

// Time Complexity: O(N), we traverse the entire array once to find peak element.
// Space Complexity: O(1), constant additional space is used.

// int Solution(vector<int>& arr, int n){  
    
//     for(int i=0;i<n;i++){
//         if((i==0 || arr[i]>arr[i-1]) && (i==n-1 || arr[i]>arr[i+1])) return i;
//     }
//     return -1;
// }

// Optimal Approach
// Algorithm
// To optimize our solution even further, we can use binary search algorithm. The primary objective of the Binary Search algorithm is to efficiently determine the appropriate half to eliminate, thereby reducing the search space by half. It does this by determining a specific condition that ensures that the target is not present in that half.

// To know how to eliminate the half efficiently, we can clearly notice a striking distinction between the left and right halves of the peak element in the array. The left half of the peak element has an increasing order whereas the right half of the peak element has a decreasing order.

// Thus we know that if current element is greater than its left neighbour, we are in the left half and if our current element is greater than its right neighbour then we are in the right half. If we know the half that we are in currently, we can eliminate it to find our peak element.

// In addition to the two cases above, we can have two more cases. One, where the current element itself is the peak or where the current element is a common point where a decreasing sequence ends and an increasing sequence begins. In either cases we can eliminate any of the halves, as the other half will also contain a peak element.
// Initialize the search space to the full range of the array.
// Find the middle index of the current search range.
// Check if the middle element is greater than its right neighbor.
// If yes, then a peak must exist in the left half (including mid), so shrink the right bound.
// Otherwise, the peak must lie in the right half (excluding mid), so shift the left bound.
// Continue until the search space converges to a single element.
// This final position is the index of a peak element.

// Time Complexity: O(log N), we reduce the search space to half at every step using binary search.
// Space Complexity: O(1), constant additional space is used.

int Solution(vector<int>& arr, int n){
    if(n==1) return 0;
    if(arr[0] > arr[1]) return 0;
    if(arr[n-1] > arr[n-2]) return n-1;

    int low = 1, high = n-2;

    while(low<=high){
        int mid = low + (high - low) / 2;

        if(arr[mid - 1] < arr[mid] && arr[mid] > arr[mid + 1] ) return mid;
        else if(arr[mid - 1] < arr[mid]) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
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
