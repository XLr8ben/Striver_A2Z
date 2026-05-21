#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <math.h>
using namespace std;

// Brute force Approach 1
// Algorithm
// The problem states that every number in the array appears exactly twice, except for one number that appears only once. If we traverse through the 
// array and compare each element with its neighbors, we can detect the unique number. If an element is not equal to its left and right neighbors, then it must be the single number.

// We handle corner cases:
// If it’s the first element, just compare it with the next.
// If it’s the last element, just compare it with the previous.
// Approach
// Find the total size of the array.
// If the size is equal to one, return the only element.
// Traverse the array from start to end.
// If the current element is the first one, compare it with the next. If they are different, return it.
// If the current element is the last one, compare it with the previous. If they are different, return it.
// Otherwise, compare the current element with both previous and next. If it is different from both, return it.
// If no such element is found during traversal, return an invalid marker (though by problem guarantee, one will always exist).

// Time Complexity: O(N), N = size of the given array.We are traversing the entire array.
// Space Complexity: O(1) as we are not using any extra space.

// int Solution(vector<int>& arr, int n){
//     if(n==1) return arr[0];

//     if(arr[0] != arr[1]) return arr[0];
//     if(arr[n-1] != arr[n-2]) return arr[n-1];

//     for(int i=1;i<n-1;i++){
//         if(arr[i] != arr[i-1] && arr[i] != arr[i+1]) return arr[i];
//     }

//     return -1;
// }

// Brute Approach 2
// Algorithm
// We can simplify the above approach using the XOR operation. We need to remember 2 important properties of XOR:
// a ^ a = 0, XOR of two same numbers results in 0.
// a ^ 0 = a, XOR of a number with 0 always results in that number.
// Now, if we XOR all the array elements, all the duplicates will result in 0 and we will be left with a single element.
// We will declare an ‘ans’ variable initialized with 0.
// We will traverse the array and XOR each element with the variable ‘ans’.
// After complete traversal, the ‘ans’ variable will store the single element and we will return it.

// Time Complexity: O(N), N = size of the given array.We are traversing the entire array.
// Space Complexity: O(1) as we are not using any extra space.

// int Solution(vector<int>& arr, int n){
//     int ans=0;

//     for(int i=0;i<n;i++){
//         ans ^= arr[i];
//     }
//     return ans;
// }

// Optimal Approach
// Algorithm
// The array is sorted, and all elements except one appear exactly twice. If we observe carefully, every pair starts at even index and ends at odd index when the array is still balanced (i.e., before the unique element is encountered).

// But once the unique element is inserted, this pairing pattern breaks and the shift happens after that unique element. So we can use this pattern to cut the search space in half using binary search:
// If the pairing is proper (i.e., arr[mid] == arr[mid ^ 1]), then the unique (non-duplicate) element lies in the right half.
// If the pairing breaks (i.e., arr[mid] != arr[mid ^ 1]), then the unique element lies in the left half.
// This leads us to an O(log n) solution by binary eliminating half of the array every step.
// Check if the array has only one element, return that element.
// Check if the first element is not equal to the second return the first.
// Check if the last element is not equal to the second last return the last.
// Set two pointers: low = 1, high = n - 2 (excluding boundary elements).
// Run a loop while low ≤ high:
// Find mid = (low + high) / 2.
// If arr[mid] ≠ arr[mid - 1] and arr[mid] ≠ arr[mid + 1], return arr[mid].
// Check if mid is part of a correct pair:
// If mid is even and arr[mid] == arr[mid + 1], or
// If mid is odd and arr[mid] == arr[mid - 1],
// Then the unique element lies to the right, so move low = mid + 1.
// Otherwise, move high = mid - 1.
// If no unique element is found (theoretically unreachable), return -1.

// Time Complexity: O(logN), N = size of the given array ,as we are basically using the Binary Search algorithm.
// Space Complexity: O(1) as we are not using any extra space.

int Solution(vector<int>& arr, int n){
    if(n==1) return arr[0];

    if(arr[0] != arr[1]) return arr[0];
    if(arr[n-1] != arr[n-2]) return arr[n-1];

    int low = 1, high = n-2;

    while(low<=high){
        int mid = low + (high - low) / 2;

        if(arr[mid] != arr[mid+1] && arr[mid] != arr[mid-1]) return arr[mid];

        if((mid%2==1 && arr[mid] == arr[mid-1]) ||
           (mid%2==0 && arr[mid] == arr[mid+1])){
            low = mid + 1;
        }else{
            high = mid -1;
        }
    }
    return -1;

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
