#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <math.h>
#include <unordered_map>
using namespace std;

//brute force approach
// We first run a loop with index i to select every possible starting index of the subarray. These starting indices range from 0 to n-1 where n is the size of the array.
// Inside this loop, we run another loop with index j to select the ending index of the subarray. For each subarray starting at index i, the ending index j can range from i to n-1.
// Next, for each subarray starting from index i and ending at index j (i.e., arr[i...j]), we run an additional loop to calculate the sum of all the elements in that subarray.
// If the sum equals k, we consider its length, which is (j - i + 1). Among all such subarrays, we keep track of the maximum length by comparing all the lengths found so far.

// Time Complexity: O(n3), where n is the size of the array. This is because we have three nested loops: one for the starting index, one for the ending index, and one for calculating the sum of the subarray.
// Space Complexity: O(1), as we are using a constant amount of space for variables and not using any additional data structures that grow with input size.

// int Solution(vector<int>& arr, int n, int target, vector<int>& temp){
//     int maxLength = 0;

//     // starting index
//     for (int startIndex = 0; startIndex < n; startIndex++) { 
//         // ending index
//         for (int endIndex = startIndex; endIndex < n; endIndex++) { 
//             /* add all the elements of 
//                subarray = nums[startIndex...endIndex]  */
//             int currentSum = 0;
//             for (int i = startIndex; i <= endIndex; i++) {
//                 currentSum += arr[i];
//             }

//             if (currentSum == target){
//                 if(endIndex - startIndex + 1 > maxLength){
//                     maxLength = endIndex - startIndex + 1;
//                     temp.clear();
//                     for(int k=startIndex; k<=endIndex; k++){
//                         temp.push_back(arr[k]);
//                     }
//                 }
//             }
//         }
//     }
//     return maxLength;
    
// }

//another brute force approach
// We use two nested loops to generate all possible subarrays of the input array. The outer loop iterates through the starting index of the subarray, while the inner loop iterates through the ending index of the subarray.
// For each subarray defined by the starting and ending indices, we calculate the sum of its elements. If the sum equals k, we check if the length of this subarray is greater than the maximum length found so far. If it is, we update the maximum length.
// Time Complexity: O(n2), where n is the size of the array. This is because we have two nested loops: one for the starting index and one for the ending index. The sum calculation can be optimized to O(1) by maintaining a running sum, but in this implementation, it is O(n) for each subarray, leading to O(n3) in total.
// Space Complexity: O(1), as we are using a constant amount of space for variables and not using any additional data structures that grow with input size.

// int Solution(vector<int>& arr, int n, int target, vector<int>& temp){
//     int maxLength = 0;

//     // starting index
//     for (int startIndex = 0; startIndex < n; startIndex++) { 
//         int currentSum = 0;
//         // ending index
//         for (int endIndex = startIndex; endIndex < n; endIndex++) { 
//             currentSum += arr[endIndex];

//             if (currentSum == target){
//                 if(endIndex - startIndex + 1 > maxLength){
//                     maxLength = endIndex - startIndex + 1;
//                     temp.clear();
//                     for(int k=startIndex; k<=endIndex; k++){
//                         temp.push_back(arr[k]);
//                     }
//                 }
//             }
//         }
//     }
//     return maxLength;
// }


//better approach
// We use a single loop to traverse the array while maintaining a running sum of the elements.
// We also maintain a hash map (or unordered map) to store the first occurrence of each running sum. The key is the running sum and the value is the index at which this sum was first seen.
// For each element in the array, we add it to the running sum. If the running sum equals k, we update the maximum length to the current index + 1 (since the subarray starts from index 0).
// If the running sum minus k (i.e., runningSum - k) exists in the hash map, it means there is a subarray that sums to k between the index stored in the hash map and the current index. We calculate the length of this subarray and update the maximum length if it's greater than the current maximum.
// If the running sum is not already in the hash map, we store it with the current index as its value.
// Time Complexity: O(n), where n is the size of the array. We traverse the array once, and each lookup and insertion in the hash map is O(1) on average.
// Space Complexity: O(n), in the worst case, we might store all running sums in the hash map if all sums are unique.

//worst time complexity: O(n2) due to collision in hash map, but average time complexity is O(n)

int Solution(vector<int>& arr, int n, int target, vector<int>& temp){
    unordered_map<int, int> mp;
    int prefixSum = 0;
    int maxLength = 0;

    for(int currentIdx=0;currentIdx<n;currentIdx++){
        prefixSum += arr[currentIdx];

        if(prefixSum == target) maxLength = currentIdx + 1;
        
        if(mp.find(prefixSum-target) != mp.end()){
            int prevIdx = mp[prefixSum-target];
            maxLength = max(maxLength, currentIdx - prevIdx);
        }
        if(mp.find(prefixSum)==mp.end()) mp[prefixSum] = currentIdx;
    }
    
    return maxLength;
}



//optimal approach
// We use two pointers, left and right, to maintain a sliding window of elements in the array. The right pointer expands the window by including new elements, while the left pointer shrinks the window when the sum exceeds k.
// We maintain a variable sum to keep track of the sum of the elements in the current window. As we move the right pointer, we add the new element to sum. If sum exceeds k, we move the left pointer to the right, subtracting the elements from sum until it is less than or equal to k.
// If at any point sum equals k, we check if the length of the current window (right - left + 1) is greater than the maximum length found so far, and if so, we update the maximum length.
// Time Complexity: O(n), where n is the size of the array. We traverse the array once with the right pointer, and the left pointer also moves at most n times, resulting in linear time complexity.
// Space Complexity: O(1), as we are using a constant amount of space for variables and not using any additional data structures that grow with input size.

// int Solution(vector<int>& arr, int n, int target, vector<int>& temp){
//     int maxLen=0;

//     int left=0,right=0,sum=arr[0];

//     while(right<n){
//         while(left<right && sum>target){
//             sum-=arr[left];
//             left++;
//         }
//         if(sum==target) {
//             if(right-left+1 > maxLen){
//                 maxLen = right-left+1;
//                 temp.clear();
//                 for(int k=left; k<=right; k++){
//                     temp.push_back(arr[k]);
//                 }
//             }
//         }
//         right++;
//         if(right < n) sum+=arr[right];
//     }
//     return maxLen;
// }

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

    vector<int> temp;

    cout<<Solution(arr, n, target, temp)<<endl;

    for(int i=0;i<temp.size();i++){
        cout<<temp[i]<<" ";
    }

    return 0;
}
