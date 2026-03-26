#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <math.h>
using namespace std;

//brute force approach
//time complexity: O(n^2)
//space complexity: O(1)
// int Solution(vector<int>& arr, int n){

//     // Iterate from 1 to n and check
//     // if the current number is present
//     for (int i = 1; i <= n; i++) {
//         bool found = false;
//         for (int j = 0; j < n - 1; j++) {
//             if (arr[j] == i) {
//                 found = true;
//                 break;
//             }
//         }
//         if (!found)
//         return i;
//     }

//     return -1;
// };

//better approach
//time complexity: O(n)
//space complexity: O(n)

// int Solution(vector<int>& arr, int n){

//     // Create hash array of size n+1
//     vector<int> hash(n + 1, 0);

//     // Store frequencies of elements
//     for (int i = 0; i < n - 1; i++) {
//         hash[arr[i]]++;
//     }

//     // Find the missing number
//     for (int i = 1; i <= n; i++) {
//         if (hash[i] == 0) {
//             return i;
//         }
//     }
//     return -1;
// };

//optimal approach
//time complexity: O(n)
//space complexity: O(1)
// int Solution(vector<int>& arr, int n){

//     // Calculate the sum of first n natural numbers
//     int total_sum = (n * (n + 1)) / 2;

//     // Calculate the sum of elements in the array
//     int arr_sum = 0;
//     for (int i = 0; i < n - 1; i++) {
//         arr_sum += arr[i];
//     }

//     // The missing number is the difference between total_sum and arr_sum
//     return total_sum - arr_sum;
// };

int Solution(vector<int>& arr, int n){

    // Calculate the XOR of all numbers from 1 to n
    int total_xor = 0;
    for (int i = 1; i <= n; i++) {
        total_xor ^= i;
    }

    // Calculate the XOR of all elements in the array
    int arr_xor = 0;
    for (int i = 0; i < n - 1; i++) {
        arr_xor ^= arr[i];
    }

    // The missing number is the XOR of total_xor and arr_xor
    return total_xor ^ arr_xor;
};

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
