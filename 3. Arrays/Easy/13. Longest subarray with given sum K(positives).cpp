#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <math.h>
using namespace std;

//brute force
// We first run a loop with index i to select every possible starting index of the subarray. These starting indices range from 0 to n-1 where n is the size of the array.
// Inside this loop, we run another loop with index j to select the ending index of the subarray. For each subarray starting at index i, the ending index j can range from i to n-1.
// Next, for each subarray starting from index i and ending at index j (i.e., arr[i...j]), we run an additional loop to calculate the sum of all the elements in that subarray.
// If the sum equals k, we consider its length, which is (j - i + 1). Among all such subarrays, we keep track of the maximum length by comparing all the lengths found so far.

//Time Complexity: O(n3), where n is the size of the array. This is because we have three nested loops: one for the starting index, one for the ending index, and one for calculating the sum of the subarray.
// Space Complexity: O(1), as we are using a constant amount of space for variables and not using any additional data structures that grow with input size.

// int Solution(vector<int>& arr, int n, int target){
//         int maxLength = 0;

//         // starting index
//         for (int startIndex = 0; startIndex < n; startIndex++) { 
//             // ending index
//             for (int endIndex = startIndex; endIndex < n; endIndex++) { 
//                 /* add all the elements of 
//                    subarray = nums[startIndex...endIndex]  */
//                 int currentSum = 0;
//                 for (int i = startIndex; i <= endIndex; i++) {
//                     currentSum += arr[i];
//                 }

//                 if (currentSum == target)
//                     maxLength = max(maxLength, endIndex - startIndex + 1);
//             }
//         }
//         return maxLength;
// }

//optimal approach
// Two pointers, left and right, are used to maintain the current window of elements in the array. These pointers represent the start and end of the current subarray.
// A variable, sum, is used to keep track of the sum of the elements in the current window between left and right.
// The right pointer expands the window by including new elements, increasing the sum.
// If the sum of the window exceeds k, the left pointer shrinks the window by removing elements from the start until the sum is less than or equal to k.
// If the sum of the current window equals k, the maximum length of such a subarray is updated.
// The process continues until the right pointer traverses the entire array.
// Finally, the maximum length of the subarray with sum k is returned as the result.

// Time Complexity: O(N), where N is the size of the array. The algorithm traverses the array once with two pointers, making it linear in time complexity.
// Space Complexity: O(1), as it uses a constant amount of space.

int Solution(vector<int>& arr, int n, int target){
    int maxLen=0;

    int left=0,right=0,sum=arr[0];

    while(right<n){
        while(left<right && sum>target){
            sum-=arr[left];
            left++;
        }
        if(sum==target) maxLen = max(maxLen, right-left+1);
        sum+=arr[right];
        right++;
    }
    return maxLen;
}

int main()
{
    int n;
    cin>>n;
    vector<int> arr(n);

    int target;
    cin>>target;

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    cout<<Solution(arr, n, target)<<endl;

    return 0;
}
