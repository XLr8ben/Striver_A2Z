#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <math.h>
#include <unordered_map>
using namespace std;

// Brute force Approach
// Algorithm
// We will check the sum of every possible subarray and count how many of them are equal to k. To get every possible subarray sum, we will be using three nested loops. The first two loops(say i and j) will iterate over every possible starting index and ending index of a subarray.
// Basically, in each iteration, the subarray range will be from index i to index j. Using another loop we will get the sum of the elements of the subarray [i…..j]. Among all values of the sum calculated, we will only consider those that are equal to k.

// Note: We are selecting every possible subarray using two nested loops and for each of them, we add all its elements using another loop.
// First, we will run a loop(say i) that will select every possible starting index of the subarray. The possible starting indices can vary from index 0 to index n-1(n = size of the array).
// Inside the loop, we will run another loop(say j) that will signify the ending index of the subarray. For every subarray starting from the index i, the possible ending index can vary from index i to n-1(n = size of the array).
// After that for each subarray starting from index i and ending at index j (i.e. arr[i….j]), we will run another loop to calculate the sum of all the elements(of that particular subarray).
// After calculating the sum, we will check if the sum is equal to the given k. If it is, we will increase the value of the count.

// Time Complexity: O(N3), where N = size of the array.We are using three nested loops here. Though all are not running for exactly N times, the time complexity will be approximately O(N3).
// Space Complexity: O(1) as we are not using any extra space.

// int Solution(vector<int>& arr, int n, int target){
//     int cnt=0;

//     for(int i=0;i<n;i++){
//         for(int j=i;j<n;j++){
//             int sum = 0;

//             for(int k=i;k<=j;k++){
//                 sum += arr[k];
//             }
//             if(sum == target) cnt++;
//         }
//     }
//     return cnt;
// }

// Better Approach
// Algorithm
// If we carefully observe, we can notice that to get the sum of the current subarray we just need to add the current element(i.e. arr[j]) to the sum of the previous subarray i.e. arr[i….j-1]. Assume previous subarray = arr[i……j-1]
// current subarray = arr[i…..j]
// Sum of arr[i….j] = (sum of arr[i….j-1]) + arr[j] This is how we can remove the third loop and while moving j pointer, we can calculate the sum.
// First, we will run a loop(say i) that will select every possible starting index of the subarray. The possible starting indices can vary from index 0 to index n-1(n = array size).
// Inside the loop, we will run another loop(say j) that will signify the ending index as well as the current element of the subarray. For every subarray starting from the index i, the possible ending index can vary from index i to n-1(n = size of the array).
// Inside loop j, we will add the current element to the sum of the previous subarray i.e. sum = sum + arr[j].
// After calculating the sum, we will check if the sum is equal to the given k. If it is, we will increase the value of the count.

// Time Complexity: O(n²),We use two nested loops to check all subarrays, where n is the size of the array.
// Space Complexity: O(1),Only a few extra variables are used, so constant extra space regardless of input size.

// int Solution(vector<int>& arr, int n, int target){
//     int cnt=0;

//     for(int i=0;i<n;i++){
//         int sum = 0;
//         for(int j=i;j<n;j++){
//             sum += arr[j];
//             if(sum == target) cnt++;
//         }
//     }
//     return cnt;

// }

// Optimal Approach
// Algorithm
// In this approach, we are going to use the concept of the prefix sum to solve this problem. Here, the prefix sum of a subarray ending at index i simply means the sum of all the elements of that subarray.

// Assume, the prefix sum of a subarray ending at index i is x. In that subarray, we will search for another subarray ending at index i, whose sum equals k. Here, we need to observe that if there exists another subarray ending at index i with sum k, then the prefix sum of the rest of the subarray will be x-k. The below image will clarify the concept:

// Now, for a subarray ending at index i with the prefix sum x, if we remove the part with the prefix sum x-k, we will be left with the part whose sum is equal to k. And that is what we want. Now, there may exist multiple subarrays with the prefix sum x-k.
// So, the number of subarrays with sum k that we can generate from the entire subarray ending at index i, is exactly equal to the number of subarrays with the prefix sum x-k, that we can remove from the entire subarray.

// That is why, instead of searching the subarrays with sum k, we will keep the occurrence of the prefix sum of the subarrays using a map data structure.

// In the map, we will store every prefix sum calculated, with its occurrence in a <key, value> pair. Now, at index i, we just need to check the map data structure to get the number of times that the subarrays with the prefix sum x-k occur. Then we will simply add that number to our answer.

// We will apply the above process for all possible indices of the given array. The possible values of the index i can be from 0 to n-1(where n = size of the array)
// First, we will declare a map to store the prefix sums and their counts.
// Then, we will set the value of 0 as 1 on the map.
// Then we will run a loop(say i) from index 0 to n-1(n = size of the array).
// For each index i, we will do the following:
// We will add the current element i.e. arr[i] to the prefix sum.
// We will calculate the prefix sum i.e. x-k, for which we need the occurrence.
// We will add the occurrence of the prefix sum x-k i.e. mpp[x-k] to our answer.
// Then we will store the current prefix sum in the map increasing its occurrence by 1.

// Time Complexity: O(n) We traverse the array once, where n is the size of the array. Each prefix sum operation and hashmap lookup is O(1) on average.
// Space Complexity: O(n) In the worst case, all prefix sums are distinct and stored in the hashmap, so space grows linearly with input size.

int Solution(vector<int> &arr, int n, int target)
{

    int prefixSum = 0, cnt = 0;

    unordered_map<int, int> mp;
    mp[0] = 1;

    for (int i = 0; i < n; i++)
    {
        prefixSum += arr[i];

        if (mp.find(prefixSum - target) != mp.end())
        {
            cnt += mp[prefixSum - target];
        }
        mp[prefixSum]++;
    }
    return cnt;
}

int main()
{
    int n;
    cin >> n;

    int target;
    cin >> target;

    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << Solution(arr, n, target) << endl;

    return 0;
}
