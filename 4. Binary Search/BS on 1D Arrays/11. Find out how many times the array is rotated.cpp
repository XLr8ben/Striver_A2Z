#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <math.h>
using namespace std;

// Brute-Force Approach
// Algorithm
// We will traverse the array and check every element if it is min than minval. If we find any element, we will update minval.
// Otherwise, we will return False.

// Time Complexity: O(N), N = size of the given array.
// Space Complexity: O(1), no extra space used.

// int Solution(vector<int>& arr, int n){
//     int minVal = INT_MAX;

//     for (int i = 0; i < n; i++) {
//         minVal = min(minVal, arr[i]);
//     }

//     return minVal;
// }

// Optimal Approach
// Algorithm
// Think of the rotated sorted array as two sorted halves the rotation “break” point is where the smallest element lives. Using binary search, we can efficiently zoom in on this smallest element by comparing middle elements to the rightmost element. If the middle element is greater than the rightmost element, the rotation point is to the right. Otherwise, it's to the left or could be the middle itself. This way, we reduce the search space by half each time, getting the rotation count in O(log n).

// Imagine searching for the break in a long sorted belt by cutting it in halves repeatedly instead of scanning all the way through.
// Initialize low = 0 and high = n - 1.
// While low is less than high:
// Find mid index.
// If the element at mid is greater than the element at high, the rotation point is after mid, so update low = mid + 1.
// Else, the rotation point is at mid or before it, so update high = mid.
// When low meets high, that index is the rotation count (index of smallest element).

// Time Complexity: O(logN), at every step the search space is reduced to half using binary search.
// Space Complexity: O(1), constant additonal space is used.

// int Solution(vector<int> &arr, int n)
// {
//     int low = 0, high = n - 1;
//     int ans = INT_MAX;
//     int idx = -1;

//     while (low <= high)
//     {
//         if (arr[low] <= arr[high])
//         {
//             if(arr[low] < ans){
//                 idx = low;
//                 ans = arr[low];
//             }
//             break;
//         }
//         int mid = low + (high - low) / 2;

//         if (arr[low] <= arr[mid])
//         {
//             if (arr[low] < ans)
//             {
//                 idx = low;
//                 ans = arr[low];
//             }
//             low = mid + 1;
//         }
//         else
//         {
//             if (arr[mid] < ans)
//             {
//                 idx = mid;
//                 ans = arr[mid];
//             }
//             high = mid - 1;
//         }
//     }
//     return idx;
// }

int Solution(vector<int> &arr, int n)
{
    int low = 0, high = n - 1;

    while (low < high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] > arr[high])
            low = mid + 1;
        else
            high = mid;
    }

    return low;
}

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
