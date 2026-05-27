#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <math.h>
#include <algorithm>
#include <unordered_map>
#include <numeric>
using namespace std;

// Brute Force
// Algorithm
// First, we will find the maximum element and the summation of the given array.
// We will use a loop to check all possible answers from max(arr[]) to sum(arr[]).
// Next, inside the loop, we will send ‘maxSum’, to the function countPartitions() function to get the number of partitions.
// The first value of ‘maxSum’, for which the number of partitions will be equal to ‘k’, will be our answer. So, we will return that particular value of ‘maxSum’.
// Finally, if we are out of the loop, we will return max(arr[]) as there cannot exist any answer smaller than that.

// Time Complexity: O(N * (sum(arr[])-max(arr[])+1)), where N = size of the array, sum(arr[]) = sum of all array elements, max(arr[]) = maximum of all array elements.
// Space Complexity: O(1), no extra space used.

int isPossible(vector<int>& arr, int n, int capacity, int maxSum){
    int splitingSum=0, cntmaxSum=1;

    for(int i=0;i<n;i++){
        if(splitingSum+arr[i] <= capacity) splitingSum += arr[i];
        else{
            cntmaxSum++;
            splitingSum = arr[i];
        }
    }
    return (cntmaxSum<=maxSum);
}

// int Solution(vector<int>& arr, int n, int maxSum){
//     if(maxSum > n) return -1;
    
//     int low = *max_element(arr.begin(), arr.end());
//     int high = accumulate(arr.begin(), arr.end(), 0);
    
//     int ans=0;

//     for(int i=low;i<=high;i++){
//         if(isPossible(arr, n, i, maxSum)) return i;
//     }
//     return -1;
// }

// Optimised Approach
// Algorithm
// Intuition
// We are going to use the Binary Search algorithm to optimize the approach.

// The primary objective of the Binary Search algorithm is to efficiently determine the appropriate half to eliminate, thereby reducing the search space by half. It does this by determining a specific condition that ensures that the target is not present in that half.

// Algorithm
// Place the 2 pointers i.e. low and high: Initially, we will place the pointers. The pointer low will point to max(arr[]) and the high will point to sum(arr[]).
// Calculate the ‘mid’: Now, inside the loop, we will calculate the value of ‘mid’ using the following formula: mid = (low+high) // 2 ( ‘//’ refers to integer division.
// Eliminate the halves based on the number of subarrays returned by countPartitions(): We will pass the potential value of ‘maxSum’, represented by the variable 'mid', to the ‘countPartitions()' function. This function will return the number of partitions we can make.
// If partitions > k: On satisfying this condition, we can conclude that the number ‘mid’ is smaller than our answer. So, we will eliminate the left half and consider the right half(i.e. low = mid+1).
// Otherwise, the value mid is one of the possible answers. But we want the minimum value. So, we will eliminate the right half and consider the left half(i.e. high = mid-1).
// Finally, outside the loop, we will return the value of low as the pointer will be pointing to the answer.

// Time Complexity: O(N * log(sum(arr[])-max(arr[])+1)), where N = size of the array, sum(arr[]) = sum of all array elements, max(arr[]) = maximum of all array elements.
// Space Complexity: O(1), no extra space used

int Solution(vector<int>& arr, int n, int maxSum){
    if(maxSum > n) return -1;

    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);

    int ans = 0;

    while(low<=high){
        int mid = low + (high - low) / 2;
    
        if(isPossible(arr, n, mid, maxSum)){
            ans = mid;
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }
    return ans;
}

int main()
{
    int n;
    cin>>n;
    vector<int> arr(n);

    int maxSum;
    cin>>maxSum;

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    cout<<Solution(arr, n, maxSum)<<endl;

    return 0;
}
