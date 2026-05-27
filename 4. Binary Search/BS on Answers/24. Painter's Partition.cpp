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

// Brute Force Approach
// Algorithm
// First, we will find the maximum element and the summation of the given array.
// We will use a loop(say time) to check all possible answers from max(arr[]) to sum(arr[]).
// Next, inside the loop, we will send ‘time’, to the function countPainters() function to get the number of painters to whom we can allocate the boards.
// The first value of ‘time’, for which the number of painters will be lesser or equal to ‘k’, will be our answer. So, we will return that particular value of ‘time’.
// Finally, if we are out of the loop, we will return max(arr[]) as there cannot exist any answer smaller than that.

// Time Complexity: O(N * (sum(arr[])-max(arr[])+1)), where N = size of the array, sum(arr[]) = sum of all array elements, max(arr[]) = maximum of all array elements.
// Space Complexity: O(1), no extra space used.

int isPossible(vector<int>& arr, int n, int capacity, int painters){
    int partition=0, cntPainters=1;

    for(int i=0;i<n;i++){
        if(partition+arr[i] <= capacity) partition += arr[i];
        else{
            cntPainters++;
            partition = arr[i];
        }
    }
    return (cntPainters<=painters);
}

// int Solution(vector<int>& arr, int n, int painters){
//     if(painters > n) return -1;
    
//     int low = *max_element(arr.begin(), arr.end());
//     int high = accumulate(arr.begin(), arr.end(), 0);
    
//     int ans=0;

//     for(int i=low;i<=high;i++){
//         if(isPossible(arr, n, i, painters)) return i;
//     }
//     return -1;
// }

// Optimal Approach
// Algorithm
// Place the 2 pointers i.e. low and high: Initially, we will place the pointers. The pointer low will point to max(arr[]) and the high will point to sum(arr[]).
// Calculate the ‘mid’: Now, inside the loop, we will calculate the value of ‘mid’ using the following formula: mid = (low+high) // 2 ( ‘//’ refers to integer division.
// Eliminate the halves based on the number of painters returned by countPainters(): We will pass the potential value of time, represented by the variable 'mid', to the ‘countPainters()' function. This function will return the number of painters we need to paint all the boards
// If painters > k: On satisfying this condition, we can conclude that the number ‘mid’ is smaller than our answer. So, we will eliminate the left half and consider the right half(i.e. low = mid+1).
// Otherwise, the value mid is one of the possible answers. But we want the minimum value. So, we will eliminate the right half and consider the left half(i.e. high = mid-1).
// Finally, outside the loop, we will return the value of low as the pointer will be pointing to the answer.

// Time Complexity: O(N * log(sum(arr[])-max(arr[])+1)), where N = size of the array, sum(arr[]) = sum of all array elements, max(arr[]) = maximum of all array elements.
// Space Complexity: O(1) since no extra space is required.

int Solution(vector<int>& arr, int n, int painters){
    if(painters > n) return -1;

    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);

    int ans = 0;

    while(low<=high){
        int mid = low + (high - low) / 2;
    
        if(isPossible(arr, n, mid, painters)){
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

    int painters;
    cin>>painters;

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    cout<<Solution(arr, n, painters)<<endl;

    return 0;
}
