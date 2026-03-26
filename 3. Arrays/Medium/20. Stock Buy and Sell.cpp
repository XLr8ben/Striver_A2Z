#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <math.h>
using namespace std;

// Brute Force Approach

// We try every possible pair of days (buy day and sell day after buy) and calculate the profit. The maximum profit among all these pairs is our answer. If no profit is possible, return 0.
// Loop through all days to consider each as a possible buy day.
// For each buy day, loop through all future days to consider them as sell days.
// Calculate the profit for each (buy, sell) pair.
// Track the maximum profit seen.

// Time Complexity: O(n²) Because for each element, we are checking every future element nested loops.
// Space Complexity: O(1) No extra space used, only variables for storing max profit.

// int Solution(vector<int>& arr, int n){
//     int buy=0,sell=0, currsum=0;

//     for(int i=0;i<n;i++){
//         buy = arr[i];
//         for(int j=i+1;j<n;j++){
//             currsum = arr[j] - buy;
//             sell = max(sell, currsum);
//         }
//     }
//     return sell;
// }

// Optimal Approach

// The idea is to track the minimum price so far while traversing the array and calculate the profit if we sold today. This way, we can constantly update the maximum profit without using nested loops. We’re basically simulating:
// What’s the lowest price we’ve seen so far?
// What’s the profit if we sold today?
// Is it better than our best so far?
// Initialize a variable to store the minimum price so far, set it to a very large value initially.
// Initialize a variable to store the maximum profit seen so far, set it to 0 initially.
// Loop through each price in the array.
// Update the minimum price if the current price is smaller.
// Calculate the profit if the stock were bought at the minimum price and sold at the current price.
// Update the maximum profit if this new profit is higher.
// Return the maximum profit after the loop ends.

// Time Complexity: O(n),This is because we are iterating through the array of prices exactly once. There are no nested loops or recursive calls.
// Space Complexity: O(1),Only two variables are used to store the minimum price and maximum profit, regardless of the input size.

int Solution(vector<int>& arr, int n){
    int mini = arr[0],ans=0;

    for(int i=1;i<n;i++){
        ans = max(ans, arr[i]-mini);
        mini = min(mini, arr[i]);
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
