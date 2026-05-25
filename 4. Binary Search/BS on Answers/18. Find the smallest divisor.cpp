#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <math.h>
#include <algorithm>
#include <unordered_map>
using namespace std;


// Brute Force
// Algorithm
// We will run a loop from 1 to max element of the array to check all possible divisors.
// To calculate the result, we will iterate over the given array using a loop. Within this loop, we will divide each element in the array by the current divisor, and sum up the obtained ceiling values.
// Inside the outer loop, If result <= threshold: We will return d as our answer.
// Finally, if we are outside the nested loops, we will return -1.

// Time Complexity: O(max(arr[])*N), where max(arr[]) = maximum element in the array, N = size of the array. We are using nested loops. The outer loop runs from 1 to max(arr[]) and the inner loop runs for N times.
// Space Complexity: O(1). No extra space used

bool isPossible(vector<int>& arr, int n, int d, int threshold){
    int sum=0;

    for(int i=0;i<n;i++){
        int a = arr[i];
        int b = d;
        int c = (a + b -1) / b;
        sum += c;
    }
    return sum<=threshold;
};

// int Solution(vector<int>& arr, int n, int threshold){
    
//     int maxi = *max_element(arr.begin(), arr.end());

//     for(int i=1;i<=maxi;i++){
//         if(isPossible(arr, n, i, threshold)){
//             return i;
//         }
//     }
//     return -1;
// }

// Optimal Approach
// Algorithm
// Intuition
// We are going to use the Binary Search algorithm to optimize the approach.

// Approach
// First, check if the number of elements is already greater than the allowed limit. If so, no answer is possible, so return -1.
// Then, identify the largest number in the list.
// Start with two markers , one at the smallest possible number (1), and another at the largest number in the list.
// Use a loop to narrow down the range. In each step, find the number that is in the middle of the current range.
// Check if using this middle number as a divisor results in a total that is within the allowed limit. This is done using a helper that adds up the rounded-up results of each division.
// If the result is within the allowed limit, it means this number might work, but a smaller one could be better. So, look in the lower half of the current range.
// If the result is too large, it means this number is too small. So, look in the upper half of the range instead.
// Repeat this process until the range closes. The smallest number that works will be pointed to by the left marker, and that's the answer.

// Time Complexity:O(log(max(arr[]))*N), where max(arr[]) = maximum element in the array, N = size of the array. We are applying binary search on our answers that are in the range of [1, max(arr[])].
// For every possible divisor ‘mid’, we call the sumByD() function. Inside that function, we are traversing the entire array, which results in O(N).
// Space Complexity: O(1), no extra space is used.

int Solution(vector<int>& arr, int n, int threshold){
    if(n > threshold) return -1;
    
    int maxi = *max_element(arr.begin(), arr.end());

    int low = 1, high = maxi;
    int ans = -1;

    while(low<=high){
        int mid = low + (high - low) / 2;

        if(isPossible(arr, n, mid, threshold)){
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

    int threshold;
    cin>> threshold;

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    cout<<Solution(arr, n, threshold)<<endl;

    return 0;
}
