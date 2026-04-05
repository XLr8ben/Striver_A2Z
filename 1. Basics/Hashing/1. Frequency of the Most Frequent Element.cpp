#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <math.h>
#include <algorithm>
using namespace std;

// Brute Force Approach

// For every element:
// Try making all previous elements equal to it
// Compute cost manually

// Time: O(n²)
// Space Complexity: O(1)

// int maxFrequency(vector<int>& nums, int k) {
//     sort(nums.begin(), nums.end());
//     int n = nums.size();
//     int ans = 1;

//     for (int i = 0; i < n; i++) {
//         long long sum = 0;
//         for (int j = i; j >= 0; j--) {
//             sum += nums[j];
//             int window = i - j + 1;

//             if ((long long)nums[i] * window - sum <= k) {
//                 ans = max(ans, window);
//             } else {
//                 break;
//             }
//         }
//     }
//     return ans;
// }

// Better Approach (Prefix Sum)

// Avoid recomputing sum every time:
// Use prefix sum array
// Get range sum in O(1)

// Time: O(n²) (but faster than brute in practice)
// Space: O(n)

// int maxFrequency(vector<int>& nums, int k) {
//     sort(nums.begin(), nums.end());
//     int n = nums.size();

//     vector<long long> prefix(n);
//     prefix[0] = nums[0];

//     for (int i = 1; i < n; i++)
//         prefix[i] = prefix[i-1] + nums[i];

//     int ans = 1;

//     for (int i = 0; i < n; i++) {
//         for (int j = i; j >= 0; j--) {
//             long long sum = prefix[i] - (j > 0 ? prefix[j-1] : 0);
//             int window = i - j + 1;

//             if ((long long)nums[i] * window - sum <= k) {
//                 ans = max(ans, window);
//             } else {
//                 break;
//             }
//         }
//     }
//     return ans;
// }

// Optimal Approach (Sliding Window)

// Sort array
// Maintain window
// Expand r, shrink l when invalid

// Time: O(n log n) (sorting)
// Sliding window: O(n)

int maxFrequency(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());

    long long l = 0, currSum = 0, ans = 0;

    for (int r = 0; r < nums.size(); r++) {

        currSum += nums[r];

        while ((long long)nums[r] * (r - l + 1) - currSum > k) {
            currSum -= nums[l];
            l++;
        }

        ans = max(ans, (long long)(r - l + 1));
    }

    return ans;
}


int main()
{
    int n;
    cin>>n;
    vector<int> arr(n);

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    cout<<maxFrequency(arr, n)<<endl;

    return 0;
}
