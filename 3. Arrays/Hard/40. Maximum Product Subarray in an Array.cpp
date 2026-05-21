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
//  Iterate through the array with variable i, which represents the starting index of each subarray. The possible values for i range from 0 to n-1, where n is the size of the array.
//  Inside the first loop, run another loop with variable j that represents the ending index of the subarray. For each i, j can range from i to n-1.
//  For each subarray defined by i and j, iterate through its elements to calculate the Product. Maintain a variable, max, to store the maximum Product encountered so far during the iteration.
//  At each step, compare the current subarray Product with the current max value. If the current Product is greater, update the max value with the new Product.
//  Finally, after completing all iterations, return the max variable, which holds the maximum Product of any subarray.

// Time Complexity: O(N^3), where N is the size of the array. This is because we have three nested loops: one for the starting index, one for the ending index, and one for calculating the Product of the subarray.
// Space Complexity: O(1), as we are using a constant amount of space for variables, regardless of the input size.

// int Solution(vector<int>& arr, int n){
//     int ans=0;

//     for(int i=0;i<n;i++){
//         for(int j=i;j<n;j++){
//             int currProduct=1;

//             for(int k=i;k<=j;k++){
//             currProduct *= arr[k];
//             }

//             ans = max(ans, currProduct);
//         }
//     }
//     return ans;
// }

// Better Approach

// Iterate through the array with variable i, which represents the starting index of each subarray. The possible values for i range from 0 to n-1, where n is the size of the array.
// Inside the first loop, iterate again with variable j to signify the ending index of the subarray and the current element of the subarray. For each i, j can range from i to n-1.
// For each subarray defined by i and j, add the current element at arr[j] to the Product of the previous subarray.
// Keep track of the maximum Product encountered during the iteration using a variable, say maxProduct, and update it whenever a greater Product is found.
// Once all iterations are complete, return maxProduct as the maximum Product of all subarrays.

// Time Complexity: O(N^2), where N is the size of the array. This is because we have two nested loops: one for the starting index and one for the ending index of the subarray.
// Space Complexity: O(1), as we are using a constant amount of space for variables, regardless of the input size.

// int Solution(vector<int>& arr, int n){
//     int ans=0;

//     for(int i=0;i<n;i++){
//         int currProduct=1;
//         for(int j=i;j<n;j++){
//             currProduct *= arr[j];
//             ans = max(ans, currProduct);
//         }
//     }
//     return ans;
// }

// Optimal Approach - 1
// Algorithm
// The product of elements in a subarray can become large when there are positive numbers, but negative numbers and zeros make it tricky. A negative number can flip a large product into a negative one, but if we meet another negative later, the sign flips back to positive. Therefore, to capture all possible max products, we do two things:
// Traverse the array from left to right (prefix) to build cumulative product.
// Traverse the array from right to left (suffix) to catch subarrays ending at the back (helpful when max product is at the end or due to even negatives).
// Reset the product to 1 whenever a zero is found, as it breaks the subarray continuity.
// By comparing products in both directions at each step, we ensure we don’t miss any possible maximum.

// Time Complexity: O(N), every element of array is visited once.
// Space Complexity: O(1), constant number of variables are used.

int Solution(vector<int>& arr, int n){
    
    int prefix=1, suffix=1;
    int maxi=INT_MIN;

    for(int i=0;i<n;i++){
        if(prefix == 0) prefix = 1;
        if(suffix == 0) suffix = 1;

        prefix *= arr[i];
        suffix *= arr[n-1-i];

        maxi = max(maxi, max(prefix, suffix));
    }
    return maxi;
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
