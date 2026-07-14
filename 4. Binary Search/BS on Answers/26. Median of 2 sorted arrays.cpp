#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

// Brute Force Approach
// Algorithm
// Approach
// First, merge both sorted arrays into a third array.
// Then find the median element(s) from the merged array.
// If total length is odd:
//      median = merged[n/2]
// Else:
//      median = (merged[n/2] + merged[n/2 - 1]) / 2.0
//
// Time Complexity: O(n+m)
// Space Complexity: O(n+m)

// double Solution(vector<int>& nums1, vector<int>& nums2){
//     vector<int> merged;

//     int i = 0, j = 0;

//     while(i < nums1.size() && j < nums2.size()){
//         if(nums1[i] <= nums2[j]) merged.push_back(nums1[i++]);
//         else merged.push_back(nums2[j++]);
//     }

//     while(i < nums1.size()){
//         merged.push_back(nums1[i++]);
//     }

//     while(j < nums2.size()){
//         merged.push_back(nums2[j++]);
//     }

//     int n = merged.size();

//     if(n % 2 == 1) return merged[n/2];

//     return (merged[n/2] + merged[n/2 - 1]) / 2.0;
// }


// ------------------------------------------------------------
// Better Approach
// ------------------------------------------------------------

// Intuition
// We do not actually need the merged array.
// While performing the merge process,
// we only keep track of the middle element(s).
//
// Algorithm
// Find the positions of median elements.
// Traverse both arrays using merge-sort logic.
// Maintain a count of elements processed.
// Whenever count reaches median positions,
// store those elements.
// Finally calculate the median.
//
// Time Complexity: O(n+m)
// Space Complexity: O(1)

//  double Solution(vector<int>& nums1, vector<int>& nums2){
//      int n1 = nums1.size();
//      int n2 = nums2.size();

//      int n = n1 + n2;

//      int ind1 = (n / 2) - 1;
//      int ind2 = n / 2;

//      int cnt = 0;

//      int ele1 = -1;
//      int ele2 = -1;

//      int i = 0;
//      int j = 0;

//      while(i < n1 && j < n2){
//          if(nums1[i]<nums2[j]){
//                 if(cnt == ind1) ele1 = nums1[i];
//                 if(cnt == ind2) ele2 = nums1[i];
//                 cnt++;
//                 i++;
//         }else{
//             if(cnt == ind1) ele1 = nums2[j];
//             if(cnt == ind2) ele2 = nums2[j];
//             cnt++;
//             j++;
//         }
//      }

//      while(i < n1){
//         if(cnt == ind1) ele1 = nums1[i];
//         if(cnt == ind2) ele2 = nums1[i];
//         cnt++;
//         i++;
//      }

//      while(j < n2){
//         if(cnt == ind1) ele1 = nums2[j];
//         if(cnt == ind2) ele2 = nums2[j];
//         cnt++;
//         j++;
//      }

//      if(n % 2 == 1)
//          return ele2;

//      return (ele1 + ele2) / 2.0;
//  }


//  ------------------------------------------------------------
//  Optimal Approach
//  ------------------------------------------------------------

// Intuition
// We use Binary Search on the smaller array.
//
// We partition both arrays such that:
//
// Left Part Size == Right Part Size
//
// and
//
// max(leftPart) <= min(rightPart)
//
// Once a valid partition is found:
//
// If total length is odd:
//      median = max(leftPart)
//
// Else:
//      median = (max(leftPart)+min(rightPart))/2
//
// Algorithm
// Always perform binary search on the smaller array.
// Compute partition positions in both arrays.
// Check if partition is valid.
//
// If l1 > r2:
//      move left
//
// Else if l2 > r1:
//      move right
//
// Else:
//      partition found
//      calculate median
//
// Time Complexity: O(log(min(n,m)))
// Space Complexity: O(1)

double Solution(vector<int>& nums1, vector<int>& nums2)
{
    int n1 = nums1.size();
    int n2 = nums2.size();

    int n = n1 + n2;

    // Ensure binary search on smaller array
    if(n1 > n2)
        return Solution(nums2, nums1);

    int low = 0;
    int high = n1;

    int left = (n1 + n2 + 1) / 2;

    while(low <= high)
    {
        int mid1 = (low + high) / 2;
        int mid2 = left - mid1;

        int l1 = INT_MIN, l2 = INT_MIN;
        int r1 = INT_MAX, r2 = INT_MAX; 

        if(mid1 < n1) r1 = nums1[mid1];
        if(mid2 < n2) r2 = nums2[mid2];
        if(mid1-1 >= 0) l1 = nums1[mid1-1];
        if(mid2-1 >= 0) l2 = nums2[mid2-1];

        if(l1<=r2 && l2<=r1){
            if(n%2 == 1) return max(l1, l2);
            return (max(l1, l2) + min(r1, r2)) / 2.0;
        }
        else if(l1 > r2) high = mid1 - 1;
        else low = mid1 + 1;
    }

    return 0.0;
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

    cout << Solution(nums1, nums2) << endl;

    return 0;
}