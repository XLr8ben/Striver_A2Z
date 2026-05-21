#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <math.h>
using namespace std;


// Brute Force Approach
// Algorithm
// The brute force way is to simply check each element from left to right. If we find the target, we return its index; otherwise, we return -1 after scanning the entire array.
// Start a loop from the first element to the last element.
// For each element:
// Compare it with the target value.
// If it matches the target, return the current index immediately.
// If the loop finishes and no match is found, return -1.

// Time Complexity: O(N),We may need to check every element in the worst case if the target is not present.
// Space Complexity: O(1),No extra space is used; only constant variables.

// int Solution(vector<int> &arr, int n, int x)
// {

//     for (int i = 0; i < n; i++){
//         if (arr[i] == x) return i;
//     }
    
//     return -1;
// }

// Optimal Approach
// Algorithm
// In a rotated sorted array, the entire array is no longer fully sorted ,but an important property still holds: in every part of the array you look at, one side will always be sorted. This means either the left portion or the right portion of the array will be in increasing order. That’s the key idea we use to find the target efficiently.
// Why Binary Search Still Works:
// In normal binary search, we rely on the entire array being sorted to decide whether to go left or right. But in this case, we adapt it slightly we don't require the whole array to be sorted, just identify which part is sorted in the current range. Once we know which part is sorted,
// we check if the target lies inside that sorted section. If it does, we discard the other half. If not, we discard the sorted half and search the remaining half. No matter how the array was rotated, the sorted structure on at least one side of any middle point always helps us narrow down where to look next.
// This lets us avoid scanning the whole array like in brute force, and instead bring down the number of checks to logarithmic time.
// Start by looking at the middle element of the array.
// Check if this middle element is the target if yes, return its index immediately.
// Now figure out which half of the array (left side or right side) is sorted.
// If the left part is sorted:
// Check if the target number falls within the range of that sorted part.
// If it does, discard the right half and continue the search in the left part.
// If it doesn’t, discard the left half and search in the right side.
// If the right part is sorted:
// Do the same check if the target is in that sorted part.
// If yes, discard the left side and search in the right.
// If not, discard the right and continue with the left.
// Repeat this process of eliminating half the array until the target is found or the search space is empty.

// Time Complexity: O(log N),We eliminate half of the search space in each iteration using binary search.
// Space Complexity: O(1),We use only a few variables (low, high, mid) no extra space used.

int Solution(vector<int> &arr, int n, int x){
    int low=0, high=n-1;

    while(low<=high){
        int mid = low + (high - low) / 2;

        if(arr[mid] == x) return mid;

        if(arr[low] <= arr[mid]){
            if(arr[low] <= x && x<arr[mid]){
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }else{
            if(arr[mid] < x && x<=arr[high]){
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }
    }
    return -1;
}


int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);

    int x;
    cin>>x;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << Solution(arr, n, x) << endl;

    return 0;
}
