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
// The problem asks to find the minimum capacity of the ship such that all packages can be shipped within d days. A brute force way is to check every capacity starting from the maximum single package weight (since capacity can't be less than the heaviest package)
// up to the sum of all package weights (which guarantees all packages shipped in one day). For each capacity, simulate the shipping process day by day. The smallest capacity that ships all packages in ≤ d days is the answer.
// Find the maximum weight in the array (minimum capacity possible).
// Calculate the sum of all weights (maximum capacity possible).
// For each capacity from max weight to sum:
// Simulate shipping: load packages one by one until capacity is reached, then move to next day.
// If total days used is ≤ d, return that capacity.

// Time Complexity: O((sum_weights - max_weight) * N), where N is the number of packages. For each capacity between max weight and total sum, we simulate shipping over N packages.
// Space Complexity: O(1), only constant extra space is used.

bool isPossible(vector<int>& arr, int n, int target, int days){
    int cnt=1, capacity=0;

    for(int i=0;i<n;i++){
        if(capacity + arr[i] <= target){
            capacity += arr[i];
        }else{
            capacity = arr[i];
            cnt++;
        }
    }
    return cnt <= days;
}

// int Solution(vector<int>& arr, int n, int d){
//     int mini = *max_element(arr.begin(), arr.end());
//     int maxi = accumulate(arr.begin(), arr.end(), 0);

//     for(int i=mini;i<=maxi;i++){
//         if(isPossible(arr,n,i,d)) return i;
//     }
//     return -1;
// }

// Optimal Approach
// Algorithm
// We want to find the minimum ship capacity that allows shipping all packages within the given number of days. The capacity must be at least the heaviest package because you can’t split a package. At the same time, the capacity can be at most the sum of all packages (if you ship everything in one day). So the answer lies between these two extremes. Using binary search on this range lets us efficiently find the smallest capacity that works. For each candidate capacity, we check if it’s possible to ship all packages within the given days by greedily accumulating package weights until we reach capacity, then moving to the next day.
// Set the lower bound as the maximum weight in the packages.
// Set the upper bound as the sum of all package weights.
// While the lower bound is less than or equal to the upper bound, do:
// Pick the middle value between lower and upper bounds as the candidate capacity.
// Simulate shipping with this capacity: accumulate package weights until capacity is reached, then count a day and reset accumulation.
// If the number of days used is within the allowed days, move the upper bound down to try smaller capacities.
// If the number of days exceeds the allowed days, increase the lower bound to try larger capacities.
// Return the lower bound when the search finishes as the minimum capacity needed.

// Time Complexity: O(N * log(S)), where N is number of packages and S is the search space (sum_weights - max_weight). Each binary search step takes O(N), repeated O(log S) times.
// Space Complexity: O(1), constant extra space used.

int Solution(vector<int>& arr, int n, int d){
    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);

    int ans = INT_MAX;
    
    while(low<=high){
        int mid = low + (high - low) / 2;

        if(isPossible(arr, n, mid, d)){
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

    int d;
    cin>>d;

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    cout<<Solution(arr, n, d)<<endl;

    return 0;
}
