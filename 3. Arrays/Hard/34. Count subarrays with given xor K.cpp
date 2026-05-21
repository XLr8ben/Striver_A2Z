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
// We will check the xorVal of every possible subarray and count how many of them are equal to k. To get every possible subarray xorVal, we will be using three nested loops. The first two loops(say i and j) will iterate over every possible starting index and ending index of a subarray. Basically, in each iteration, the subarray range will be from index i to index j. Using another loop we will get the xorVal of the elements of the subarray [i…..j]. Among all values of the xorVal calculated, we will only consider those that are equal to k.

// Note: We are selecting every possible subarray using two nested loops and for each of them, we add all its elements using another loop.
// First, we will run a loop(say i) that will select every possible starting index of the subarray. The possible starting indices can vary from index 0 to index n-1(n = size of the array).
// Inside the loop, we will run another loop(say j) that will signify the ending index of the subarray. For every subarray starting from the index i, the possible ending index can vary from index i to n-1(n = size of the array).
// After that for each subarray starting from index i and ending at index j (i.e. arr[i….j]), we will run another loop to calculate the xorVal of all the elements(of that particular subarray).
// After calculating the xorVal, we will check if the xorVal is equal to the given k. If it is, we will increase the value of the count.

// Time Complexity: O(N3), where N = size of the array.We are using three nested loops here. Though all are not running for exactly N times, the time complexity will be approximately O(N3).
// Space Complexity: O(1) as we are not using any extra space.

// int Solution(vector<int>& arr, int n, int target){
//     int cnt=0;

//     for(int i=0;i<n;i++){
//         for(int j=i;j<n;j++){
//             int xorVal = 0;

//             for(int k=i;k<=j;k++){
//                 xorVal ^= arr[k];
//             }
//             if(xorVal == target) cnt++;
//         }
//     }
//     return cnt;
// }

// Better Approach
// Algorithm
// If we carefully observe, we can notice that to get the xorVal of the current subarray we just need to add the current element(i.e. arr[j]) to the xorVal of the previous subarray i.e. arr[i….j-1]. AsxorVale previous subarray = arr[i……j-1]
// current subarray = arr[i…..j]
// xorVal of arr[i….j] = (xorVal of arr[i….j-1]) + arr[j] This is how we can remove the third loop and while moving j pointer, we can calculate the xorVal.
// First, we will run a loop(say i) that will select every possible starting index of the subarray. The possible starting indices can vary from index 0 to index n-1(n = array size).
// Inside the loop, we will run another loop(say j) that will signify the ending index as well as the current element of the subarray. For every subarray starting from the index i, the possible ending index can vary from index i to n-1(n = size of the array).
// Inside loop j, we will add the current element to the xorVal of the previous subarray i.e. xorVal = xorVal + arr[j].
// After calculating the xorVal, we will check if the xorVal is equal to the given k. If it is, we will increase the value of the count.

// Time Complexity: O(n²),We use two nested loops to check all subarrays, where n is the size of the array.
// Space Complexity: O(1),Only a few extra variables are used, so constant extra space regardless of input size.

// int Solution(vector<int>& arr, int n, int target){
//     int cnt=0;

//     for(int i=0;i<n;i++){
//         int xorVal = 0;
//         for(int j=i;j<n;j++){
//             xorVal ^= arr[j];
//             if(xorVal == target) cnt++;
//         }
//     }
//     return cnt;

// }

// Optimal Approach
// Algorithm
// The brute force approach checks all possible subarrays and computes their XOR, but this quickly becomes inefficient for large arrays because it requires checking every pair of indices. Instead, we can make use of prefix XORs. A prefix XOR at index i represents the XOR of all elements from the start up to i. Using this, the XOR of any subarray can be derived by taking the XOR of two prefix XOR values.

// Now, to find whether a subarray ending at the current position has XOR equal to k, we only need to check if there was an earlier prefix XOR such that when we combine it with the current prefix XOR, the result is k. In other words, the condition becomes prefixXor[r] ^ prefixXor[l-1] = k.

// We keep track of how many times each prefix XOR has appeared using a hashmap (or dictionary). Whenever we find one that matches, we increase our count. This way, instead of checking all subarrays, we just use the hashmap and solve it much faster.
// Initialize a hashmap to store how many times each prefix XOR has appeared.
// Keep a variable to store the current prefix XOR as we move through the array.
// Keep another variable to count the total number of subarrays with XOR equal to k.
// For each element in the array, update the prefix XOR by combining it with the current element.
// If the prefix XOR itself is equal to k, increase the count by one.
// Check if there exists a prefix XOR seen before that can make the subarray XOR equal to k, and if yes, add its frequency from the hashmap to the count.
// Store or update the frequency of the current prefix XOR in the hashmap.
// After processing all elements, the count will be the total number of subarrays with XOR equal to k.

// Time Complexity: O(N), we traverse the entire array once to calculate prefix XOR and subarrays with given XOR.
// Space Complexity: O(N) , additional amount of extra space is used to store frequencies of prefix XOR in hash map.

int Solution(vector<int> &arr, int n, int target)
{

    int sum = 0, cnt = 0;

    unordered_map<int, int> mp;
    mp[0] = 1;

    // for (int i = 0; i < n; i++)
    // {
    //     sum ^= arr[i];

    //     int prefix = sum ^ target;

    //     if (mp.find(prefix) != mp.end())
    //     {
    //         cnt += mp[prefix];
    //     }
    //     mp[sum]++;
    // }

    // another way around
    for (int i = 0; i < arr.size(); i++){
        sum ^= arr[i];
        int prefix = sum ^ target;
        cnt += mp[prefix];
        mp[sum]++;
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
