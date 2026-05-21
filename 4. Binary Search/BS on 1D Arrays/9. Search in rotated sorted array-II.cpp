#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <math.h>
using namespace std;

// Brute Force
// Algorithm
// We will traverse the array and check every element if it is equal to k. If we find any element, we will return True.
// Otherwise, we will return False.

// Time Complexity: O(N), N = size of the given array.
// Space Complexity: O(1), no extra space used.

// int Solution(vector<int>& arr, int n, int x){
//     for (int i = 0; i < n; i++){
//         if (arr[i] == x) return i;
//     }
    
//     return -1;
// }

// Optimised Approach
// Algorithm
// Intuition
// First, we identify the sorted half of the array.
// Once found, we determine if the target is located within this sorted half
// If not, we eliminate that half from further consideration.
// Conversely, if the target does exist in the sorted half, we eliminate the other half.
// We basically compare arr[mid] with arr[low] and arr[high] in the following way:
// If arr[low] <= arr[mid]: In this case, we identified that the left half is sorted.
// If arr[mid] <= arr[high]: In this case, we identified that the right half is sorted.


// Approach
// Place the 2 pointers i.e. low and high: Initially, we will place the pointers like this: low will point to the first index, and high will point to the last index.
// Calculate the ‘mid’: Now, inside a loop, we will calculate the value of ‘mid’ using the following formula: mid = (low+high) // 2 ( ‘//’ refers to integer division)
// Check if arr[mid] = target: If it is, return True.
// Check if arr[low] = arr[mid] = arr[high]: If this condition is satisfied, we will just increment the low pointer and decrement the high pointer by one step. We will not perform the later steps until this condition is no longer satisfied. So, we will continue to the next iteration from this step.
// Identify the sorted half, check where the target is located, and then eliminate one half accordingly:
// If arr[low] <= arr[mid]: This condition ensures that the left part is sorted.
// If arr[low] <= target && target <= arr[mid]: It signifies that the target is in this sorted half. So, we will eliminate the right half (high = mid-1).
// Otherwise, the target does not exist in the sorted half. So, we will eliminate this left half by doing low = mid+1.
// Otherwise, if the right half is sorted:
// If arr[mid] <= target && target <= arr[high]: It signifies that the target is in this sorted right half. So, we will eliminate the left half (low = mid+1).
// Otherwise, the target does not exist in this sorted half. So, we will eliminate this right half by doing high = mid-1.
// Once, the ‘mid’ points to the target, we will return True.
// This process will be inside a loop and the loop will continue until low crosses high. If no element is found, we will return False.

// Time Complexity: O(logN) for the best and average case. O(N/2) for the worst case. Here, N = size of the given array.
// Space Complexity: O(1), no extra space used


string Solution(vector<int>& arr, int n, int x){
    int low=0, high=n-1;

    while(low<=high){
        int mid = low + (high - low) / 2;

        if(arr[mid] == x) return "true";

        else if(arr[low] == arr[mid] && arr[mid] == arr[high]){
            low++;
            high--;
        }

        else if(arr[low] <= arr[mid]){
            if(arr[low] <= x && x < arr[mid]){
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }else{
            if(arr[mid] < x && x <= arr[high]){
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }
    }
    return "false";
}

int main()
{
    int n;
    cin>>n;
    vector<int> arr(n);

    int x;
    cin>>x;

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    cout<<Solution(arr, n, x)<<endl;

    return 0;
}
