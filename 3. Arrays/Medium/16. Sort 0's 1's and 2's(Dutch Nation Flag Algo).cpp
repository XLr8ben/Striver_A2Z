#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <math.h>
#include <algorithm>

using namespace std;

//Brute/Better Approach

//brute force approach and better approach are same with same TC SC
//Initialize three counters to count the frequency of 0s, 1s, and 2s
// Loop through the array once and count each number
// In the second loop, fill the array based on the frequency of each number: first 0s, then 1s, then 2s

// Time Complexity: O(n),We traverse the array twice: once to count, once to overwrite. Each operation is O(n).
// Space Complexity: O(1), We use only a constant number of counters regardless of the input size. No extra array is used.

// void Solution(vector<int>& arr, int n){
//     int zero=0, one=0, two=0;

//     for(int ele: arr){
//         if(ele==0) zero++;
//         else if(ele==1) one++;
//         else two++;
//     }

//     int idx=0;

//     while(zero--){
//         arr[idx++] = 0;
//     }
//     while(one--){
//         arr[idx++] = 1;
//     }
//     while(two--){
//         arr[idx++] = 2;
//     }

// }

//optimal approach
// This approach is a direct implementation of the Dutch National Flag algorithm.

// [ 0s | 1s | UNKNOWN | 2s ]
//   ↑     ↑       ↑      ↑
//  low   mid             high

// We divide the array into three partitions using three pointers – low, mid, and high.
// From 0 to low-1, we’ll keep only 0s
// From low to mid-1, only 1s
// From high+1 to n-1, only 2
// The range from mid to high is the unsorted zone we’re scanning and fixing. At each step:
// If arr[mid] == 0, it belongs to the left section → swap with low, move both low and mid.
// If arr[mid] == 1, it’s already in the middle section → just move mid.
// If arr[mid] == 2, it belongs to the right section → swap with high, only move high.
// When you swap with high, you don’t move mid because the incoming value might still be 0 or 2 which needs processing.This ensures we sort the array in one single pass without using extra space.
// Start with three pointers at the beginning, middle, and end of the array.
// Iterate while the middle pointer is less than or equal to the end pointer.
// If the current element belongs to the front section:
// Swap it with the element at the front boundary.
// Move both front and middle boundaries forward.
// If the current element belongs to the middle section:
// Move the middle boundary forward.
// If the current element belongs to the end section:
// Swap it with the element at the end boundary.
// Move the end boundary backward.
// Repeat until all elements are in their correct zones.

// Time Complexity: O(n) The array is traversed only once using the `mid` pointer. Each element is checked at most once, and swaps are done in constant time.
// Space Complexity: O(1) Only a few integer pointers (`low`, `mid`, `high`) are used. Sorting is done in-place, requiring no additional space.

void Solution(vector<int>& arr, int n){
    int low=0, mid=0, high=n-1;

    while(mid<=high){
        if(arr[mid]==0){
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        }
        else if(arr[mid]==1) mid++;
        else{
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}

int main()
{
    int n;
    cin>>n;
    vector<int> arr(n);

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    Solution(arr, n);

    for(int ele: arr){
        cout<<ele<<' ';
    }

    return 0;
}
