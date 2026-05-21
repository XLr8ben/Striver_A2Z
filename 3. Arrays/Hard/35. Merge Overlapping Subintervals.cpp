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
// The main idea is to combine intervals that overlap with each other. To do this easily, we first sort the intervals by their starting point so that all overlapping intervals come next to each other. Then, for each interval, we try to see if the next ones overlap with it. If they do, we merge them into one bigger interval. We keep doing this until we find a non-overlapping interval, and then start the process again from that point.
// Sort all intervals based on their starting points. This helps bring all overlapping intervals next to each other.
// Go through each interval one by one and if the current interval is already covered by a previously merged interval, skip it. Else, pick the current interval as the starting point of a new merged interval.
// Now run another loop to check if the following intervals overlap with the current one
// If the start of next interval is less than or equal to the end of the current merged interval, it means they overlap. Therefore, extend the end of the merged interval to be the maximum of the two ends.
// Keep doing this for the next intervals as long as they overlap. As soon as you find an interval that doesn't overlap, break the inner loop and move back to the outer loop to process the next non-overlapping interval.
// Store each merged interval in the final answer list and after the loop ends, return the list of merged intervals.

// Time Complexity: O(N^2), for every interval we check all future intervals.
// Space Complexity: ON), additonal space used to store the non-overlapping intervals.

// void Solution(vector<vector<int>>& arr, int n){
    
//     sort(arr.begin(), arr.end());

//     vector<vector<int>> ans;

//     for(int i=0;i<n;i++){
//         int start = arr[i][0];
//         int end = arr[i][1];

//         if(!ans.empty() && end <= ans.back()[1]) continue;

//         for(int j=i+1;j<n;j++){
//             if(arr[j][0]<=end){
//                 end = max(end, arr[j][1]);
//             }else{
//                 break;
//             }
//         }
//         ans.push_back({start, end});
//     }

//     for (auto interval : ans) {
//         cout << "[" << interval[0] << "," << interval[1] << "] ";
//     }
// }

// Optimal Approach
// Algorithm
// Imagine laying intervals out on a number line. If two intervals overlap, we can combine them into one, like merging blocks that touch or overlap.

// Instead of checking each interval with every other one (as in brute-force), we first sort the intervals, so that any overlapping intervals will come one after the other. This way, we only need to compare each interval with the last one added to our answer. If they overlap, we merge them. If they don’t, we simply add the current interval as a new entry.
// Sort the intervals based on their starting points. This ensures overlapping intervals come together.
// Initialize an empty list to store the final merged intervals.
// If the list is empty or the current interval starts after the last one ends, it means there is no overlap, so just add it to the list.
// If the current interval starts before or exactly at the end of the last one, it means there is overlap. So, combine both by extending the end of the last one to the further end of the two.
// Keep doing this until all intervals have been checked. The final list will now contain only non-overlapping, merged intervals.

// Time Complexity: O(N*logN) + O(N), we sort the entire array and then merge them in a single pass.
// Space Complexity: O(N), additonal space used to store the non-overlapping intervals.

void Solution(vector<vector<int>>& arr, int n){

    sort(arr.begin(), arr.end());

    vector<vector<int>> ans;

    for(int i=0;i<n;i++){
        if(ans.empty() || arr[i][0]>ans.back()[1]){
            ans.push_back(arr[i]);
        }else{
            ans.back()[1] = max(ans.back()[1], arr[i][1]);
        }
    }

    for (auto interval : ans) {
        cout << "[" << interval[0] << "," << interval[1] << "] ";
    }
}

int main()
{
    int n;
    cin>>n;
    // vector<int> arr(n);

    // for(int i=0; i<n; i++){
    //     cin>>arr[i];
    // }

    vector<vector<int>> arr = {{1,3}, {2,6}, {8,10}, {15,18}};

    n = arr.size();

    Solution(arr, n);

    return 0;
}
