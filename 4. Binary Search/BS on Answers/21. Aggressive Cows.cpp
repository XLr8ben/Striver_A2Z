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
// Intuition
// The basic idea is to test every possible distance between 1 and the difference between the farthest and nearest stalls. The largest distance for which canWePlace() returns true will be our answer.

// Algorithm:
// Sort the stalls array in increasing order.
// Use a loop to check every possible distance one by one.
// For each distance, call the canWePlace() function to see if all cows can be placed:
// If canWePlace() returns false for a distance, return the previous distance (current distance - 1), as that was the largest distance where placement was possible.
// If the loop finishes without failure, return the largest possible distance (difference between farthest and nearest stalls).

// Time Complexity: O(NlogN) + O(N *(max(stalls[])-min(stalls[]))), where N = size of the array, max(stalls[]) = maximum element in stalls[] array, min(stalls[]) = minimum element in stalls[] array.
// Space Complexity: O(1) as we are not using any extra space to solve this problem.

int isPossible(vector<int>& arr, int n, int dist, int cows){
    int cntCows=1, lastCow = arr[0];
    int ans=0;

    for(int i=1;i<n;i++){
        if(arr[i] - lastCow >= dist){
            cntCows++;
            lastCow = arr[i];
        }
    }
    return (cntCows>=cows);
}

// int Solution(vector<int>& arr, int n, int cows){
//     sort(arr.begin(), arr.end());
//     int ans=0;

//     int high = arr[n-1] - arr[0];

//     for(int i=1;i<=high;i++){
//         if(isPossible(arr, n, i, cows)) ans = i;
//         else break;
//     }
//     return ans;
// }

// Optimal Approach
// Algorithm
// We use Binary Search to optimize the solution by reducing the answer space in half each time.

// The main idea of Binary Search is to determine which half of the search space can be eliminated based on a specific condition, thus minimizing unnecessary checks.

// The answer space is sorted: 1 to the difference between max and min values. We can divide this space into two parts:

// One containing valid answers.
// The other containing non-viable options.
// Example: For stalls = {1, 2, 8, 4, 9}, the possible distances are shown below:



// Sort the stalls: Arrange the stalls in ascending order.
// Set the search range:
// Start with the smallest possible distance.
// The largest possible distance is the gap between the farthest and nearest stalls.
// Use Binary Search: Repeat the process until the search range is exhausted:
// Pick the middle distance: Test this distance as a possible answer.
// Check if it works:
// If it works: Try to increase the distance to see if a larger one is possible.
// If it doesn’t work: Decrease the distance and test smaller ones.
// Return answer: After exiting the loop, high holds the largest valid distance.

// Time Complexity: O(NlogN) + O(N * log(max(stalls[])-min(stalls[]))), where N = size of the array, max(stalls[]) = maximum element in stalls[] array, min(stalls[]) = minimum element in stalls[] array.
// Space Complexity: O(1) as we are not using any extra space to solve this problem.

int Solution(vector<int>& arr, int n, int cows){
    sort(arr.begin(), arr.end());

    int low = 1, high = arr[n-1]-arr[0];

    int ans = 0;

    while(low<=high){
        int mid = low + (high - low) / 2;
    
        if(isPossible(arr, n, mid, cows)){
            ans = mid;
            low = mid + 1;
        }else{
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

    int cows;
    cin>>cows;

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    cout<<Solution(arr, n, cows)<<endl;

    return 0;
}
