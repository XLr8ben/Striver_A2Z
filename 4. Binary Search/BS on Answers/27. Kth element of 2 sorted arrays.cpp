#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

// ============================================================
// Kth Element of Two Sorted Arrays
// ============================================================


// ------------------------------------------------------------
// Brute Force Approach
// ------------------------------------------------------------

// Algorithm
// Approach
// First, merge both sorted arrays into a third array.
// After merging, simply return merged[k-1].
//
// Time Complexity: O(n+m)
// Space Complexity: O(n+m)

// int Solution(vector<int>& nums1, vector<int>& nums2, int k)
// {
//     vector<int> merged;

//     int i = 0;
//     int j = 0;

//     while(i < nums1.size() && j < nums2.size())
//     {
//         if(nums1[i] <= nums2[j])
//             merged.push_back(nums1[i++]);
//         else
//             merged.push_back(nums2[j++]);
//     }

//     while(i < nums1.size())
//     {
//         merged.push_back(nums1[i++]);
//     }

//     while(j < nums2.size())
//     {
//         merged.push_back(nums2[j++]);
//     }

//     return merged[k - 1];
// }



// ------------------------------------------------------------
// Better Approach
// ------------------------------------------------------------

// Intuition
// We do not actually need the merged array.
// While performing the merge process,
// we only keep track of the count.
//
// As soon as we reach the kth element,
// we return it directly.
//
// Time Complexity: O(k)
// Space Complexity: O(1)

// int Solution(vector<int>& nums1, vector<int>& nums2, int k)
// {
//     int n1 = nums1.size();
//     int n2 = nums2.size();

//     int i = 0;
//     int j = 0;

//     int cnt = 0;

//     while(i < n1 && j < n2)
//     {
//         int val;

//         if(nums1[i] <= nums2[j])
//             val = nums1[i++];
//         else
//             val = nums2[j++];

//         cnt++;

//         if(cnt == k)
//             return val;
//     }

//     while(i < n1)
//     {
//         cnt++;

//         if(cnt == k)
//             return nums1[i];

//         i++;
//     }

//     while(j < n2)
//     {
//         cnt++;

//         if(cnt == k)
//             return nums2[j];

//         j++;
//     }

//     return -1;
// }



// ------------------------------------------------------------
// Optimal Approach
// ------------------------------------------------------------

// Intuition
// This approach is very similar to
// Median of Two Sorted Arrays.
//
// We partition both arrays such that:
//
// Number of elements on Left Side = k
//
// If:
//
//      l1 <= r2
//      l2 <= r1
//
// Then the partition is valid.
//
// Since left side contains exactly k elements,
// kth element will be:
//
//      max(l1, l2)
//
// Algorithm
//
// Always apply Binary Search on the smaller array.
//
// Choose:
//      mid1 elements from nums1
//      mid2 = k - mid1 elements from nums2
//
// Check whether partition is valid.
//
// If l1 > r2:
//      move left
//
// Else if l2 > r1:
//      move right
//
// Else:
//      valid partition found
//      answer = max(l1, l2)
//
// Time Complexity: O(log(min(n,m)))
// Space Complexity: O(1)

int Solution(vector<int>& nums1, vector<int>& nums2, int k)
{
    int n1 = nums1.size();
    int n2 = nums2.size();

    // Always binary search on smaller array
    if(n1 > n2)
        return Solution(nums2, nums1, k);

    // Search space for partition in nums1
    int low = max(0, k - n2);
    int high = min(k, n1);

    while(low <= high)
    {
        int mid1 = (low + high) / 2;
        int mid2 = k - mid1;

        int l1 = INT_MIN;
        int l2 = INT_MIN;
        int r1 = INT_MAX;
        int r2 = INT_MAX;

        if(mid1 < n1) r1 = nums1[mid1];
        if(mid2 < n2) r2 = nums2[mid2];

        if(mid1 - 1 >= 0) l1 = nums1[mid1 - 1];
        if(mid2 - 1 >= 0) l2 = nums2[mid2 - 1];

        if(l1 <= r2 && l2 <= r1)
        {
            return max(l1, l2);
        }
        else if(l1 > r2)
        {
            high = mid1 - 1;
        }
        else
        {
            low = mid1 + 1;
        }
    }

    return -1;
}


int main()
{
    int n1, n2;
    cin >> n1 >> n2;

    vector<int> nums1(n1);
    vector<int> nums2(n2);

    for(int i = 0; i < n1; i++)
    {
        cin >> nums1[i];
    }

    for(int i = 0; i < n2; i++)
    {
        cin >> nums2[i];
    }

    int k;
    cin >> k;

    cout << Solution(nums1, nums2, k) << endl;

    return 0;
}