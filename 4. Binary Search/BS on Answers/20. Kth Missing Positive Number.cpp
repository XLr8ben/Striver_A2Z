#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <math.h>
#include <algorithm>
#include <unordered_map>
using namespace std;

// Brute Force Approach
// Algorithm
// We will use a loop to traverse the array.
// Inside the loop,
// If arr[i] <= k: we will simply increase the value of k by 1.
// Otherwise, we will break out of the loop.
// Finally, we will return the value of k.

// Time Complexity: O(N), where N = size of the given array.
// Space Complexity: O(1), no extra space used.

// int Solution(vector<int>& arr, int n, int k){
    
//     for(int i=0;i<n;i++){
//         if(arr[i]<=k) k++;
//         else break;
//     }
//     return k;
// }

// Optimal Approach
// Algorithm
// We cannot apply binary search on the answer space here as we cannot assure which missing number has the possibility of being the kth missing number. That is why, we will do something different here.
// We will try to find the closest neighbors (i.e. Present in the array) for the kth missing number by counting the number of missing numbers for each element in the given array.

// Algorithm
// Start by setting two markers: one at the beginning and one at the end of the list.
// Keep checking the middle position between the two markers by taking their average.
// Count how many numbers are missing up to that middle position by subtracting the expected number from the actual number found at that point.
// If the number of missing values is less than the desired position, move your focus to the right side of the list by shifting the beginning marker ahead.
// If not, move your focus to the left side by shifting the end marker backward.
// Once you've narrowed down the search and exited the loop, return the final answer by adding the desired position to the last marker you checked (plus one).

// Time Complexity: O(logn), used for typical binary search
// Space Complexity: O(1), no extra space used

int Solution(vector<int>& arr, int n, int k){
    int low = 0, high = n-1;

    while(low<=high){
        int mid = low + (high - low) / 2;

        int missing = arr[mid] - (mid + 1);
        if(missing<k) low = mid + 1;
        else high = mid - 1;
    }
    return k + high - 1;
    //previously derived formula was arr[high] + more, 
    // where more = k - missing;
    // so using these equations we derived
    // arr[high] + more;
    // arr[high] + (k - missing);
    // arr[high] + (k - (arr[high] - (high - 1)));
    // k + high + 1; or k + low;
}

int main()
{
    int n;
    cin>>n;
    vector<int> arr(n);

    int k;
    cin>>k;

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    cout<<Solution(arr, n, k)<<endl;

    return 0;
}
