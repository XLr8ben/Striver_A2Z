#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <math.h>
using namespace std;

// Brute-Force Approach
// Algorithm
// We will traverse the array and check every element if it is min than minval. If we find any element, we will update minval.
// Otherwise, we will return False.

// Time Complexity: O(N), N = size of the given array.
// Space Complexity: O(1), no extra space used.

// int Solution(vector<int>& arr, int n){
//     int minVal = INT_MAX;

//     for (int i = 0; i < n; i++) {
//         minVal = min(minVal, arr[i]);
//     }

//     return minVal;
// }

// Optimal Approach
// Algorithm
// In a rotated sorted array, the smallest element represents the point of rotation. It is the only element that is smaller than its previous element. Since the array is sorted in two segments,
// we can use binary search to efficiently find this pivot point. By comparing the middle element with the rightmost element in the current search space, we can determine which half of the array contains the minimum element.
// Initialize pointers to the start and end of the array.
// While start is less than end, calculate the middle index.
// If the middle element is greater than the rightmost element, move the start to mid + 1.
// Else, move the end to mid (because mid can be the minimum).
// When the loop ends, start will point to the minimum element.

// Time Complexity: O(logN), at every step the search space is reduced to half using binary search.
// Space Complexity: O(1), constant additonal space is used.

int Solution(vector<int>& arr, int n){
    int low=0, high=n-1;
    int ans = INT_MAX;

    while(low<=high){
        if(arr[low] <= arr[high]){
            return arr[low];
        }
        int mid = low + (high - low) / 2;

        if(arr[low] <= arr[mid] ){
            ans = min(ans, arr[low]);
            low = mid + 1;
        }else{
            ans = min(ans, arr[mid]);
            high = mid - 1;
        }
    }
    return ans;
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
