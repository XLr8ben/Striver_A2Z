#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <math.h>
using namespace std;

// Brute Force
//  Iterate through the array with variable i, which represents the starting index of each subarray. The possible values for i range from 0 to n-1, where n is the size of the array.
//  Inside the first loop, run another loop with variable j that represents the ending index of the subarray. For each i, j can range from i to n-1.
//  For each subarray defined by i and j, iterate through its elements to calculate the sum. Maintain a variable, max, to store the maximum sum encountered so far during the iteration.
//  At each step, compare the current subarray sum with the current max value. If the current sum is greater, update the max value with the new sum.
//  Finally, after completing all iterations, return the max variable, which holds the maximum sum of any subarray.

// Time Complexity: O(N^3), where N is the size of the array. This is because we have three nested loops: one for the starting index, one for the ending index, and one for calculating the sum of the subarray.
// Space Complexity: O(1), as we are using a constant amount of space for variables, regardless of the input size.

// int Solution(vector<int>& arr, int n){
//     int ans=0;

//     for(int i=0;i<n;i++){
//         for(int j=i;j<n;j++){
//             int currSum=0;

//             for(int k=i;k<=j;k++){
//             currSum += arr[k];
//             }

//             ans = max(ans, currSum);
//         }
//     }
//     return ans;
// }

// Better Approach

// Iterate through the array with variable i, which represents the starting index of each subarray. The possible values for i range from 0 to n-1, where n is the size of the array.
// Inside the first loop, iterate again with variable j to signify the ending index of the subarray and the current element of the subarray. For each i, j can range from i to n-1.
// For each subarray defined by i and j, add the current element at arr[j] to the sum of the previous subarray.
// Keep track of the maximum sum encountered during the iteration using a variable, say maxSum, and update it whenever a greater sum is found.
// Once all iterations are complete, return maxSum as the maximum sum of all subarrays.

// Time Complexity: O(N^2), where N is the size of the array. This is because we have two nested loops: one for the starting index and one for the ending index of the subarray.
// Space Complexity: O(1), as we are using a constant amount of space for variables, regardless of the input size.

// int Solution(vector<int>& arr, int n){
//     int ans=0;

//     for(int i=0;i<n;i++){
//         int currSum=0;
//         for(int j=i;j<n;j++){
//             currSum += arr[j];
//             ans = max(ans, currSum);
//         }
//     }
//     return ans;
// }

// Optimal Approach

// Iterate through the array using a variable i. During each iteration, add the current element arr[i] to a running sum variable.
// Keep track of the maximum sum encountered during the iteration by comparing the current sum with the previous maximum sum, and update it if the current sum is greater.
// If at any point the sum becomes negative, reset it to 0, as a negative sum won't contribute positively to the overall maximum sum.
// Continue the iteration until all elements in the array are processed.
// Finally, return the maximum sum encountered during the iteration.

// Time Complexity: O(n), where n is the number of elements in the array. We traverse the array only once.
// Space Complexity: O(1). We use a constant amount of space for variables.

int Solution(vector<int> &arr, int n)
{
    int ans = 0;
    int currSum = 0;

    for (int i = 0; i < n; i++)
    {
        if (currSum < 0)
            currSum = 0;

        currSum += arr[i];
        ans = max(ans, currSum);
    }
    return ans;
}

// sliding window approach not suitable for all -ve numbers

// int Solution(vector<int>& arr, int n){
//     int left=0,right=0;
//     int ans=0,currsum=0;

//     while(right<n){
//         while(left<right && ans<0){
//             currsum-=arr[left];
//             left++;
//         }
//         currsum += arr[right];
//         ans = max(ans, currsum);
//         right++;
//     }
//     return ans;
// }

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << Solution(arr, n) << endl;

    return 0;
}
