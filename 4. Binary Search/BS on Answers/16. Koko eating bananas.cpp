#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <math.h>
#include <algorithm>
#include <unordered_map>
using namespace std;

// Brute-Force Approach
// Algorithm
// The problem is about finding the minimum eating speed such that Koko can finish all bananas within h hours.
// The extremely naive approach is to check all possible answers from 1 to max(a[]). The minimum number for which the required time is less than or equal to h is our answer.
// Find the largest pile size (max of the array).
// Loop through all possible speeds from 1 to this maximum value.
// For each speed, calculate the total hours needed. For each pile, compute the time as ceil(pile / speed).
// Sum up the hours for all piles.
// If the total hours is less than or equal to the allowed hours, return this speed as the answer.

// Time Complexity: O(n * max(a[])), since for each possible speed we go through all the piles.
// Space Complexity: O(1), since the algorithm does not use any additional space or data structures.

// int hoursneeded(vector<int>& arr, int n, int hourly){
//     int ans = 0;

//     for(int i=0;i<n;i++){
//         int a = arr[i];
//         int b = hourly;
//         ans += (a + b - 1) / b; //ciel formula
//     }
//     return ans;
// }

// int Solution(vector<int>& arr, int n, int h){
//     int maxi = *max_element(arr.begin(), arr.end());

//     for(int i=1;i<=maxi;i++){
//         int hours = hoursneeded(arr, n, i);
//         if(hours <= h) return i;
//     }
//     return 0;
// }

// Optimal Approach
// Algorithm
// The naive method checks every speed, which is slow if the piles are large. But the possible answer space (from 1 to the maximum pile size) is sorted, meaning if a certain speed works, then all higher speeds will also work.
// This allows us to apply Binary Search on the answer space to efficiently find the minimum speed at which Koko can finish the bananas within the given hours.
// First, identify the largest pile size since the eating speed cannot be more than that.
// Set the search range with the lowest speed as 1 and the highest speed as the maximum pile size.
// Use binary search within this range to check possible speeds.
// At each step, take the middle value as the current speed and calculate how many hours it would take to finish all piles at this speed.
// If the total hours are less than or equal to the allowed hours, this speed is a candidate, so try to see if a smaller speed also works by moving left.
// If the total hours exceed the allowed hours, then the speed is too slow, so move right to try higher speeds.
// Continue this process until the range closes, and the smallest valid speed found will be the answer.

// Time Complexity: O(N*log(max(a[]))), we apply binary search on our search space to reduce it into half at every step.
// Space Complexity: O(1), since the algorithm does not use any additional space or data structures.

int hoursneeded(vector<int>& arr, int n, int hourly){
    int ans = 0;

    for(int i=0;i<n;i++){
        int a = arr[i];
        int b = hourly;

        ans += (a + b -1) / b;
    }
    return ans;
}
int Solution(vector<int>& arr, int n, int h){
    int low = 1, high = *max_element(arr.begin(), arr.end());
    int ans=0;

    while(low <= high){
        int mid = low + ( high - low ) / 2;

        int target = hoursneeded(arr, n, mid);

        if(target <= h){
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
    
    int h;
    cin>>h;

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    cout<<Solution(arr, n, h)<<endl;

    return 0;
}
