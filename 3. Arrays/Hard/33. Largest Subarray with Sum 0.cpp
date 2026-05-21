#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <math.h>
#include <unordered_map>
#include <algorithm>
using namespace std;


// Brute Force
// Algorithm
// Initialize a variable max = 0, which stores the length of the longest subarray with a sum of 0.
// Traverse the array from the start and initialize a variable sum = 0, which stores the sum of the subarray starting with the current index.
// Traverse from the next element of the current index up to the end of the array. Each time, add the element to the sum and check if it is equal to 0.
// If sum = 0, check if the length of the subarray so far is greater than max, and if yes, update max.
// Continue adding elements and repeat the above step until the outer loop completes traversing all elements.
// Finally, return the max which holds the length of the longest subarray with a sum of 0.

// Time Complexity: O(N^2), where N is the size of the array. This is because we are using two nested loops to check all possible subarrays.
// Space Complexity: O(1), as we are not using any additional data structures that grow with input size. We are only using a few variables to store the maximum length and the current sum.

// int Solution(vector<int>& arr, int n){
//     int maxi = 0;

//     for(int i=0;i<n;i++){
//         int sum = 0;

//         for(int j=i;j<n;j++){
//             sum += arr[j];

//             if(sum==0){
//                 maxi = max(maxi, j-i+1);
//             }
//         }
//     }
//     return maxi;
// }

// Optimal Approach
// Algorithm
// Initialize a variable sum = 0, which stores the sum of elements traversed so far, and another variable max = 0, which stores the length of the longest subarray with sum zero.
// Declare a HashMap<Integer, Integer> to store the prefix sum of every element as a key and its index as a value.
// Traverse the array and add the array element to the sum.
// If sum = 0, update max with the maximum value between max and current_index + 1, as the subarray from the start to the current index has a sum of 0.
// If sum is not equal to zero, check the HashMap to see if we've encountered this sum before.
// If the HashMap contains the sum, this indicates that a subarray with the same sum exists, so update max accordingly.
// If the sum is not found in the HashMap, insert (sum, current_index) into the HashMap to store the prefix sum until the current index.
// After traversing the entire array, the max variable will hold the length of the longest subarray with a sum equal to zero. Return max.

// Time Complexity: O(n), where n is the length of the string. This is because we are using a single pass through the string with two pointers, leading to linear time complexity.
// Space Complexity: O(1), as we are using a fixed-size hash array of size 256 (for ASCII characters) and not using any additional data structures that grow with input size.

int Solution(vector<int>& arr, int n){
    unordered_map<int, int> mp;

    int maxi=0, sum=0;

    for(int i=0;i<n;i++){
        sum += arr[i];

        if(sum==0) maxi=i+1;

        if(mp.find(sum) != mp.end()){
            maxi = max(maxi, i-mp[sum]);
        }else{
            mp[sum] = i;
        }
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
